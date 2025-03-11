// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__BUILDER_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mit_msgs/msg/detail/mit_low_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mit_msgs
{

namespace msg
{

namespace builder
{

class Init_MITLowState_joint_states
{
public:
  explicit Init_MITLowState_joint_states(::mit_msgs::msg::MITLowState & msg)
  : msg_(msg)
  {}
  ::mit_msgs::msg::MITLowState joint_states(::mit_msgs::msg::MITLowState::_joint_states_type arg)
  {
    msg_.joint_states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mit_msgs::msg::MITLowState msg_;
};

class Init_MITLowState_imu
{
public:
  explicit Init_MITLowState_imu(::mit_msgs::msg::MITLowState & msg)
  : msg_(msg)
  {}
  Init_MITLowState_joint_states imu(::mit_msgs::msg::MITLowState::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_MITLowState_joint_states(msg_);
  }

private:
  ::mit_msgs::msg::MITLowState msg_;
};

class Init_MITLowState_stamp
{
public:
  Init_MITLowState_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MITLowState_imu stamp(::mit_msgs::msg::MITLowState::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_MITLowState_imu(msg_);
  }

private:
  ::mit_msgs::msg::MITLowState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mit_msgs::msg::MITLowState>()
{
  return mit_msgs::msg::builder::Init_MITLowState_stamp();
}

}  // namespace mit_msgs

#endif  // MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__BUILDER_HPP_
