#include <cmath>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <mit_msgs/msg/detail/mit_joint_commands__struct.hpp>
#include <mit_msgs/msg/detail/mit_low_state__struct.hpp>
#include <sensor_msgs/msg/detail/joint_state__struct.hpp>
#include <sensor_msgs/msg/detail/imu__struct.hpp>
#include <sensor_msgs/msg/detail/joy__struct.hpp>
#include "std_msgs/msg/header.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "ForwardkinematicsT/FT_method.hpp"
#include "rclcpp/rclcpp.hpp"


                                                                                                                             
double FT_method:: nomalozeangle(double angle)
{
    while (angle > M_PI)
    {
        angle -= 2 * M_PI;
    }
    while (angle < -M_PI)
    {
        angle += 2 * M_PI;
    }
    return angle;
}

Eigen::Matrix3d FT_method:: generateM(Eigen::Vector3d q_0) {

    // 提取关节角度
    double q1 = q_0(0);
    double q2 = q_0(1);
    double q3 = q_0(2);

    // 定义 M 矩阵的各个元素
    double M11 = a1 + a2 + a4 + 2 * a3 * cos(q2) + 2 * a5 * cos(q2 + q3) + 2 * a6 * cos(q3);
    double M12 = a2 + a4 + a3 * cos(q2) + a5 * cos(q2 + q3) + 2 * a6 * cos(q3);
    double M13 = a4 + a5 * cos(q2 + q3) + a6 * cos(q3);

    double M21 = M12;
    double M22 = a2 + a4 + 2 * a6 * cos(q3);
    double M23 = a4 + a6 * cos(q3);

    double M31 = M13;
    double M32 = M23;
    double M33 = a4;

    // 构造 M 矩阵
    Eigen::Matrix3d M;
    M << M11, M12, M13,
            M21, M22, M23,
            M31, M32, M33;

    return M;
}

// 定义生成 C 矩阵的函数
Eigen::Vector3d FT_method:: generateC(Eigen::Vector3d q_0, Eigen::Vector3d dq_0){
    // 提取关节角度和角速度
    double q1 = q_0(0);
    double q2 = q_0(1);
    double q3 = q_0(2);

    double dq1 = dq_0(0);
    double dq2 = dq_0(1);
    double dq3 = dq_0(2);

    // 定义 C 矩阵的各个元素
    double C1 = -a3 * (2 * dq1 + dq2) * dq2 * sin(q2)
                      - a5 * (2 * dq1 + dq2 + dq3) * (dq2 + dq3) * sin(q2 + q3)
                      - a6 * (2 * dq1 + 2 * dq2 + dq3) * dq3 * sin(q3);

    double C2 = a3 * dq1 * dq1 * sin(q2)
                      + a5 * dq1 * dq1 * sin(q2 + q3)
                      - a6 * (2 * dq1 + 2 * dq2 + dq3) * dq3 * sin(q3);

    double C3 = a5 * dq1 * dq1 * sin(q2 + q3)
                      + a6 * (dq1 + dq2) * (dq1 + dq2) * sin(q3);

    // 构造 C 矩阵
    Eigen::Vector3d C;
    C << C1, C2, C3;

    return C;
}


// 定义生成 G 矩阵的函数
Eigen::Vector3d FT_method:: generateG(Eigen::Vector3d q_0) {
        // 提取关节角度
        double q1 = q_0(0);
        double q2 = q_0(1);
        double q3 = q_0(2);        

        // 定义 G 矩阵的各个元素
        double G1 = m3 * g * (L1 * cos(q1) + L2 * cos(q1 + q2) + Lc3 * cos(q1 + q2 + q3))
               + m2 * g * (L1 * cos(q1) + Lc2 * cos(q1 + q2))
               + m1 * g * (Lc1 * cos(q1));

        double G2 = m3 * g * (L2 * cos(q1 + q2) + Lc3 * cos(q1 + q2 + q3))
               + m2 * g * (Lc2 * cos(q1 + q2));

        double G3 = m3 * g * (Lc3 * cos(q1 + q2 + q3));

        // 构造 G 矩阵
        Eigen::Vector3d G;
        G << G1, G2, G3;

        return G;
    }

