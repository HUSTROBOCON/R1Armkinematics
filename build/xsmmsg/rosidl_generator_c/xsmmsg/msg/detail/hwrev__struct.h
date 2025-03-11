// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSMMSG__MSG__DETAIL__HWREV__STRUCT_H_
#define XSMMSG__MSG__DETAIL__HWREV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Hwrev in the package xsmmsg.
typedef struct xsmmsg__msg__Hwrev
{
  double tau[3];
} xsmmsg__msg__Hwrev;

// Struct for a sequence of xsmmsg__msg__Hwrev.
typedef struct xsmmsg__msg__Hwrev__Sequence
{
  xsmmsg__msg__Hwrev * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsmmsg__msg__Hwrev__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSMMSG__MSG__DETAIL__HWREV__STRUCT_H_
