// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSMMSG__MSG__DETAIL__HWREV__TRAITS_HPP_
#define XSMMSG__MSG__DETAIL__HWREV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xsmmsg/msg/detail/hwrev__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xsmmsg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Hwrev & msg,
  std::ostream & out)
{
  out << "{";
  // member: tau
  {
    if (msg.tau.size() == 0) {
      out << "tau: []";
    } else {
      out << "tau: [";
      size_t pending_items = msg.tau.size();
      for (auto item : msg.tau) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hwrev & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tau
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tau.size() == 0) {
      out << "tau: []\n";
    } else {
      out << "tau:\n";
      for (auto item : msg.tau) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hwrev & msg, bool use_flow_style = false)
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

}  // namespace xsmmsg

namespace rosidl_generator_traits
{

[[deprecated("use xsmmsg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xsmmsg::msg::Hwrev & msg,
  std::ostream & out, size_t indentation = 0)
{
  xsmmsg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xsmmsg::msg::to_yaml() instead")]]
inline std::string to_yaml(const xsmmsg::msg::Hwrev & msg)
{
  return xsmmsg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xsmmsg::msg::Hwrev>()
{
  return "xsmmsg::msg::Hwrev";
}

template<>
inline const char * name<xsmmsg::msg::Hwrev>()
{
  return "xsmmsg/msg/Hwrev";
}

template<>
struct has_fixed_size<xsmmsg::msg::Hwrev>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xsmmsg::msg::Hwrev>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xsmmsg::msg::Hwrev>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XSMMSG__MSG__DETAIL__HWREV__TRAITS_HPP_