// 末端速度轨迹规划
MatrixNumd4 FT_method:: endTrajectory(float k)
{
    // 预期末端出手速度
    double vx = k*v_end;
    double vy = k*v_end;

    //预计总时长
    double t = 2*v_end/a; // 前半段加速，后半段减速
    RCLCPP_INFO(this->get_logger(),"here");
    // 定义位置和速度数组, 用于存储每个时刻的位置和速度
    Eigen::MatrixXd pos(int(1.5*num), 2);
    Eigen::MatrixXd vel(int(1.5*num), 2);

    // 给定抛物线轨迹
    for ( int i=0; i<num1; i++)
    {
        pos(i, 0) = x0 * i / num + 0.08;
        pos(i, 1) = b * pos(i, 0) - pos(i, 0) * pos(i, 0) ;
    };
    RCLCPP_INFO(this->get_logger(),"here");

    // 计算速度
    for ( int i=0; i<num1; i++)
    {
        double Angle = atan(b - 2 * pos(i, 0));
        double Vnorm;
        if (i < num)
        {
            Vnorm = sin((i * M_PI / 2)/ num ) * v_end;
        }
        else 
        {
            Vnorm = cos(((i - num)* M_PI / 2) / (num1 - num) ) * v_end;
        }
        vel(i, 0) = Vnorm * cos(Angle);
        vel(i, 1) = Vnorm * sin(Angle);
    }
    RCLCPP_INFO(this->get_logger(),"here");

    // 将位置和速度数组合并
    MatrixNumd4 result(3*num, 2);
    for (int i=0; i<600 ; i++)
    {
        result(i, 0) = pos(i, 0);
        result(i, 1) = pos(i, 1);
    }
    for (int i=600; i<1200; i++)
    {
        int i0 = i - 600;
        result(i, 0) = vel(i0, 0);
        result(i, 1) = vel(i0, 1);

        // 打印 i 和 vel
        //RCLCPP_INFO(this->get_logger(), "i: %d, vel: %f, %f", i, vel(i0, 0), vel(i0, 1));
    }
    RCLCPP_INFO(this->get_logger(),"here");
    return result;
}

// Eigen::Vector3d FT_method::computeEndEffectorPosition(double x, double y)
// {
//     Eigen::Vector3d target_q(x, 0, y);
//     // pino_inv(target_q(0), target_q(1), target_q(2));
//     tar
//     return target_q;
// }

Eigen::Vector3d FT_method::myinverseKinematics(double x ,double z ,int num)
{
    // 规定初值
    // 输出结果存储
    Eigen::Vector3d q;
    static double qLast = 0;
    if(num == 0)
    {
        qLast = 90*pi/180;
    }
    // 规定q(3) 从90 -> 0;
    double i0 = double(num)/50.0;
    // RCLCPP_INFO(this->get_logger(), "i0: %f", i0);
    double D_target23;
    double L23;
    double theta3;
    // q(2) = (90 - 90*powf32(i0 , 5))*pi/180;
        q(2) = (90)*pi/180;
    // RCLCPP_INFO(this->get_logger(), "q(2): %f", q(2));
    while(1)
    {  

    L23 = sqrt(L2*L2 + L3*L3 - 2*L2*L3*cos(pi- q(2)));
    
    theta3 = acos((L2*L2 + L23*L23 - L3*L3)/(2*L23*L2));
    D_target23 = sqrt(x*x + z*z);
    if ((D_target23 < L1 + L23)&&(L1 < D_target23 + L23)&&(L23 < D_target23 + L1))
    {
        // RCLCPP_INFO(this->get_logger(), "L23: %f", L23);
        //     RCLCPP_INFO(this->get_logger(), "theta3: %f", theta3);
        //             RCLCPP_INFO(this->get_logger(), "D_target23: %f", D_target23);
        break;
    }
    else
    {
        //std::cout << "超出工作空间" << std::endl;
        q(2) = q(2) - 0.001;
        if(q(2) < 0)
        {
            q(2) = 0;
            break;
        }
    }
    }
    // 解关节2位置
    q(0) =  - acos((L1*L1 + D_target23*D_target23 - L23*L23)/(2*L1*D_target23)) + atan2(z,x);
    q(1) =  pi - (acos((L1*L1 + L23*L23 - D_target23*D_target23)/(2*L1*L23)) + theta3);
    qLast = q(2);
    return q;
}

