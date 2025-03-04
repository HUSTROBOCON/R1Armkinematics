#include <string>
#include <thread>
#include <Eigen/Dense>
#include <iostream>
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/frames.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/multibody/data.hpp"
#include "pinocchio/spatial/explog.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pid/pid.hpp>
#include <mit_msgs/msg/detail/mit_low_state__struct.hpp>
#include "mit_msgs/msg/mit_joint_commands.hpp"
#include "mit_msgs/msg/mit_low_state.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>

#include "rclcpp/rclcpp.hpp"



// #include <ament_index_cpp/get_package_share_directory.hpp>

#define num0 400
#define num1 600 // num * 1.5
#define pi 3.1415926
#define e 2.7182818

typedef Eigen::Matrix<double, num0, 4> MatrixNumd;
typedef Eigen::Matrix<double, num1, 2> MatrixNumd2;

typedef Eigen::Matrix<double, num1, 3> MatrixNumd3;

typedef Eigen::Matrix<double, 1200, 2> MatrixNumd4;


class FT_method : public rclcpp::Node
{
public:
    /* data */
    FT_method();   
    ~FT_method();
private:
    /* data */

    rclcpp::TimerBase::SharedPtr timer_;
    double g = 9.81;

    double m1 = 2.092699082; // 质量 m1
    double m2 = 2.317699082; // 质量 m2
    double m3 = 2.472699082; // 质量 m3

    double Lc1 = 0.16; // 链接1的质心位置
    double Lc2 = 0.1925; // 链接2的质心位置
    double Lc3 = 0.179; // 链接3的质心位置

    double L1 = 0.32; // 链接1的长度
    double L2 = 0.385; // 链接2的长度
    double L3 = 0.358; // 链接3的长度

    double J1 = 0.02828397; // 链接1的惯性矩
    double J2 = 0.04363308; // 链接2的惯性矩
    double J3 = 0.03698911; // 链接3的惯性矩

    // 定义系数
    double a1 = m1 * Lc1 * Lc1 + J1 + (m2 + m3) * L1 * L1;
    double a2 = J2 + m2 * Lc2 * Lc2 + m3 * L2 * L2;
    double a3 = (m2 * Lc2 + m3 * L2) * L1;
    double a4 = J3 + m3 * Lc3 * Lc3;
    double a5 = m3 * Lc3 * L1;
    double a6 = m3 * Lc3 * L2;

    double H_base = 0.5;

    // 定义一倍出手速度常数
    double v_end = 0.25;
    double a = 0.5; // 上升加速度
    int num = num0; // 采样点数
    
    // pinochio部分
    //创建模型
    //urdf文件路径
    //创建模型
    pinocchio::Model model;
    //定义刚体数据
    pinocchio::Data data;
    //定义关节和计算参数
    int jointNumber ;
    //逆解的参数
    int arm_nv;

    // 机械臂kp kd
    double arm_kp ;
    double arm_kd ;

    //计算结果反馈
    bool SolveFlag;
    //定义雅克比矩阵
    pinocchio::Data::Matrix6x J;    //定义解算结果
    Eigen::VectorXd q_out;
    //初始化模型
    void pino_init();
    // 角度归一化
    double nomalizeangle(double angle);
    //逆解函数
    bool pino_inv(double target_x,double target_y,double target_z);
    
    // 定义速度存储数组
    MatrixNumd2 posExp;
    MatrixNumd2 velExp;

    // 定义预期关节角度和速度
    MatrixNumd3 qExp;
    MatrixNumd3 dqExp;

    // 测试
    Eigen::MatrixXd TestposExp;
    Eigen::MatrixXd TestvelExp;

    // 位置环PID
    PID errorPosPid;
    PID errorVelPid;

    // 存储当前位置
    Eigen::Vector2d nowPosition;
    Eigen::Vector2d nowVelocity;
    Eigen::Vector3d qnow;
    Eigen::Vector3d dqnow;

