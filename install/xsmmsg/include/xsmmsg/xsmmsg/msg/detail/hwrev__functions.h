// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSMMSG__MSG__DETAIL__HWREV__FUNCTIONS_H_
#define XSMMSG__MSG__DETAIL__HWREV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xsmmsg/msg/rosidl_generator_c__visibility_control.h"

#include "xsmmsg/msg/detail/hwrev__struct.h"

/// Initialize msg/Hwrev message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xsmmsg__msg__Hwrev
 * )) before or use
 * xsmmsg__msg__Hwrev__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
bool
xsmmsg__msg__Hwrev__init(xsmmsg__msg__Hwrev * msg);

/// Finalize msg/Hwrev message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
void
xsmmsg__msg__Hwrev__fini(xsmmsg__msg__Hwrev * msg);

/// Create msg/Hwrev message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xsmmsg__msg__Hwrev__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
xsmmsg__msg__Hwrev *
xsmmsg__msg__Hwrev__create();

/// Destroy msg/Hwrev message.
/**
 * It calls
 * xsmmsg__msg__Hwrev__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
void
xsmmsg__msg__Hwrev__destroy(xsmmsg__msg__Hwrev * msg);

/// Check for msg/Hwrev message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
bool
xsmmsg__msg__Hwrev__are_equal(const xsmmsg__msg__Hwrev * lhs, const xsmmsg__msg__Hwrev * rhs);

/// Copy a msg/Hwrev message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
bool
xsmmsg__msg__Hwrev__copy(
  const xsmmsg__msg__Hwrev * input,
  xsmmsg__msg__Hwrev * output);

/// Initialize array of msg/Hwrev messages.
/**
 * It allocates the memory for the number of elements and calls
 * xsmmsg__msg__Hwrev__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
bool
xsmmsg__msg__Hwrev__Sequence__init(xsmmsg__msg__Hwrev__Sequence * array, size_t size);

/// Finalize array of msg/Hwrev messages.
/**
 * It calls
 * xsmmsg__msg__Hwrev__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
void
xsmmsg__msg__Hwrev__Sequence__fini(xsmmsg__msg__Hwrev__Sequence * array);

/// Create array of msg/Hwrev messages.
/**
 * It allocates the memory for the array and calls
 * xsmmsg__msg__Hwrev__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
xsmmsg__msg__Hwrev__Sequence *
xsmmsg__msg__Hwrev__Sequence__create(size_t size);

/// Destroy array of msg/Hwrev messages.
/**
 * It calls
 * xsmmsg__msg__Hwrev__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
void
xsmmsg__msg__Hwrev__Sequence__destroy(xsmmsg__msg__Hwrev__Sequence * array);

/// Check for msg/Hwrev message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
bool
xsmmsg__msg__Hwrev__Sequence__are_equal(const xsmmsg__msg__Hwrev__Sequence * lhs, const xsmmsg__msg__Hwrev__Sequence * rhs);

/// Copy an array of msg/Hwrev messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsmmsg
bool
xsmmsg__msg__Hwrev__Sequence__copy(
  const xsmmsg__msg__Hwrev__Sequence * input,
  xsmmsg__msg__Hwrev__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XSMMSG__MSG__DETAIL__HWREV__FUNCTIONS_H_