Eigen:: Vector3d FT_method::MycomputeEndEffectorVelocity(double dx, double dy , Eigen::Vector3d q)
{
    Eigen::MatrixXd Jt(6, 3);
    // pinocchio::computeJointJacobian(model, data, q, jointNumber, Jt);
    Eigen::Vector3d dq_out;
    dq_out = Eigen::VectorXd::Zero(3);    
    Eigen::VectorXd target_dq(6);
    // std::cout << "q: " << q << std::endl;
    Jt = computeJacobian(q);
    target_dq << dx, 0, dy, 0, 0, 0;
    // RCLCPP_INFO(this->get_logger(), "Jt: %f, %f, %f", Jt(0, 0), Jt(0, 1), Jt(0, 2));
    Eigen::MatrixXd Jt_pinv = Jt.completeOrthogonalDecomposition().pseudoInverse();
    // std::cout << "Jt_pinv: " <<std::endl;
    dq_out = Jt_pinv * target_dq;
    // std::cout << "dq_out: " << dq_out << std::endl;
   for (int i = 0; i < 3; i++)
    {
        if (dq_out(i) < -30)
        {
            dq_out(i) = -30;
        }
        if (dq_out(i) > 30)
        {
            dq_out(i) = 30;
        }
    }
    // std::cout << "dq_out: " << dq_out << std::endl;

    return dq_out;
} 

// 计算雅各比矩阵的函数定义
Eigen::MatrixXd FT_method::computeJacobian(Eigen::Vector3d &q)
{
    Eigen::MatrixXd J(6, 3); // 6行3列的雅各比矩阵

    double theta1 = q(0);
    double theta2 = q(1);
    double theta3 = q(2);

    // 位置部分
    J(0, 0) = -L1 * sin(theta1) - L2 * sin(theta1 + theta2) - L3 * sin(theta1 + theta2 + theta3);
    J(0, 1) = -L2 * sin(theta1 + theta2) - L3 * sin(theta1 + theta2 + theta3);
    J(0, 2) = -L3 * sin(theta1 + theta2 + theta3);

    J(2, 0) = L1 * cos(theta1) + L2 * cos(theta1 + theta2) + L3 * cos(theta1 + theta2 + theta3);
    J(2, 1) = L2 * cos(theta1 + theta2) + L3 * cos(theta1 + theta2 + theta3);
    J(2, 2) = L3 * cos(theta1 + theta2 + theta3);

    J(1, 0) = 0;
    J(1, 1) = 0;
    J(1, 2) = 0;

    // 姿态部分
    J(3, 0) = 0;
    J(3, 1) = 0;
    J(3, 2) = 0;

    J(4, 0) = 1;
    J(4, 1) = 1;
    J(4, 2) = 1;

    J(5, 0) = 0;
    J(5, 1) = 0;
    J(5, 2) = 0;

    return J;
}

