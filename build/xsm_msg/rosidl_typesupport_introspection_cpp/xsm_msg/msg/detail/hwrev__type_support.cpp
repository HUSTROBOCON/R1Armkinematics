// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from xsm_msg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "xsm_msg/msg/detail/hwrev__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace xsm_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Hwrev_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) xsm_msg::msg::Hwrev(_init);
}

void Hwrev_fini_function(void * message_memory)
{
  auto typed_message = static_cast<xsm_msg::msg::Hwrev *>(message_memory);
  typed_message->~Hwrev();
}

size_t size_function__Hwrev__tau(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__Hwrev__tau(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__Hwrev__tau(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__Hwrev__tau(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Hwrev__tau(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Hwrev__tau(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Hwrev__tau(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Hwrev_message_member_array[1] = {
  {
    "tau",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xsm_msg::msg::Hwrev, tau),  // bytes offset in struct
    nullptr,  // default value
    size_function__Hwrev__tau,  // size() function pointer
    get_const_function__Hwrev__tau,  // get_const(index) function pointer
    get_function__Hwrev__tau,  // get(index) function pointer
    fetch_function__Hwrev__tau,  // fetch(index, &value) function pointer
    assign_function__Hwrev__tau,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Hwrev_message_members = {
  "xsm_msg::msg",  // message namespace
  "Hwrev",  // message name
  1,  // number of fields
  sizeof(xsm_msg::msg::Hwrev),
  Hwrev_message_member_array,  // message members
  Hwrev_init_function,  // function to initialize message memory (memory has to be allocated)
  Hwrev_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Hwrev_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Hwrev_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace xsm_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<xsm_msg::msg::Hwrev>()
{
  return &::xsm_msg::msg::rosidl_typesupport_introspection_cpp::Hwrev_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, xsm_msg, msg, Hwrev)() {
  return &::xsm_msg::msg::rosidl_typesupport_introspection_cpp::Hwrev_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