    // 轨迹规划参数
    double x0 = 0.4;
    double b = 2*x0 + 1;

    // 寻找最近点参数
    const int forwardSearchPointNum; // 向前搜索点数
    const int backwardSearchPointNum; // 向后搜索点数
    int lastClosestPointId; // 上次搜索到最近点的id

    Eigen::Vector3d initial_q;
    Eigen::MatrixXd poscircle;
    Eigen::MatrixXd velcircle;
    Eigen::VectorXd yawcircle;
    Eigen::VectorXd wristcircle;
    Eigen::Vector3d init_pos ;

    // ros订阅
    rclcpp::Subscription<mit_msgs::msg::MITLowState>::SharedPtr FTrobotStatusSub_;
    rclcpp::Publisher<mit_msgs::msg::MITJointCommands>::SharedPtr
            jointCommandPub_;



    // 动力学方程 
    Eigen::Matrix3d generateM(Eigen::Vector3d q_0);
    Eigen::Vector3d generateC(Eigen::Vector3d q_0, Eigen::Vector3d dq_0);
    Eigen::Vector3d generateG(Eigen::Vector3d q_0);

    // 末端速度轨迹规划
    MatrixNumd4 endTrajectory(float k);

    // 使用pinocchio库计算机械臂关节期望位置
    Eigen::Vector3d computeEndEffectorPosition(double x ,double y);
    // 使用自己写的库计算
    Eigen::Vector3d myinverseKinematics(double x ,double z ,int num);

    // 使用pinocchio库计算机械臂关节期望速度
    Eigen:: Vector3d MycomputeEndEffectorVelocity(double dx, double dy , double w, Eigen::Vector3d q);
    // 使用pinocchio库计算机械臂关节期望加速度
    Eigen:: Vector3d computeJointAcceleration(const Eigen::Vector3d &ddx, const Eigen::Vector3d &dq ,Eigen ::Vector3d q ,double dw);

    // 跟踪计算速度
    Eigen::Vector2d trace(const Eigen::Vector2d& nowPosition, const int closestPointId ,Eigen::Vector2d& nowVelocity);
    
    // 寻找最近点
    int findClosestPoint(const Eigen::Vector2d& nowPosition , const Eigen::MatrixXd& ExpPosition ,int num ,double nowyaw ,const Eigen::VectorXd& expyaw);

    Eigen::MatrixXd computeJacobian(Eigen::Vector3d &q); // 计算雅各比矩阵的函数声明
    Eigen::MatrixXd computeJacobianDerivative(const Eigen::VectorXd &q ,const Eigen::VectorXd &dq); // 计算雅各比矩阵导数的函数声明

    double calculateDistance(const Eigen::Vector2d& a, const Eigen::Vector2d& b ,double nowtheta ,double exptheta); // 计算两点之间的距离

    Eigen::Vector3d forwardKinematics(const Eigen::Vector3d& q);

    Eigen::Vector3d computeEfftor(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow);

    void robotStatusCallback(mit_msgs::msg::MITLowState::SharedPtr msg) ;


    Eigen::MatrixXd pathPlan( int pathnum);
    Eigen::MatrixXd velPlan( int pathnum);
    Eigen::VectorXd yawPlan( int pathnum);
    Eigen::VectorXd wristPlan( int pathnum);
    Eigen::MatrixXd linepathPlan( int pathnum);
    Eigen::MatrixXd linespeedpathPlan( int pathnum);
    Eigen::VectorXd lineyawPlan( int pathnum);
    Eigen::VectorXd linewristPlan( int pathnum);
    Eigen::Vector3d zwzmcgcal(Eigen::Vector3d q, Eigen::Vector3d dq, Eigen::Vector3d ddq);
    Eigen:: Vector3d zwzVelcal(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow);
    Eigen::Vector3d zwzVeltaucal(Eigen::Vector3d& qnow ,Eigen::Vector3d& dqnow);

};

