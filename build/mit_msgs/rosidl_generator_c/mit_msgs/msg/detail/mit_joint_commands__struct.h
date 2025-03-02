// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__STRUCT_H_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'commands'
#include "mit_msgs/msg/detail/mit_joint_command__struct.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/MITJointCommands in the package mit_msgs.
/**
  * DogeJointCommands.msg
 */
typedef struct mit_msgs__msg__MITJointCommands
{
  mit_msgs__msg__MITJointCommand__Sequence commands;
  builtin_interfaces__msg__Time stamp;
} mit_msgs__msg__MITJointCommands;

// Struct for a sequence of mit_msgs__msg__MITJointCommands.
typedef struct mit_msgs__msg__MITJointCommands__Sequence
{
  mit_msgs__msg__MITJointCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mit_msgs__msg__MITJointCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__STRUCT_H_