// 计算雅各比矩阵导数的函数定义
Eigen::MatrixXd FT_method::computeJacobianDerivative(const Eigen::VectorXd &q ,const Eigen::VectorXd &dq)
{
    Eigen ::MatrixXd dJ(6, 3);

    dJ(0, 0) = -L1 * cos(q(0))*dq(0) - L2 * cos(q(0) + q(1)) * (dq(0) + dq(1)) - L3 * cos(q(0) + q(1) + q(2)) * (dq(0) + dq(1) + dq(2));
    dJ(0, 1) = -L2 * cos(q(0) + q(1)) * (dq(0) + dq(1)) - L3 * cos(q(0) + q(1) + q(2)) * (dq(0) + dq(1) + dq(2));
    dJ(0, 2) = -L3 * cos(q(0) + q(1) + q(2)) * (dq(0) + dq(1) + dq(2));

    dJ(2, 0) = - L1 * sin(q(0)) * dq(0) - L2 * sin(q(0) + q(1)) * (dq(0) + dq(1)) - L3 * sin(q(0) + q(1) + q(2)) * (dq(0) + dq(1) + dq(2));
    dJ(2, 1) = - L2 * sin(q(0) + q(1)) * (dq(0) + dq(1)) - L3 * sin(q(0) + q(1) + q(2)) * (dq(0) + dq(1) + dq(2));
    dJ(2, 2) = - L3 * sin(q(0) + q(1) + q(2)) * (dq(0) + dq(1) + dq(2));

    dJ(1, 0) = 0;
    dJ(1, 1) = 0;
    dJ(1, 2) = 0;

    dJ(3, 0) = 0;
    dJ(3, 1) = 0;
    dJ(3, 2) = 0;

    dJ(4, 0) = 1;
    dJ(4, 1) = 1;
    dJ(4, 2) = 1;

    dJ(5, 0) = 0;
    dJ(5, 1) = 0;
    dJ(5, 2) = 0;

    return dJ;
}

Eigen::Vector3d FT_method::computeJointAcceleration(const Eigen::Vector3d &ddx, const Eigen::Vector3d &dq ,Eigen ::Vector3d q ,double dw)
{

    Eigen::Vector3d dq6;
    dq6 << dq(0), dq(1), dq(2);
    Eigen::VectorXd ddx6 = Eigen::VectorXd::Zero(6);
    ddx6 << ddx(0), ddx(1), ddx(2), 0, dw, 0;
    // RCLCPP_INFO(this->get_logger(), "111");
    // 计算雅各比矩阵
    Eigen::MatrixXd Jt = computeJacobian(q);
    // RCLCPP_INFO(this->get_logger(), "222");
    // 计算雅各比矩阵的导数
    Eigen::MatrixXd dJ = computeJacobianDerivative(q ,dq);
    // RCLCPP_INFO(this->get_logger(), "333");
    // 计算关节加速度
    Eigen::VectorXd ddq6(6);
    ddq6 = Jt.completeOrthogonalDecomposition().pseudoInverse() * (ddx6 - dJ * dq6);
    // RCLCPP_INFO(this->get_logger(), "444");
    Eigen::Vector3d ddq;
    ddq << ddq6(0), ddq6(1), ddq6(2);
    // RCLCPP_INFO(this->get_logger(), "ddq: %f, %f, %f", ddq(0), ddq(1), ddq(2));
    return ddq;                                                                                                                                                                                 
}


Eigen::Vector2d FT_method:: trace(const Eigen::Vector2d& nowPosition, const int closestPointId ,Eigen::Vector2d& nowVelocity)
{
    Eigen::Vector2d targetVelocity = velExp.row(closestPointId);
    // 暂时不限制速度

    Eigen::Vector2d closestPoint = posExp.row(closestPointId).cast<double>();
    // 计算从当前位置到 过最近点,方向为速度的直线 的向量
    // 计算垂足    // qExpI << posExp(i , 0), posExp(i , 1), posExp(i , 2);

    Eigen::Vector2d footPoint = targetVelocity.normalized() * 
                                ((nowPosition - closestPoint).dot(targetVelocity.normalized()))
                                + closestPoint;
    
    // 计算垂直速度方向的距离误差向量
    Eigen::Vector2d errorVerticalPos = footPoint - nowPosition;

    float errPosPidOutput = errorPosPid.PIDcalculate(errorVerticalPos.norm());

    // 计算速度
    Eigen::Vector2d ErrPosCorrectionV = errorVerticalPos.normalized() * errPosPidOutput;
    Eigen::Vector2d finalVelocity = targetVelocity + ErrPosCorrectionV;

    // 计算速度误差
    nowVelocity = finalVelocity - nowVelocity;
    float AccOutput = errorVelPid.PIDcalculate(nowVelocity.norm());

    // 计算加速度
    // Eigen::Vector2d AccOutputV = nowVelocity.normal();   // qExpI << posExp(i , 0), posExp(i , 1), posExp(i , 2);

    
}

