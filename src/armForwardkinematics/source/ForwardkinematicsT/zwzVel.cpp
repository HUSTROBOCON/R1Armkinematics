#include "ForwardkinematicsT/FT_method.hpp"

Eigen:: Vector3d FT_method::zwzVelcal(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow)
{
    int count = 0;
    int id = 0;
    
    Eigen::Vector3d endTargetvel(0, 0 ,0.2);
    Eigen::Vector3d jointvel;

    jointvel = MycomputeEndEffectorVelocity(endTargetvel(0), endTargetvel(2) , 0, qnow);
    return jointvel;
} 

// 实现规划路径
Eigen::MatrixXd FT_method::pathPlan( int pathnum)
{
    Eigen::MatrixXd pathPoints(pathnum*4, 3);
    for (int i = 0; i < pathnum*4; i++)
    {
        double R = 0.5;
        pathPoints(i, 0) = init_pos(0) + R * cos(-pi + 2 * pi * i / pathnum) + R;
        pathPoints(i, 1) = 0;
        pathPoints(i, 2) = init_pos(2) + R * sin(-pi + 2 * pi * i / pathnum);
    }
    return pathPoints;
}

// 速度规划
Eigen::MatrixXd FT_method::velPlan( int pathnum)
{
    Eigen::MatrixXd velPoints(pathnum*4 , 2);
    double R = 0.8;
    double  v_cir = this->get_parameter("Vmax").as_double();
   for (int i = 0; i < pathnum*4; i++)
    {
        velPoints(i ,0) = -v_cir * sin(-pi + 2 * pi * i / pathnum);
        velPoints(i ,1) =  v_cir * cos(-pi + 2 * pi * i / pathnum);
    }
    return velPoints;

}

// 末端角度规划
Eigen::VectorXd FT_method::yawPlan( int pathnum)
{
    Eigen::VectorXd yawPoints(pathnum*4);
    for (int i = 0; i < pathnum*4; i++)
    {
        yawPoints(i) = -pi + 2 * pi * i / pathnum;
        yawPoints(i) = nomalizeangle(yawPoints(i));
    }
    return yawPoints;   
}

// 末端角速度规划
Eigen::VectorXd FT_method::wristPlan( int pathnum)
{
    Eigen::VectorXd wristPoints(pathnum*4);
    for (int i = 0; i < pathnum*4; i++)
    {
        wristPoints(i) = this->get_parameter("Vmax").as_double() / 0.8;
    }
    return wristPoints;   
}

Eigen::Vector3d FT_method::zwzVeltaucal(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow)
{

    static int count = 0;

    Eigen::Vector3d nowPos = forwardKinematics(qnow);
    Eigen::Vector2d nowPos2d(nowPos(0), nowPos(2));
    double nowyaw = qnow(0) + qnow(1) + qnow(2);
    RCLCPP_INFO(this->get_logger(), "nowyaw: %f", nowyaw);

    // 计算路径跟踪线速度
    int closestPointId = findClosestPoint(nowPos2d, poscircle, 800 ,nowyaw ,yawcircle);
    RCLCPP_INFO(this->get_logger(), "closestPointId: %d", closestPointId);

    // 计算垂足
    Eigen::Vector2d closestPoint(poscircle(closestPointId, 0), poscircle(closestPointId, 2));
    Eigen::Vector2d foot = velcircle.row(closestPointId).transpose().normalized() * (nowPos2d - closestPoint).dot(velcircle.row(closestPointId).transpose().normalized()) 
                            + closestPoint;

    // 计算垂足到当前位置的误差
    Eigen::Vector2d err = foot - nowPos2d;
    PID velPid(this->get_parameter("errvelkp").as_double(), this->get_parameter("errvelki").as_double(), this->get_parameter("errvelkd").as_double(), this->get_parameter("errveloutlimit").as_double(), this->get_parameter("errvelinterlimit").as_double(), 0.001);
    double erroutput = velPid.PIDcalculate(err.norm());
    
    // 计算速度;
    Eigen::Vector2d errcorrectVel = err.normalized() * erroutput;
    Eigen::Vector2d finalcombinevel = velcircle.row(closestPointId).transpose() + errcorrectVel;
    RCLCPP_INFO(this->get_logger(), "finalcombinevel: %f, %f", finalcombinevel(0), finalcombinevel(1));

    // 计算路径跟踪角速度
    double erryaw = yawcircle(closestPointId) - nowyaw;
    PID yawPid(this->get_parameter("errwristkp").as_double(), this->get_parameter("errwristki").as_double(), this->get_parameter("errwristkd").as_double(), this->get_parameter("errwristoutlimit").as_double(), this->get_parameter("errwristinterlimit").as_double(), 0.001);
    double errwristoutput = yawPid.PIDcalculate(nomalizeangle(erryaw));
    double finalwrist = errwristoutput + wristcircle(closestPointId);
    RCLCPP_INFO(this->get_logger(), "finalwrist: %f", finalwrist);

    Eigen::Vector3d endTargetvel(finalcombinevel(0), 0 ,finalcombinevel(1));

    Eigen::Vector3d jointvel = MycomputeEndEffectorVelocity(endTargetvel(0), endTargetvel(2) , finalwrist, qnow);

    PID accPid(this->get_parameter("errposkp").as_double(), this->get_parameter("errposki").as_double(), this->get_parameter("errposkd").as_double(), this->get_parameter("errposoutlimit").as_double(), this->get_parameter("errposinterlimit").as_double(), 0.001);
    Eigen::Vector3d velAcc = accPid.PIDcalculate((jointvel - dqnow).norm())*(jointvel - dqnow).normalized() ;

    Eigen::Vector3d tau ;
    // 方法一
    tau = zwzmcgcal(qnow, dqnow, velAcc);
    // 方法二
    // tau = generateM(qnow) * velAcc + generateC(qnow, dqnow) + generateG(qnow);

    RCLCPP_INFO(this->get_logger(), "tau: %f, %f, %f", tau(0), tau(1), tau(2));

    Eigen::VectorXd velnow = computeJacobian(qnow) * dqnow;
    Eigen::Vector3d velnow3(velnow(0), velnow(1), velnow(2));
    Eigen::Vector3d velerr = endTargetvel - velnow3;

    if(count < 1000)
    {RCLCPP_INFO(this->get_logger(), "vel: %f, %f",velnow3.norm(), endTargetvel.norm());}

    count = count + 1;
    return tau;
}