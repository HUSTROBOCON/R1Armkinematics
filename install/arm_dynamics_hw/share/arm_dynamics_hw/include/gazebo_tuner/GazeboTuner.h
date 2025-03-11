//
// Created by lock on 2024/12/1.
//
#pragma once

#include <mit_msgs/msg/detail/mit_low_state__struct.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/timer.hpp>
#ifndef GAZEBO_TUNER_PACKAGE_PATH
#warning "GAZEBO_TUNER_PACKAGE_PATH is not defined"
#endif

#include <gazebo_msgs/srv/detail/apply_body_wrench__struct.hpp>
#include <gazebo_msgs/srv/detail/apply_link_wrench__struct.hpp>
#include <nav_msgs/msg/detail/odometry__struct.hpp>
#include <rclcpp/logging.hpp>
#include <vector>
#include <chrono>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <sensor_msgs/msg/imu.hpp> // 包含IMU消息类型
#include <gazebo_msgs/srv/set_physics_properties.hpp>
#include <cmath>
#include <queue>
#include <unistd.h>
#include "yaml-cpp/yaml.h"
#include "lock_utils/SaveParseCSV.h"
#include <Eigen/Dense>
// ros2的msg要使用小写+hpp尾缀
#include "mit_msgs/msg/mit_low_state.hpp"
#include "mit_msgs/msg/mit_joint_commands.hpp"
#include <gazebo_msgs/srv/apply_link_wrench.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"
#include <yaml-cpp/yaml.h>
// #include "gazebo_msgs/srv/apply_link_wrench.hpp"

using namespace std::chrono_literals;
class GazeboTuner : public rclcpp::Node {
public:
    // 添加一个固定的关节顺序数组

    // 添加一个固定的关节顺序数组
    const std::vector<std::string> joint_name_order_ = {
        "joint1",
        "joint2",
        "joint3"
    };

    // 添加一个映射表用于快速查找关节索引
    std::unordered_map<std::string, size_t> joint_name_to_index_;

    std::vector<std::vector<double>> torqueRecordTable_;
    std::vector<std::vector<double>> torqueDemandedRecordTable_;
    std::vector<std::vector<double>> velocityRecordTable_;
    std::vector<std::vector<double>> positionRecordTable_;

    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr jointCommandPublisher_;
    rclcpp::Subscription<mit_msgs::msg::MITJointCommands>::SharedPtr jointCommandSubscriber_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr jointStateSubscriber_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imuSubscriber_;
    rclcpp::Publisher<mit_msgs::msg::MITLowState>::SharedPtr lowStatePublisher_;
    int counter_{0};

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

    GazeboTuner(const std::string& configFilePath);

    ~GazeboTuner();

private:
    YAML::Node configNode_;

    bool fixBaseFlag_;
    // 初始化目标位置和姿态
    Eigen::Vector3d    desired_position_ = Eigen::Vector3d(0.0, 0.0, 0.0); // 期望悬停高度
    Eigen::Vector3d    desired_orientation_ = Eigen::Vector3d(0.0, 0.0, 0.0); // 期望水平姿态
        // PD控制器参数
    Eigen::Vector3d    Kp_position_ = Eigen::Vector3d(100.0, 100.0, 300.0);
    Eigen::Vector3d    Kd_position_ = Eigen::Vector3d(10.0, 10.0, 10.0);
    Eigen::Vector3d    Kp_orientation_ = Eigen::Vector3d(100.0, 100.0, 100.0);
    Eigen::Vector3d    Kd_orientation_ = Eigen::Vector3d(10.0, 10.0,10.0);
    // 状态变量
    Eigen::Vector3d current_position_;
    Eigen::Vector3d current_orientation_;
    Eigen::Vector3d current_linear_vel_;
    Eigen::Vector3d current_angular_vel_;
    Eigen::Vector3d last_position_;
    Eigen::Vector3d last_orientation_;

    std::string lowStateTopic_;
    std::string jointCommandTopic_;
    mit_msgs::msg::MITLowState lowState_;
    mit_msgs::msg::MITJointCommands jointCommands_; // 关节命令
    sensor_msgs::msg::JointState jointState_;
    sensor_msgs::msg::Imu imuData_; // IMU数据
    std_msgs::msg::Float64MultiArray commands_;
    rclcpp::TimerBase::SharedPtr jointControllerTimer_;
    rclcpp::TimerBase::SharedPtr fixBaseControllerTimer_;
    std::queue<mit_msgs::msg::MITJointCommands> jointCommandArrayQueue_;//消息队列
    
    // 服务客户端
    rclcpp::Client<gazebo_msgs::srv::ApplyLinkWrench>::SharedPtr wrench_client_;
    // 订阅者
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;


    double delay_{1};//延迟时间

    void jointCommandCallback(const mit_msgs::msg::MITJointCommands::SharedPtr msg);

    void printDetailedStatus(const std::vector<double>& sorted_positions,
                                    const std::vector<double>& sorted_velocities,
                                    const std::vector<double>& sorted_efforts);

    void fixBaseCallBack();

    void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg);

    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);

    void jointControllerTimerCallback();
};

