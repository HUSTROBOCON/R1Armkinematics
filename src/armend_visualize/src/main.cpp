#include <iostream>
#include <cmath>
#include "armend_visualize/visualize.hpp"
#include <mit_msgs/msg/detail/mit_low_state__struct.hpp>
#include "mit_msgs/msg/mit_joint_commands.hpp"
#include "mit_msgs/msg/mit_low_state.hpp"
#include "Eigen/Dense"
#include <matplotlibcpp.h>
#include "rclcpp/rclcpp.hpp"


namespace plt = matplotlibcpp;

Eigen::Vector3d armend_visualize::forwardKinematics(const Eigen::Vector3d& q)
{
    double theta1 = q(0);
    double theta2 = q(1);
    double theta3 = q(2);

    double x = L1 * cos(theta1) + L2 * cos(theta1 + theta2) + L3 * cos(theta1 + theta2 + theta3);
    double z = L1 * sin(theta1) + L2 * sin(theta1 + theta2) + L3 * sin(theta1 + theta2 + theta3);
    double y = 0; // 假设在 xz 平面内运动

    return Eigen::Vector3d(x, y, z);
}

void armend_visualize::draw(Eigen::Vector3d q)
{
    RCLCPP_INFO(this->get_logger(), "Drawing");
    if (q(0) == 0 && q(1) == 0 && q(2) == 0)
    {
        return;
    }
    Eigen ::Vector3d endpos = forwardKinematics(q);
    // 传入值赋第一个点，其他点依次后移
    for (int i = 9999; i > 0; i--)
    {
        figure_X[i] = figure_X[i - 1];
        figure_Y[i] = figure_Y[i - 1];
    }
    figure_X[0] = endpos(0);
    figure_Y[0] = endpos(2);

    plt::clf();
    plt::plot(figure_X,figure_Y,"r");
    plt::pause(0.01);

}

armend_visualize::armend_visualize() : Node("armend_visualize")
{
    RCLCPP_INFO(this->get_logger(), "Hello World");
    // 这里和config文件中的参数对应
    Eigen::Vector3d init_q(-45 * M_PI / 180, 135 * M_PI / 180, 90 * M_PI / 180);
    Eigen::Vector3d init_pos = forwardKinematics(init_q);
    for (int i = 0; i < 10000; i++)
    {
        figure_X[i] = init_pos(0);
        figure_Y[i] = init_pos(2);
    }
    SubjointState_ =this->create_subscription<mit_msgs::msg::MITLowState>(
        "gazebo_low_state_topic",
        1,
        [this](const mit_msgs::msg::MITLowState::SharedPtr msg){
            RCLCPP_INFO(this->get_logger(), "I heard: [%f, %f, %f]", msg->joint_states.position[0], msg->joint_states.position[1], msg->joint_states.position[2]);
            draw(Eigen::Vector3d(msg->joint_states.position[0], msg->joint_states.position[1], msg->joint_states.position[2]));
        });
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<armend_visualize>();
    RCLCPP_INFO(node->get_logger(), "Hello World");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}