#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/multibody/data.hpp"
#include "pinocchio/spatial/explog.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <mit_msgs/msg/detail/mit_joint_commands__struct.hpp>
#include <mit_msgs/msg/detail/mit_low_state__struct.hpp>
#include "Eigen/Dense"
#include "rclcpp/rclcpp.hpp"
#include "ForwardkinematicsT/FT_method.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FT_method>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
  
}