// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__PATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define XSM_MSG__MSG__DETAIL__PATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "xsm_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "xsm_msg/msg/detail/path__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace xsm_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
cdr_serialize(
  const xsm_msg::msg::Path & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsm_msg::msg::Path & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
get_serialized_size(
  const xsm_msg::msg::Path & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
max_serialized_size_Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xsm_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsm_msg, msg, Path)();

#ifdef __cplusplus
}
#endif

#endif  // XSM_MSG__MSG__DETAIL__PATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
