// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice
#include "xsm_msg/msg/detail/path__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsm_msg/msg/detail/path__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: rows
  cdr << ros_message.rows;
  // Member: cols
  cdr << ros_message.cols;
  // Member: data
  {
    cdr << ros_message.data;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsm_msg::msg::Path & ros_message)
{
  // Member: rows
  cdr >> ros_message.rows;

  // Member: cols
  cdr >> ros_message.cols;

  // Member: data
  {
    cdr >> ros_message.data;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
get_serialized_size(
  const xsm_msg::msg::Path & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: rows
  {
    size_t item_size = sizeof(ros_message.rows);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cols
  {
    size_t item_size = sizeof(ros_message.cols);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: data
  {
    size_t array_size = ros_message.data.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.data[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsm_msg
max_serialized_size_Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: rows
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: cols
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xsm_msg::msg::Path;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Path__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsm_msg::msg::Path *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Path__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsm_msg::msg::Path *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Path__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsm_msg::msg::Path *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Path__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Path(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Path__callbacks = {
  "xsm_msg::msg",
  "Path",
  _Path__cdr_serialize,
  _Path__cdr_deserialize,
  _Path__get_serialized_size,
  _Path__max_serialized_size
};

static rosidl_message_type_support_t _Path__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Path__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xsm_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsm_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<xsm_msg::msg::Path>()
{
  return &xsm_msg::msg::typesupport_fastrtps_cpp::_Path__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsm_msg, msg, Path)() {
  return &xsm_msg::msg::typesupport_fastrtps_cpp::_Path__handle;
}

#ifdef __cplusplus
}
#endif