// 计算两点之间的距离
double FT_method::calculateDistance(const Eigen::Vector2d& a, const Eigen::Vector2d& b) {
    return (a - b).norm();
}

// 寻找最近点
int FT_method:: findClosestPoint(const Eigen::Vector2d& nowPosition)
{
    float minDistance = std::numeric_limits<float>::infinity();

    int startId = lastClosestPointId - forwardSearchPointNum;
    int endId = lastClosestPointId + backwardSearchPointNum;
    // 众所周知，程序员从0数数
    startId = std::clamp(startId, 0, num0-1);
    endId = std::clamp(endId, 0, num0-1);

    int closestPointId = -1;

    for (int i = startId; i <= endId; i++) {
        float distance = calculateDistance(posExp.row(i).cast<double>(), nowPosition);
        if (distance < minDistance) {
            minDistance = distance;
            closestPointId = i;
        }
    }

    lastClosestPointId = closestPointId;

    // auto logger = rclcpp::get_logger("navigation_logger");
    // RCLCPP_INFO(logger, "closest point: x:%.3f, y:%.3f", 
    //     positionPoints[closestPointId](0), positionPoints[closestPointId](1));

    return closestPointId;
}

Eigen::Vector3d FT_method::
computeEfftor(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow)
{
    static int count = 0;
    static int i00 = 0;

    Eigen::Vector3d nowPosition = forwardKinematics(qnow);
    Eigen::VectorXd nowVelocity = computeJacobian(qnow) * dqnow;
    double noww = qnow(0) + qnow(1) + qnow(2);
    
    Eigen::Vector2d nowPosition2d;
    nowPosition2d << nowPosition(0), nowPosition(2);
    Eigen::Vector2d nowVelocity2d;
    nowVelocity2d << nowVelocity(0), nowVelocity(2);
    Eigen::Vector3d ExpPosition = forwardKinematics(TestposExp.row(i00).cast<double>());

    // // 到位检测
    // if ((nowPosition2d - Eigen::Vector2d(ExpPosition(0), ExpPosition(2))).norm() < 0.05)
    // {
    //     // 如果到位，切换到下一个点
    //     if (i00 < 49)
    //     {
    //         i00 = i00 + 1;            
    //     }
    // }

    i00 = 5;

    //==== 方法1 ====
    // // 预期加速度 
    Eigen ::Vector3d inputAcc;
    inputAcc << 0, 0, 0;
    Eigen::Vector3d qExpI ;
    
    qExpI << TestposExp(i00, 0), TestposExp(i00, 1), TestposExp(i00, 2);
    Eigen::Vector3d dqExpI ;
    // dqExpI << TestvelExp(i00, 0), TestvelExp(i00, 1), TestvelExp(i00, 2);
    dqExpI << 0, 0, 0;

    // 结合一下方法二
    PID errorOuterPosPid(this->get_parameter("errposkp").as_double(), this->get_parameter("errposki").as_double(), this->get_parameter("errposkd").as_double(), this->get_parameter("errposoutlimit").as_double(), this->get_parameter("errposinterlimit").as_double(), 0.001);
    PID errorOuterVelPid(this->get_parameter("errvelkp").as_double(), this->get_parameter("errvelki").as_double(), this->get_parameter("errvelkd").as_double(), this->get_parameter("errveloutlimit").as_double(), this->get_parameter("errvelinterlimit").as_double(), 0.001);
    PID errwirsPid(this->get_parameter("errwristkp").as_double(), this->get_parameter("errwristki").as_double(), this->get_parameter("errwristkd").as_double(), this->get_parameter("errwristoutlimit").as_double(), this->get_parameter("errwristinterlimit").as_double(), 0.001);
    double angelTest = atan2(0.2 - nowPosition(2), 0.8 - nowPosition(0));
    double dwzwz = errwirsPid.PIDcalculate(1.32 - noww); 
    double inputanorm = errorOuterPosPid.PIDcalculate((Eigen::Vector3d(0.2,0,0.8) - nowPosition).norm());
    double inputanormV = errorOuterVelPid.PIDcalculate((Eigen::Vector2d(inputanorm * cos(angelTest), inputanorm * sin(angelTest)) - nowVelocity2d).norm());
    // inputAcc << inputanormV * cos(angelTest), 0, inputanormV * sin(angelTest);
    // inputAcc = computeJointAcceleration(inputAcc, dqnow, qnow);
    inputAcc = computeJointAcceleration(Eigen::Vector3d(inputanormV * cos(angelTest), 0, inputanormV * sin(angelTest)), dqnow, qnow ,dwzwz);
    
    // inputAcc = inputAcc + arm_kp * (qExpI - qnow) + arm_kd * (dqExpI - dqnow);
    // RCLCPP_INFO(this->get_logger(), "inputAcc: %f, %f, %f", inputAcc(0), inputAcc(1), inputAcc(2));

    // 打印误差
    Eigen::Vector2d errorPos;
    errorPos(0) = forwardKinematics(qExpI)(0) - nowPosition(0);
    if (i00 < 49)
    {RCLCPP_INFO(this->get_logger(), "errorPos: %f, %f", errorPos(0), errorPos(1));}

    // Eigen::Matrix3d M = generateM(qnow);
    // Eigen::Vector3d C = generateC(qnow, dqnow);
    // Eigen::Vector3d G = generateG(qnow);

    //==== 方法2 ====
    //==============


    // 计算关节力矩
    // Eigen::Vector3d tau = M * inputAcc + C + G;
    Eigen::Vector3d tau = zwzmcgcal(qnow, dqnow, inputAcc);
    // RCLCPP_INFO(this->get_logger(), "tau: %f, %f, %f", tau(0), tau(1), tau(2));

    if (count < 50)
    {
        count = count + 1;
    }
    else
    {
        i00 = i00 + 1;
        count = 0;
    }

    if (i00 >= 49)
    {
        i00 = 49;
    }

    return tau;
}

