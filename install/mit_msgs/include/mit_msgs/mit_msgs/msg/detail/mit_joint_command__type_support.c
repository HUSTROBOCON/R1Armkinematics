// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mit_msgs/msg/detail/mit_joint_command__rosidl_typesupport_introspection_c.h"
#include "mit_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mit_msgs/msg/detail/mit_joint_command__functions.h"
#include "mit_msgs/msg/detail/mit_joint_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mit_msgs__msg__MITJointCommand__init(message_memory);
}

void mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_fini_function(void * message_memory)
{
  mit_msgs__msg__MITJointCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_member_array[5] = {
  {
    "kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommand, kp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommand, kd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommand, pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommand, vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITJointCommand, eff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_members = {
  "mit_msgs__msg",  // message namespace
  "MITJointCommand",  // message name
  5,  // number of fields
  sizeof(mit_msgs__msg__MITJointCommand),
  mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_member_array,  // message members
  mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_type_support_handle = {
  0,
  &mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mit_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mit_msgs, msg, MITJointCommand)() {
  if (!mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_type_support_handle.typesupport_identifier) {
    mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mit_msgs__msg__MITJointCommand__rosidl_typesupport_introspection_c__MITJointCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
