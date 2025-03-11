// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__TRAITS_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mit_msgs/msg/detail/mit_low_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__traits.hpp"
// Member 'joint_states'
#include "sensor_msgs/msg/detail/joint_state__traits.hpp"

namespace mit_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MITLowState & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: imu
  {
    out << "imu: ";
    to_flow_style_yaml(msg.imu, out);
    out << ", ";
  }

  // member: joint_states
  {
    out << "joint_states: ";
    to_flow_style_yaml(msg.joint_states, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MITLowState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: imu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu:\n";
    to_block_style_yaml(msg.imu, out, indentation + 2);
  }

  // member: joint_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_states:\n";
    to_block_style_yaml(msg.joint_states, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MITLowState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mit_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mit_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mit_msgs::msg::MITLowState & msg,
  std::ostream & out, size_t indentation = 0)
{
  mit_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mit_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mit_msgs::msg::MITLowState & msg)
{
  return mit_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mit_msgs::msg::MITLowState>()
{
  return "mit_msgs::msg::MITLowState";
}

template<>
inline const char * name<mit_msgs::msg::MITLowState>()
{
  return "mit_msgs/msg/MITLowState";
}

template<>
struct has_fixed_size<mit_msgs::msg::MITLowState>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<sensor_msgs::msg::Imu>::value && has_fixed_size<sensor_msgs::msg::JointState>::value> {};

template<>
struct has_bounded_size<mit_msgs::msg::MITLowState>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<sensor_msgs::msg::Imu>::value && has_bounded_size<sensor_msgs::msg::JointState>::value> {};

template<>
struct is_message<mit_msgs::msg::MITLowState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__TRAITS_HPP_
