// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mit_msgs/msg/detail/mit_joint_commands__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mit_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MITJointCommands_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mit_msgs::msg::MITJointCommands(_init);
}

void MITJointCommands_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mit_msgs::msg::MITJointCommands *>(message_memory);
  typed_message->~MITJointCommands();
}

size_t size_function__MITJointCommands__commands(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<mit_msgs::msg::MITJointCommand> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MITJointCommands__commands(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<mit_msgs::msg::MITJointCommand> *>(untyped_member);
  return &member[index];
}

void * get_function__MITJointCommands__commands(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<mit_msgs::msg::MITJointCommand> *>(untyped_member);
  return &member[index];
}

void fetch_function__MITJointCommands__commands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const mit_msgs::msg::MITJointCommand *>(
    get_const_function__MITJointCommands__commands(untyped_member, index));
  auto & value = *reinterpret_cast<mit_msgs::msg::MITJointCommand *>(untyped_value);
  value = item;
}

void assign_function__MITJointCommands__commands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<mit_msgs::msg::MITJointCommand *>(
    get_function__MITJointCommands__commands(untyped_member, index));
  const auto & value = *reinterpret_cast<const mit_msgs::msg::MITJointCommand *>(untyped_value);
  item = value;
}

void resize_function__MITJointCommands__commands(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<mit_msgs::msg::MITJointCommand> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MITJointCommands_message_member_array[2] = {
  {
    "commands",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<mit_msgs::msg::MITJointCommand>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs::msg::MITJointCommands, commands),  // bytes offset in struct
    nullptr,  // default value
    size_function__MITJointCommands__commands,  // size() function pointer
    get_const_function__MITJointCommands__commands,  // get_const(index) function pointer
    get_function__MITJointCommands__commands,  // get(index) function pointer
    fetch_function__MITJointCommands__commands,  // fetch(index, &value) function pointer
    assign_function__MITJointCommands__commands,  // assign(index, value) function pointer
    resize_function__MITJointCommands__commands  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs::msg::MITJointCommands, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MITJointCommands_message_members = {
  "mit_msgs::msg",  // message namespace
  "MITJointCommands",  // message name
  2,  // number of fields
  sizeof(mit_msgs::msg::MITJointCommands),
  MITJointCommands_message_member_array,  // message members
  MITJointCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  MITJointCommands_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MITJointCommands_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MITJointCommands_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mit_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mit_msgs::msg::MITJointCommands>()
{
  return &::mit_msgs::msg::rosidl_typesupport_introspection_cpp::MITJointCommands_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mit_msgs, msg, MITJointCommands)() {
  return &::mit_msgs::msg::rosidl_typesupport_introspection_cpp::MITJointCommands_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
