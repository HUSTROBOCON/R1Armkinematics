// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__BUILDER_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mit_msgs/msg/detail/mit_joint_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mit_msgs
{

namespace msg
{

namespace builder
{

class Init_MITJointCommand_eff
{
public:
  explicit Init_MITJointCommand_eff(::mit_msgs::msg::MITJointCommand & msg)
  : msg_(msg)
  {}
  ::mit_msgs::msg::MITJointCommand eff(::mit_msgs::msg::MITJointCommand::_eff_type arg)
  {
    msg_.eff = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommand msg_;
};

class Init_MITJointCommand_vel
{
public:
  explicit Init_MITJointCommand_vel(::mit_msgs::msg::MITJointCommand & msg)
  : msg_(msg)
  {}
  Init_MITJointCommand_eff vel(::mit_msgs::msg::MITJointCommand::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_MITJointCommand_eff(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommand msg_;
};

class Init_MITJointCommand_pos
{
public:
  explicit Init_MITJointCommand_pos(::mit_msgs::msg::MITJointCommand & msg)
  : msg_(msg)
  {}
  Init_MITJointCommand_vel pos(::mit_msgs::msg::MITJointCommand::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_MITJointCommand_vel(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommand msg_;
};

class Init_MITJointCommand_kd
{
public:
  explicit Init_MITJointCommand_kd(::mit_msgs::msg::MITJointCommand & msg)
  : msg_(msg)
  {}
  Init_MITJointCommand_pos kd(::mit_msgs::msg::MITJointCommand::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return Init_MITJointCommand_pos(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommand msg_;
};

class Init_MITJointCommand_kp
{
public:
  Init_MITJointCommand_kp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MITJointCommand_kd kp(::mit_msgs::msg::MITJointCommand::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_MITJointCommand_kd(msg_);
  }

private:
  ::mit_msgs::msg::MITJointCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mit_msgs::msg::MITJointCommand>()
{
  return mit_msgs::msg::builder::Init_MITJointCommand_kp();
}

}  // namespace mit_msgs

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__BUILDER_HPP_
