// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__BUILDER_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mit_msgs/msg/detail/mit_joint_commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mit_msgs
{

namespace msg
{

namespace builder
{

class Init_MITJointCommands_stamp
{
public:
  explicit Init_MITJointCommands_stamp(::mit_msgs::msg::MITJointCommands & msg)
  : msg_(msg)
  {}
  ::mit_msgs::msg::MITJointCommands stamp(::mit_msgs::msg::MITJointCommands::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommands msg_;
};

class Init_MITJointCommands_commands
{
public:
  Init_MITJointCommands_commands()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MITJointCommands_stamp commands(::mit_msgs::msg::MITJointCommands::_commands_type arg)
  {
    msg_.commands = std::move(arg);
    return Init_MITJointCommands_stamp(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mit_msgs::msg::MITJointCommands>()
{
  return mit_msgs::msg::builder::Init_MITJointCommands_commands();
}

}  // namespace mit_msgs

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__BUILDER_HPP_
