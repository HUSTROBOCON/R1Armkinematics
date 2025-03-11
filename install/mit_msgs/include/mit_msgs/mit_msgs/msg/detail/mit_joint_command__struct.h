// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__STRUCT_H_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MITJointCommand in the package mit_msgs.
/**
  * DogeJointCommand.msg
 */
typedef struct mit_msgs__msg__MITJointCommand
{
  float kp;
  float kd;
  float pos;
  float vel;
  float eff;
} mit_msgs__msg__MITJointCommand;

// Struct for a sequence of mit_msgs__msg__MITJointCommand.
typedef struct mit_msgs__msg__MITJointCommand__Sequence
{
  mit_msgs__msg__MITJointCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mit_msgs__msg__MITJointCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__STRUCT_H_
