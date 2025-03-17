#include <Eigen/Dense>
#include <iostream>
#include <cmath>
#include <mit_msgs/msg/detail/mit_low_state__struct.hpp>
#include "mit_msgs/msg/mit_joint_commands.hpp"
#include "mit_msgs/msg/mit_low_state.hpp"
#include "xsm_msg/msg/path.hpp"
#include "rclcpp/rclcpp.hpp"

class armend_visualize : public rclcpp::Node
{
public:
    rclcpp::Subscription<xsm_msg::msg::Path>::SharedPtr poscircle_sub_;
    rclcpp::Subscription<mit_msgs::msg::MITLowState>::SharedPtr SubjointState_;
    armend_visualize();
    Eigen::MatrixXd poscircle;
    Eigen::MatrixXd linepathPlan( int pathnum ,double lineangle, double linewidth, Eigen::Vector3d init_pos);

private:
    double L1 = 0.42; // 链接1的长度 //0.42
    double L2 = 0.48; // 链接2的长度 //0.52
    double L3 = 0.3805; // 链接3的长度 //0.358
    Eigen::Vector3d forwardKinematics(const Eigen::Vector3d& q);
    float figure_X[10000];
    float figure_Y[10000];
    void draw(Eigen::Vector3d q);
};