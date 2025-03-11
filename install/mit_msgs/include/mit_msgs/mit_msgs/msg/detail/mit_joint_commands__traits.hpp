// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__TRAITS_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mit_msgs/msg/detail/mit_joint_commands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'commands'
#include "mit_msgs/msg/detail/mit_joint_command__traits.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace mit_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MITJointCommands & msg,
  std::ostream & out)
{
  out << "{";
  // member: commands
  {
    if (msg.commands.size() == 0) {
      out << "commands: []";
    } else {
      out << "commands: [";
      size_t pending_items = msg.commands.size();
      for (auto item : msg.commands) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MITJointCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: commands
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.commands.size() == 0) {
      out << "commands: []\n";
    } else {
      out << "commands:\n";
      for (auto item : msg.commands) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MITJointCommands & msg, bool use_flow_style = false)
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
  const mit_msgs::msg::MITJointCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  mit_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mit_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mit_msgs::msg::MITJointCommands & msg)
{
  return mit_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mit_msgs::msg::MITJointCommands>()
{
  return "mit_msgs::msg::MITJointCommands";
}

template<>
inline const char * name<mit_msgs::msg::MITJointCommands>()
{
  return "mit_msgs/msg/MITJointCommands";
}

template<>
struct has_fixed_size<mit_msgs::msg::MITJointCommands>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mit_msgs::msg::MITJointCommands>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mit_msgs::msg::MITJointCommands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__TRAITS_HPP_
