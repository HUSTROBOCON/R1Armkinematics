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
    //   using namespace pinocchio;
 
//   // You should change here to set up your own URDF file or just pass it as an argument of this
//   // example.
// //   const std::string urdf_filename =
// //     (argc <= 1) ? PINOCCHIO_MODEL_DIR
// //                     + std::string("/example-robot-data/robots/ur_description/urdf/ur5_robot.urdf")
// //                 : argv[1];
 
//   // Load the urdf model
//   Model model;
//   pinocchio::urdf::buildModel("/home/xsm/R1_ws/src/arm_dynamics_hw/urdf/ARMvertical.urdf", model);
//   std::cout << "model name: " << model.name << std::endl;
 
//   // Create data required by the algorithms
//   Data data(model);
 
//   // Sample a random configuration
//   Eigen::VectorXd q = randomConfiguration(model);
//   std::cout << "q: " << q.transpose() << std::endl;
 
//   // Perform the forward kinematics over the kinematic tree
//   forwardKinematics(model, data, q);
 
//   // Print out the placement of each joint of the kinematic tree
//   for (JointIndex joint_id = 0; joint_id < (JointIndex)model.njoints; ++joint_id)
//     std::cout << std::setw(24) << std::left << model.names[joint_id] << ": " << std::fixed
//               << std::setprecision(2) << data.oMi[joint_id].translation().transpose() << std::endl;
}