// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mit_msgs/msg/detail/mit_low_state__rosidl_typesupport_introspection_c.h"
#include "mit_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mit_msgs/msg/detail/mit_low_state__functions.h"
#include "mit_msgs/msg/detail/mit_low_state__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `imu`
#include "sensor_msgs/msg/imu.h"
// Member `imu`
#include "sensor_msgs/msg/detail/imu__rosidl_typesupport_introspection_c.h"
// Member `joint_states`
#include "sensor_msgs/msg/joint_state.h"
// Member `joint_states`
#include "sensor_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mit_msgs__msg__MITLowState__init(message_memory);
}

void mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_fini_function(void * message_memory)
{
  mit_msgs__msg__MITLowState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_member_array[3] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITLowState, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITLowState, imu),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mit_msgs__msg__MITLowState, joint_states),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_members = {
  "mit_msgs__msg",  // message namespace
  "MITLowState",  // message name
  3,  // number of fields
  sizeof(mit_msgs__msg__MITLowState),
  mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_member_array,  // message members
  mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_init_function,  // function to initialize message memory (memory has to be allocated)
  mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_type_support_handle = {
  0,
  &mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mit_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mit_msgs, msg, MITLowState)() {
  mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Imu)();
  mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, JointState)();
  if (!mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_type_support_handle.typesupport_identifier) {
    mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mit_msgs__msg__MITLowState__rosidl_typesupport_introspection_c__MITLowState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
