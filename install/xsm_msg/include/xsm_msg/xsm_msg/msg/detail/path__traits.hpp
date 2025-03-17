// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__PATH__TRAITS_HPP_
#define XSM_MSG__MSG__DETAIL__PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xsm_msg/msg/detail/path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xsm_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Path & msg,
  std::ostream & out)
{
  out << "{";
  // member: rows
  {
    out << "rows: ";
    rosidl_generator_traits::value_to_yaml(msg.rows, out);
    out << ", ";
  }

  // member: cols
  {
    out << "cols: ";
    rosidl_generator_traits::value_to_yaml(msg.cols, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
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
  const Path & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: rows
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rows: ";
    rosidl_generator_traits::value_to_yaml(msg.rows, out);
    out << "\n";
  }

  // member: cols
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cols: ";
    rosidl_generator_traits::value_to_yaml(msg.cols, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
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

inline std::string to_yaml(const Path & msg, bool use_flow_style = false)
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

}  // namespace xsm_msg

namespace rosidl_generator_traits
{

[[deprecated("use xsm_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xsm_msg::msg::Path & msg,
  std::ostream & out, size_t indentation = 0)
{
  xsm_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xsm_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const xsm_msg::msg::Path & msg)
{
  return xsm_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xsm_msg::msg::Path>()
{
  return "xsm_msg::msg::Path";
}

template<>
inline const char * name<xsm_msg::msg::Path>()
{
  return "xsm_msg/msg/Path";
}

template<>
struct has_fixed_size<xsm_msg::msg::Path>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<xsm_msg::msg::Path>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<xsm_msg::msg::Path>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XSM_MSG__MSG__DETAIL__PATH__TRAITS_HPP_
