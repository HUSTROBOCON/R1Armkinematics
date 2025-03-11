// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xsm_msg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__HWREV__FUNCTIONS_H_
#define XSM_MSG__MSG__DETAIL__HWREV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xsm_msg/msg/rosidl_generator_c__visibility_control.h"

#include "xsm_msg/msg/detail/hwrev__struct.h"

/// Initialize msg/Hwrev message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xsm_msg__msg__Hwrev
 * )) before or use
 * xsm_msg__msg__Hwrev__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
bool
xsm_msg__msg__Hwrev__init(xsm_msg__msg__Hwrev * msg);

/// Finalize msg/Hwrev message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
void
xsm_msg__msg__Hwrev__fini(xsm_msg__msg__Hwrev * msg);

/// Create msg/Hwrev message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xsm_msg__msg__Hwrev__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
xsm_msg__msg__Hwrev *
xsm_msg__msg__Hwrev__create();

/// Destroy msg/Hwrev message.
/**
 * It calls
 * xsm_msg__msg__Hwrev__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
void
xsm_msg__msg__Hwrev__destroy(xsm_msg__msg__Hwrev * msg);

/// Check for msg/Hwrev message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
bool
xsm_msg__msg__Hwrev__are_equal(const xsm_msg__msg__Hwrev * lhs, const xsm_msg__msg__Hwrev * rhs);

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
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
bool
xsm_msg__msg__Hwrev__copy(
  const xsm_msg__msg__Hwrev * input,
  xsm_msg__msg__Hwrev * output);

/// Initialize array of msg/Hwrev messages.
/**
 * It allocates the memory for the number of elements and calls
 * xsm_msg__msg__Hwrev__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
bool
xsm_msg__msg__Hwrev__Sequence__init(xsm_msg__msg__Hwrev__Sequence * array, size_t size);

/// Finalize array of msg/Hwrev messages.
/**
 * It calls
 * xsm_msg__msg__Hwrev__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
void
xsm_msg__msg__Hwrev__Sequence__fini(xsm_msg__msg__Hwrev__Sequence * array);

/// Create array of msg/Hwrev messages.
/**
 * It allocates the memory for the array and calls
 * xsm_msg__msg__Hwrev__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
xsm_msg__msg__Hwrev__Sequence *
xsm_msg__msg__Hwrev__Sequence__create(size_t size);

/// Destroy array of msg/Hwrev messages.
/**
 * It calls
 * xsm_msg__msg__Hwrev__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
void
xsm_msg__msg__Hwrev__Sequence__destroy(xsm_msg__msg__Hwrev__Sequence * array);

/// Check for msg/Hwrev message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
bool
xsm_msg__msg__Hwrev__Sequence__are_equal(const xsm_msg__msg__Hwrev__Sequence * lhs, const xsm_msg__msg__Hwrev__Sequence * rhs);

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
ROSIDL_GENERATOR_C_PUBLIC_xsm_msg
bool
xsm_msg__msg__Hwrev__Sequence__copy(
  const xsm_msg__msg__Hwrev__Sequence * input,
  xsm_msg__msg__Hwrev__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XSM_MSG__MSG__DETAIL__HWREV__FUNCTIONS_H_
