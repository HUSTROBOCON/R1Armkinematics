// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__PATH__STRUCT_H_
#define XSM_MSG__MSG__DETAIL__PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Path in the package xsm_msg.
/**
  * 矩阵的行数和列数
 */
typedef struct xsm_msg__msg__Path
{
  int32_t rows;
  int32_t cols;
  /// 按行主序存储的矩阵数据
  rosidl_runtime_c__double__Sequence data;
} xsm_msg__msg__Path;

// Struct for a sequence of xsm_msg__msg__Path.
typedef struct xsm_msg__msg__Path__Sequence
{
  xsm_msg__msg__Path * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsm_msg__msg__Path__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSM_MSG__MSG__DETAIL__PATH__STRUCT_H_
