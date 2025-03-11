// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__STRUCT_H_
#define MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__struct.h"
// Member 'joint_states'
#include "sensor_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in msg/MITLowState in the package mit_msgs.
typedef struct mit_msgs__msg__MITLowState
{
  builtin_interfaces__msg__Time stamp;
  sensor_msgs__msg__Imu imu;
  sensor_msgs__msg__JointState joint_states;
} mit_msgs__msg__MITLowState;

// Struct for a sequence of mit_msgs__msg__MITLowState.
typedef struct mit_msgs__msg__MITLowState__Sequence
{
  mit_msgs__msg__MITLowState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mit_msgs__msg__MITLowState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__STRUCT_H_