// 回调函数
void FT_method::robotStatusCallback(mit_msgs::msg::MITLowState::SharedPtr msg) {

        Eigen::Vector3d robotStatusPos;
        Eigen::Vector3d robotStatusVel;

        robotStatusPos(0) = msg->joint_states.position[0];
        robotStatusPos(1) = msg->joint_states.position[1];
        robotStatusPos(2) = msg->joint_states.position[2];
        robotStatusVel(0) = msg->joint_states.velocity[0];
        robotStatusVel(1) = msg->joint_states.velocity[1];
        robotStatusVel(2) = msg->joint_states.velocity[2];
        
        
        if(robotStatusPos(0) == 0 && robotStatusPos(1) == 0 && robotStatusPos(2) == 0)
        {
            return;
        }
        
        //RCLCPP_INFO(this->get_logger(), "robotStatusPos: %f, %f, %f", robotStatusPos(0), robotStatusPos(1), robotStatusPos(2));

        Eigen::Vector3d effort = computeEfftor(robotStatusPos, robotStatusVel);

        // 计算当前位置
        mit_msgs::msg::MITJointCommands jointCommand;
        jointCommand.commands.resize(3);
        jointCommand.commands[0].pos = 0;//double(-90*pi/180);//effortPosVel(1, 0);
        jointCommand.commands[0].vel = 0;//effortPosVel(2, 0);
        jointCommand.commands[0].eff =  effort(0);
        jointCommand.commands[1].pos = 0;//effortPosVel(1, 1);
        jointCommand.commands[1].vel = 0;//effortPosVel(2, 1);
        jointCommand.commands[1].eff =  effort(1);
        jointCommand.commands[2].pos = 0;//effortPosVel(1, 2);
        jointCommand.commands[2].vel = 0;//effortPosVel(2, 2);
        jointCommand.commands[2].eff =  effort(2);
        jointCommandPub_->publish(jointCommand);

}

