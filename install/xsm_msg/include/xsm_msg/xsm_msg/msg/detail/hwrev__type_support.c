// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsm_msg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsm_msg/msg/detail/hwrev__rosidl_typesupport_introspection_c.h"
#include "xsm_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsm_msg/msg/detail/hwrev__functions.h"
#include "xsm_msg/msg/detail/hwrev__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsm_msg__msg__Hwrev__init(message_memory);
}

void xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_fini_function(void * message_memory)
{
  xsm_msg__msg__Hwrev__fini(message_memory);
}

size_t xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__size_function__Hwrev__tau(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__get_const_function__Hwrev__tau(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__get_function__Hwrev__tau(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__fetch_function__Hwrev__tau(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__get_const_function__Hwrev__tau(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__assign_function__Hwrev__tau(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__get_function__Hwrev__tau(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_member_array[1] = {
  {
    "tau",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xsm_msg__msg__Hwrev, tau),  // bytes offset in struct
    NULL,  // default value
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__size_function__Hwrev__tau,  // size() function pointer
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__get_const_function__Hwrev__tau,  // get_const(index) function pointer
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__get_function__Hwrev__tau,  // get(index) function pointer
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__fetch_function__Hwrev__tau,  // fetch(index, &value) function pointer
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__assign_function__Hwrev__tau,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_members = {
  "xsm_msg__msg",  // message namespace
  "Hwrev",  // message name
  1,  // number of fields
  sizeof(xsm_msg__msg__Hwrev),
  xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_member_array,  // message members
  xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_init_function,  // function to initialize message memory (memory has to be allocated)
  xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_type_support_handle = {
  0,
  &xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsm_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsm_msg, msg, Hwrev)() {
  if (!xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_type_support_handle.typesupport_identifier) {
    xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &xsm_msg__msg__Hwrev__rosidl_typesupport_introspection_c__Hwrev_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
