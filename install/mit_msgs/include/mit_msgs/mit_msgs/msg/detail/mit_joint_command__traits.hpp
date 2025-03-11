// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__TRAITS_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mit_msgs/msg/detail/mit_joint_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mit_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MITJointCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: kp
  {
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << ", ";
  }

  // member: kd
  {
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
    out << ", ";
  }

  // member: pos
  {
    out << "pos: ";
    rosidl_generator_traits::value_to_yaml(msg.pos, out);
    out << ", ";
  }

  // member: vel
  {
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << ", ";
  }

  // member: eff
  {
    out << "eff: ";
    rosidl_generator_traits::value_to_yaml(msg.eff, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MITJointCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << "\n";
  }

  // member: kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
    out << "\n";
  }

  // member: pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos: ";
    rosidl_generator_traits::value_to_yaml(msg.pos, out);
    out << "\n";
  }

  // member: vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << "\n";
  }

  // member: eff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "eff: ";
    rosidl_generator_traits::value_to_yaml(msg.eff, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MITJointCommand & msg, bool use_flow_style = false)
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
  const mit_msgs::msg::MITJointCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  mit_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mit_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mit_msgs::msg::MITJointCommand & msg)
{
  return mit_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mit_msgs::msg::MITJointCommand>()
{
  return "mit_msgs::msg::MITJointCommand";
}

template<>
inline const char * name<mit_msgs::msg::MITJointCommand>()
{
  return "mit_msgs/msg/MITJointCommand";
}

template<>
struct has_fixed_size<mit_msgs::msg::MITJointCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mit_msgs::msg::MITJointCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mit_msgs::msg::MITJointCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__TRAITS_HPP_