// 构造函数定义
FT_method ::FT_method() :
    rclcpp::Node("FT_method_node"), // 使用节点名称初始化基类
    errorPosPid(5, 0.5, 0, 1, 0.05, 0.01),
    errorVelPid(5, 0.5, 0.5, 1, 0.05, 0.01), 
    forwardSearchPointNum(5),
    backwardSearchPointNum(5)
{
    // 初始化参数
    this->declare_parameter<double>("kp");
    this->declare_parameter<double>("kd");
    this->declare_parameter<double>("joint1");
    this->declare_parameter<double>("joint2");
    this->declare_parameter<double>("joint3");
    this->declare_parameter<double>("b");
    this->declare_parameter<int>("Ntest");
    this->declare_parameter<double>("errposkp");
    this->declare_parameter<double>("errposki");
    this->declare_parameter<double>("errposkd");
    this->declare_parameter<double>("errvelkp");
    this->declare_parameter<double>("errvelki");
    this->declare_parameter<double>("errvelkd");
    this->declare_parameter<double>("errposoutlimit");
    this->declare_parameter<double>("errveloutlimit");
    this->declare_parameter<double>("errposinterlimit");
    this->declare_parameter<double>("errvelinterlimit");
    this->declare_parameter<double>("errwristkp");
    this->declare_parameter<double>("errwristki");
    this->declare_parameter<double>("errwristkd");
    this->declare_parameter<double>("errwristoutlimit");
    this->declare_parameter<double>("errwristinterlimit");
    this->declare_parameter<double>("Vmax");


    arm_kp = this->get_parameter("kp").as_double();
    arm_kd = this->get_parameter("kd").as_double();


    //===测试代码===
    Eigen::Vector3d initial_q(this->get_parameter("joint1").as_double(), this->get_parameter("joint2").as_double(), this->get_parameter("joint3").as_double());
    initial_q = initial_q * pi / 180;
    Eigen::Vector3d init_pos = forwardKinematics(initial_q);
    RCLCPP_INFO(this->get_logger(), "init_pos: %f, %f, %f", init_pos(0), init_pos(1), init_pos(2));

    double b = this->get_parameter("b").as_double();
    double x_end = (b-1)/2;
    double H = b * x_end - x_end * x_end;
    int Ntest = this->get_parameter("Ntest").as_int();
    TestposExp = Eigen::MatrixXd::Zero(Ntest, 3); // 用于存储测试轨迹
    TestvelExp = Eigen::MatrixXd::Zero(Ntest, 3); // 用于存储测试速度

    // Eigen::MatrixXd M(6,3);
    // M << 6, 0, 0,
    //      5, 6, 0,
    //      4, 5, 6,
    //      3, 4, 5,
    //      2, 3, 4,
    //      1, 2, 3; 
    // Eigen::MatrixXd MT(3,6);
    
    // MT = M.completeOrthogonalDecomposition().pseudoInverse();
    // RCLCPP_INFO(this->get_logger(), "MT: %f, %f, %f ,%f ,%f, %f", MT(0, 0), MT(0, 1), MT(0, 2), MT(0, 3), MT(0, 4), MT(0, 5));
    // RCLCPP_INFO(this->get_logger(), "MT: %f, %f, %f ,%f ,%f, %f", MT(1, 0), MT(1, 1), MT(1, 2), MT(1, 3), MT(1, 4), MT(1, 5));
    // RCLCPP_INFO(this->get_logger(), "MT: %f, %f, %f ,%f ,%f, %f", MT(2, 0), MT(2, 1), MT(2, 2), MT(2, 3), MT(2, 4), MT(2, 5));
   
    // 轨迹规划
    for (int i = 0 ;i < Ntest; i++)
    {
        double xi = x_end * i / double(Ntest);
        double yi = b * xi - xi * xi;

        xi = xi + init_pos(0);
        yi = yi + init_pos(2);

        Eigen::Vector3d q = myinverseKinematics(xi, yi, i);

        // q = q * 180 / pi;
        RCLCPP_INFO(this->get_logger(), "q: %f, %f, %f", q(0)* 180 / pi, q(1)* 180 / pi, q(2)* 180 / pi);
        TestposExp(i, 0) = q(0);
        TestposExp(i, 1) = q(1);
        TestposExp(i, 2) = q(2);
    }
    // 速度规划
    double vtest = this->get_parameter("Vmax").as_double();
    for (int i = 0 ;i < Ntest; i++)
    {
        double vangle = atan(b - 2 * TestposExp(i, 0));
        double vnorm = sin((i * M_PI / 2) / Ntest) * vtest;
        Eigen::Vector3d vel(vnorm * cos(vangle), 0 , vnorm * sin(vangle));
        TestvelExp.row(i) = MycomputeEndEffectorVelocity(vel(0), vel(2), TestposExp.row(i));
        RCLCPP_INFO(this->get_logger(), "TestvelExp: %f, %f, %f", TestvelExp(i, 0), TestvelExp(i, 1), TestvelExp(i, 2));
    }

    Eigen::Matrix3d TESTM;
    TESTM << 1, 2, 3, //q
        0.1, 0.2, 0.3, //dq
        0.01, 0.02, 0.03; //ddq
    
    Eigen::Vector3d tauxsm = generateM(TESTM.row(0).transpose()) * TESTM.row(2).transpose() + generateC(TESTM.row(0).transpose(), TESTM.row(1).transpose()) + generateG(TESTM.row(0).transpose());
    Eigen::Vector3d tauzwz = zwzmcgcal(TESTM.row(0).transpose(), TESTM.row(1).transpose(), TESTM.row(2).transpose());
    RCLCPP_INFO(this->get_logger(), "tauxsm: %f, %f, %f", tauxsm(0), tauxsm(1), tauxsm(2));
    RCLCPP_INFO(this->get_logger(), "tauzwz: %f, %f, %f", tauzwz(0), tauzwz(1), tauzwz(2));
    //===测试代码===

    // 给定速度调节系数k,  得到轨迹， 规划出序列
    
    // RCLCPP_INFO(this->get_logger(), "FT_method_node has been started.");
    // MatrixNumd4 posvelExp = endTrajectory(1);
    // RCLCPP_INFO(this->get_logger(), " endTrajectory finished.");

    // // 从轨迹中提取位置和速度,上半部分是位置，下半部分是速度
    // for (int i = 0; i < num1; i++)
    // {
    //     posExp(i, 0) = posvelExp(i, 0);
    //     posExp(i, 1) = posvelExp(i, 1);
    //     velExp(i, 0) = posvelExp(i + num1, 0);
    //     velExp(i, 1) = posvelExp(i + num1, 1);
    // }
    // RCLCPP_INFO(this->get_logger(),"here");
    // // 根据序列计算出机械臂预期的关节速度和角度
    // qExp = Eigen::MatrixXd::Zero(num1, 3);
    // dqExp = Eigen::MatrixXd::Zero(num1, 3);

    // RCLCPP_INFO(this->get_logger(), "compute qExp and dqExp");

    // for (int i = 0; i < num1; i++)
    // {
    //     qExp.row(i) = myinverseKinematics(posExp(i, 0) , posExp(i, 1) , i);
    //     dqExp.row(i) = MycomputeEndEffectorVelocity(velExp(i, 0), velExp(i, 1), qExp.row(i));
    // }

    // 定时器
    RCLCPP_INFO(this->get_logger(), "FT_method::FT_method has been callback.");


    FTrobotStatusSub_ = this->create_subscription<mit_msgs::msg::MITLowState>(
            "gazebo_low_state_topic",
            1,
            std::bind(&FT_method::robotStatusCallback, this, std::placeholders::_1));
    
    jointCommandPub_ = this->create_publisher<mit_msgs::msg::MITJointCommands>(
            "gazebo_joint_command_array",
            1);
}

Eigen::Vector3d FT_method::forwardKinematics(const Eigen::Vector3d& q)
{
    double theta1 = q(0);
    double theta2 = q(1);
    double theta3 = q(2);

    double x = L1 * cos(theta1) + L2 * cos(theta1 + theta2) + L3 * cos(theta1 + theta2 + theta3);
    double z = L1 * sin(theta1) + L2 * sin(theta1 + theta2) + L3 * sin(theta1 + theta2 + theta3);
    double y = 0; // 假设在 xz 平面内运动

    return Eigen::Vector3d(x, y, z);
}

// 析构函数定义
FT_method ::~FT_method()
{
    // 析构函数代码
}
