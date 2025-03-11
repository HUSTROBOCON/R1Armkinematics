// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice
#include "xsmmsg/msg/detail/hwrev__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsmmsg/msg/detail/hwrev__struct.hpp"

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

namespace xsmmsg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsmmsg
cdr_serialize(
  const xsmmsg::msg::Hwrev & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: tau
  {
    cdr << ros_message.tau;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsmmsg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsmmsg::msg::Hwrev & ros_message)
{
  // Member: tau
  {
    cdr >> ros_message.tau;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsmmsg
get_serialized_size(
  const xsmmsg::msg::Hwrev & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: tau
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.tau[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsmmsg
max_serialized_size_Hwrev(
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


  // Member: tau
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xsmmsg::msg::Hwrev;
    is_plain =
      (
      offsetof(DataType, tau) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Hwrev__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsmmsg::msg::Hwrev *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Hwrev__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsmmsg::msg::Hwrev *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Hwrev__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsmmsg::msg::Hwrev *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Hwrev__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Hwrev(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Hwrev__callbacks = {
  "xsmmsg::msg",
  "Hwrev",
  _Hwrev__cdr_serialize,
  _Hwrev__cdr_deserialize,
  _Hwrev__get_serialized_size,
  _Hwrev__max_serialized_size
};

static rosidl_message_type_support_t _Hwrev__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Hwrev__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xsmmsg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsmmsg
const rosidl_message_type_support_t *
get_message_type_support_handle<xsmmsg::msg::Hwrev>()
{
  return &xsmmsg::msg::typesupport_fastrtps_cpp::_Hwrev__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsmmsg, msg, Hwrev)() {
  return &xsmmsg::msg::typesupport_fastrtps_cpp::_Hwrev__handle;
}

#ifdef __cplusplus
}
#endif
