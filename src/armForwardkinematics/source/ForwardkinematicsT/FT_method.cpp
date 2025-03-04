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


                                                                                                                             
double FT_method:: nomalizeangle(double angle)
{
    while (angle >= M_PI)
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

Eigen:: Vector3d FT_method::MycomputeEndEffectorVelocity(double dx, double dy ,double w, Eigen::Vector3d q)
{
    Eigen::MatrixXd Jt(6, 3);
    Eigen::Vector3d dq_out;
    dq_out = Eigen::VectorXd::Zero(3);    
    Eigen::VectorXd target_dq(6);
    Jt = computeJacobian(q);
    target_dq << dx, 0, dy, 0, w, 0;
    Eigen::MatrixXd Jt_pinv = Jt.completeOrthogonalDecomposition().pseudoInverse();
    dq_out = Jt_pinv * target_dq;
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
    // 计算雅各比矩阵
    Eigen::MatrixXd Jt = computeJacobian(q);
    // 计算雅各比矩阵的导数
    Eigen::MatrixXd dJ = computeJacobianDerivative(q ,dq);
    // 计算关节加速度
    Eigen::VectorXd ddq6(6);
    ddq6 = Jt.completeOrthogonalDecomposition().pseudoInverse() * (ddx6 - dJ * dq6);
    Eigen::Vector3d ddq;
    ddq << ddq6(0), ddq6(1), ddq6(2);
    return ddq;                                                                                                                                                                                 
}

// 计算两点之间的距离
double FT_method::calculateDistance(const Eigen::Vector2d& a, const Eigen::Vector2d& b ,double nowtheta ,double exptheta) {
    double dis = sqrt(pow(a(0) - b(0), 2) + pow(a(1) - b(1), 2) + 0.1 * pow((nowtheta - exptheta), 2));
    return dis;
}

// 寻找最近点
int FT_method:: findClosestPoint(const Eigen::Vector2d& nowPosition , const Eigen::MatrixXd& ExpPosition ,int num ,double nowyaw ,const Eigen::VectorXd& expyaw)
{
    float minDistance = std::numeric_limits<float>::infinity();

    int startId = lastClosestPointId - forwardSearchPointNum;
    int endId = lastClosestPointId + backwardSearchPointNum;
    // 众所周知，程序员从0数数
    startId = std::clamp(startId, 0, num-1);
    endId = std::clamp(endId, 0, num-1);

    int closestPointId = -1;

    for (int i = startId; i <= endId; i++) {
        float distance = calculateDistance(Eigen::Vector2d(ExpPosition(i,0),ExpPosition(i,2)), nowPosition ,nowyaw ,expyaw(i));
        if (distance < minDistance) {
            minDistance = distance;
            closestPointId = i;
        }
    }

    lastClosestPointId = closestPointId;

    return closestPointId;
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
        
        Eigen::Vector3d effort = zwzVeltaucal(robotStatusPos, robotStatusVel);

        // 计算当前位置
        mit_msgs::msg::MITJointCommands jointCommand;
        jointCommand.commands.resize(3);
        jointCommand.commands[0].pos = 0;//double(-90*pi/180);//effortPosVel(1, 0);
        jointCommand.commands[0].vel = 0;//effortPosVel(2, 0);
        jointCommand.commands[0].eff = effort(0);
        jointCommand.commands[1].pos = 0;//effortPosVel(1, 1);
        jointCommand.commands[1].vel = 0;//effortPosVel(2, 1);
        jointCommand.commands[1].eff = effort(1);
        jointCommand.commands[2].pos = 0;//effortPosVel(1, 2);
        jointCommand.commands[2].vel = 1;//effortPosVel(2, 2);
        jointCommand.commands[2].eff = effort(2);
        jointCommandPub_->publish(jointCommand);

}

// 构造函数定义
FT_method ::FT_method() :
    rclcpp::Node("FT_method_node"), // 使用节点名称初始化基类
    errorPosPid(5, 0.5, 0, 1, 0.05, 0.01),
    errorVelPid(5, 0.5, 0.5, 1, 0.05, 0.01), 
    forwardSearchPointNum(5),
    backwardSearchPointNum(10)
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
    this->declare_parameter<int>("Nzwz");
    this->declare_parameter<double>("lineangle");
    this->declare_parameter<double>("linewidth");
    this->declare_parameter<double>("Wmax");
    this->declare_parameter<double>("shootangle");


    arm_kp = this->get_parameter("kp").as_double();
    arm_kd = this->get_parameter("kd").as_double();


    //===测试代码===
    initial_q <<this->get_parameter("joint1").as_double(), this->get_parameter("joint2").as_double(), this->get_parameter("joint3").as_double();
    initial_q = initial_q * pi / 180;
    init_pos = forwardKinematics(initial_q);
    RCLCPP_INFO(this->get_logger(), "init_pos: %f, %f, %f", init_pos(0), init_pos(1), init_pos(2));

    // 新速度规划
    int Nnum = this->get_parameter("Nzwz").as_int();
    poscircle = Eigen::MatrixXd::Zero(Nnum, 3);
    velcircle = Eigen::MatrixXd::Zero(Nnum, 2);
    // poscircle = pathPlan(Nnum);
    // velcircle = velPlan(Nnum);
    // yawcircle = yawPlan(Nnum);
    // wristcircle = wristPlan(Nnum);
    poscircle = linepathPlan(Nnum);
    velcircle = linespeedpathPlan(Nnum);
    yawcircle = lineyawPlan(Nnum);
    wristcircle = linewristPlan(Nnum);
    for (int i = 0; i < Nnum; i++)
    {
        // RCLCPP_INFO(this->get_logger(), "poscircle: %f, %f", poscircle(i, 0), poscircle(i, 2));
        RCLCPP_INFO(this->get_logger(), "velcircle: %f, %f", velcircle(i, 0), velcircle(i, 1));
    }

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
