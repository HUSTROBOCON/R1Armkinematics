// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mit_msgs/msg/detail/mit_joint_commands__rosidl_typesupport_introspection_c.h"
#include "mit_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mit_msgs/msg/detail/mit_joint_commands__functions.h"
#include "mit_msgs/msg/detail/mit_joint_commands__struct.h"


// Include directives for member types
// Member `commands`
#include "mit_msgs/msg/mit_joint_command.h"
// Member `commands`
#include "mit_msgs/msg/detail/mit_joint_command__rosidl_typesupport_introspection_c.h"
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mit_msgs__msg__MITJointCommands__init(message_memory);
}

void mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_fini_function(void * message_memory)
{
  mit_msgs__msg__MITJointCommands__fini(message_memory);
}

size_t mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__size_function__MITJointCommands__commands(
  const void * untyped_member)
{
  const mit_msgs__msg__MITJointCommand__Sequence * member =
    (const mit_msgs__msg__MITJointCommand__Sequence *)(untyped_member);
  return member->size;
}

const void * mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__get_const_function__MITJointCommands__commands(
  const void * untyped_member, size_t index)
{
  const mit_msgs__msg__MITJointCommand__Sequence * member =
    (const mit_msgs__msg__MITJointCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__get_function__MITJointCommands__commands(
  void * untyped_member, size_t index)
{
  mit_msgs__msg__MITJointCommand__Sequence * member =
    (mit_msgs__msg__MITJointCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__fetch_function__MITJointCommands__commands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mit_msgs__msg__MITJointCommand * item =
    ((const mit_msgs__msg__MITJointCommand *)
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__get_const_function__MITJointCommands__commands(untyped_member, index));
  mit_msgs__msg__MITJointCommand * value =
    (mit_msgs__msg__MITJointCommand *)(untyped_value);
  *value = *item;
}

void mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__assign_function__MITJointCommands__commands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mit_msgs__msg__MITJointCommand * item =
    ((mit_msgs__msg__MITJointCommand *)
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__get_function__MITJointCommands__commands(untyped_member, index));
  const mit_msgs__msg__MITJointCommand * value =
    (const mit_msgs__msg__MITJointCommand *)(untyped_value);
  *item = *value;
}

bool mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__resize_function__MITJointCommands__commands(
  void * untyped_member, size_t size)
{
  mit_msgs__msg__MITJointCommand__Sequence * member =
    (mit_msgs__msg__MITJointCommand__Sequence *)(untyped_member);
  mit_msgs__msg__MITJointCommand__Sequence__fini(member);
  return mit_msgs__msg__MITJointCommand__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_member_array[2] = {
  {
    "commands",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommands, commands),  // bytes offset in struct
    NULL,  // default value
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__size_function__MITJointCommands__commands,  // size() function pointer
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__get_const_function__MITJointCommands__commands,  // get_const(index) function pointer
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__get_function__MITJointCommands__commands,  // get(index) function pointer
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__fetch_function__MITJointCommands__commands,  // fetch(index, &value) function pointer
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__assign_function__MITJointCommands__commands,  // assign(index, value) function pointer
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__resize_function__MITJointCommands__commands  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommands, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_members = {
  "mit_msgs__msg",  // message namespace
  "MITJointCommands",  // message name
  2,  // number of fields
  sizeof(mit_msgs__msg__MITJointCommands),
  mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_member_array,  // message members
  mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_type_support_handle = {
  0,
  &mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mit_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mit_msgs, msg, MITJointCommands)() {
  mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mit_msgs, msg, MITJointCommand)();
  mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_type_support_handle.typesupport_identifier) {
    mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mit_msgs__msg__MITJointCommands__rosidl_typesupport_introspection_c__MITJointCommands_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
