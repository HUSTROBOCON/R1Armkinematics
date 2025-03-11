#include "ForwardkinematicsT/FT_method.hpp"

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
    static Eigen::Vector3d qpre = qnow;
    static Eigen::Vector3d dqpre = dqnow;

    Eigen::Vector3d nowPos = forwardKinematics(qnow);
    Eigen::Vector2d nowPos2d(nowPos(0), nowPos(2));
    double nowyaw = qnow(0) + qnow(1) + qnow(2);
    double nowyawprint = nowyaw * 180 / pi;
    RCLCPP_INFO(this->get_logger(), "nowyaw: %f", nowyawprint);
    double nowlineyaw = atan2(nowPos(2) - init_pos(2), nowPos(0) - init_pos(0));
    RCLCPP_INFO(this->get_logger(), "nowlineyaw: %f", nowlineyaw * 180 / pi);
    RCLCPP_INFO(this->get_logger(), "nowpos: %f, %f, %f" , nowPos(0), nowPos(1), nowPos(2));

    // 计算路径跟踪线速度
    int closestPointId = findClosestPoint(nowPos2d, poscircle, 200 ,nowyaw ,yawcircle);
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
    // RCLCPP_INFO(this->get_logger(), "finalcombinevel: %f, %f", finalcombinevel(0), finalcombinevel(1));

    // 计算路径跟踪角速度
    double erryaw = yawcircle(closestPointId) - nowyaw;
    PID yawPid(this->get_parameter("errwristkp").as_double(), this->get_parameter("errwristki").as_double(), this->get_parameter("errwristkd").as_double(), this->get_parameter("errwristoutlimit").as_double(), this->get_parameter("errwristinterlimit").as_double(), 0.001);
    double errwristoutput = yawPid.PIDcalculate(nomalizeangle(erryaw));
    double finalwrist = errwristoutput + wristcircle(closestPointId);

    Eigen::Vector3d endTargetvel(finalcombinevel(0), 0 ,finalcombinevel(1));

    Eigen::Vector3d jointvel = MycomputeEndEffectorVelocity(endTargetvel(0), endTargetvel(2) , finalwrist, qnow);

    PID accPid(this->get_parameter("errposkp").as_double(), this->get_parameter("errposki").as_double(), this->get_parameter("errposkd").as_double(), this->get_parameter("errposoutlimit").as_double(), this->get_parameter("errposinterlimit").as_double(), 0.001);
    Eigen::Vector3d velAcc = accPid.PIDcalculate((jointvel - dqnow).norm()) * (jointvel - dqnow).normalized() ;

    Eigen::Vector3d tau ;
    // 方法一
    // if (closestPointId >= 199 || count ==1)
    // {   
    //     RCLCPP_INFO(this->get_logger(), "count: %d", count);
    //     // if ((calculateDistance(nowPos2d ,Eigen::Vector2d(poscircle(180, 0) ,poscircle(180, 1)) ,nowyaw ,yawcircle(180))) < 0.5)
    //     if ((nowyaw - this->get_parameter("shootangle").as_double()) * 180 / pi < 1)
    //     {
    //         if (count == 0)
    //         {
    //             qpre = qnow;
    //         }
    //         count = 1; 
    //     }
    //     if (count == 1)
    //     {tau = arm_kp * (qpre - qnow) - arm_kd *  dqnow + zwzmcgcal(qnow, Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0));}
        
    // }
    // else
    // {   
    //     qpre = qnow;
        tau = zwzmcgcal(qnow, dqnow, velAcc);    
    // }
 
    RCLCPP_INFO(this->get_logger(), "tau: %f, %f, %f", tau(0), tau(1), tau(2));
    return tau;
}

// 定点力控测试
Eigen::Vector3d FT_method::zwzSinglepointForcecal(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow)
{
    //测试位置
    Eigen::Vector2d testpoint(init_pos(0),  init_pos(2));
    Eigen::Vector2d testvel(0, 0);

    //当前位置
    Eigen::Vector3d nowPos = forwardKinematics(qnow);
    Eigen::Vector2d nowPos2d(nowPos(0), nowPos(2));
    double nowyaw = qnow(0) + qnow(1) + qnow(2);

    Eigen::Vector2d foot = testvel.normalized() * (nowPos2d - testpoint).dot(testvel.normalized()) 
                            + testpoint;

    Eigen::Vector2d err = foot - nowPos2d;
    PID velPid(this->get_parameter("errvelkp").as_double(), this->get_parameter("errvelki").as_double(), this->get_parameter("errvelkd").as_double(), this->get_parameter("errveloutlimit").as_double(), this->get_parameter("errvelinterlimit").as_double(), 0.001);
    double erroutput = velPid.PIDcalculate(err.norm());

    // 计算速度;
    Eigen::Vector2d errcorrectVel = err.normalized() * erroutput;
    Eigen::Vector2d finalcombinevel = errcorrectVel;

    Eigen::Vector3d endTargetvel(finalcombinevel(0), 0 ,finalcombinevel(1));
    
    // 计算路径跟踪角速度
    double erryaw = (initial_q(0) +initial_q(1) +initial_q(2)) - nowyaw;
    PID yawPid(this->get_parameter("errwristkp").as_double(), this->get_parameter("errwristki").as_double(), this->get_parameter("errwristkd").as_double(), this->get_parameter("errwristoutlimit").as_double(), this->get_parameter("errwristinterlimit").as_double(), 0.001);
    double errwristoutput = yawPid.PIDcalculate(nomalizeangle(erryaw));
    double finalwrist = errwristoutput;

    Eigen::Vector3d jointvel = MycomputeEndEffectorVelocity(endTargetvel(0), endTargetvel(2) , finalwrist, qnow);

    PID accPid(this->get_parameter("errposkp").as_double(), this->get_parameter("errposki").as_double(), this->get_parameter("errposkd").as_double(), this->get_parameter("errposoutlimit").as_double(), this->get_parameter("errposinterlimit").as_double(), 0.001);
    Eigen::Vector3d velAcc = accPid.PIDcalculate((jointvel - dqnow).norm()) * (jointvel - dqnow).normalized() ;

    Eigen::Vector3d tau = zwzmcgcal(qnow, dqnow, velAcc);
    RCLCPP_INFO(this->get_logger(), "tau: %f, %f, %f", tau(0), tau(1), tau(2));
    RCLCPP_INFO(this->get_logger(), "nowPos: %f, %f", nowPos(0), nowPos(2));
    return tau;
}