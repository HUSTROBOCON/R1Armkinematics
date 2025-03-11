// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__FUNCTIONS_H_
#define MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mit_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "mit_msgs/msg/detail/mit_low_state__struct.h"

/// Initialize msg/MITLowState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mit_msgs__msg__MITLowState
 * )) before or use
 * mit_msgs__msg__MITLowState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITLowState__init(mit_msgs__msg__MITLowState * msg);

/// Finalize msg/MITLowState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITLowState__fini(mit_msgs__msg__MITLowState * msg);

/// Create msg/MITLowState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mit_msgs__msg__MITLowState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
mit_msgs__msg__MITLowState *
mit_msgs__msg__MITLowState__create();

/// Destroy msg/MITLowState message.
/**
 * It calls
 * mit_msgs__msg__MITLowState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITLowState__destroy(mit_msgs__msg__MITLowState * msg);

/// Check for msg/MITLowState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITLowState__are_equal(const mit_msgs__msg__MITLowState * lhs, const mit_msgs__msg__MITLowState * rhs);

/// Copy a msg/MITLowState message.
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
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITLowState__copy(
  const mit_msgs__msg__MITLowState * input,
  mit_msgs__msg__MITLowState * output);

/// Initialize array of msg/MITLowState messages.
/**
 * It allocates the memory for the number of elements and calls
 * mit_msgs__msg__MITLowState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITLowState__Sequence__init(mit_msgs__msg__MITLowState__Sequence * array, size_t size);

/// Finalize array of msg/MITLowState messages.
/**
 * It calls
 * mit_msgs__msg__MITLowState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITLowState__Sequence__fini(mit_msgs__msg__MITLowState__Sequence * array);

/// Create array of msg/MITLowState messages.
/**
 * It allocates the memory for the array and calls
 * mit_msgs__msg__MITLowState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
mit_msgs__msg__MITLowState__Sequence *
mit_msgs__msg__MITLowState__Sequence__create(size_t size);

/// Destroy array of msg/MITLowState messages.
/**
 * It calls
 * mit_msgs__msg__MITLowState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITLowState__Sequence__destroy(mit_msgs__msg__MITLowState__Sequence * array);

/// Check for msg/MITLowState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITLowState__Sequence__are_equal(const mit_msgs__msg__MITLowState__Sequence * lhs, const mit_msgs__msg__MITLowState__Sequence * rhs);

/// Copy an array of msg/MITLowState messages.
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
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITLowState__Sequence__copy(
  const mit_msgs__msg__MITLowState__Sequence * input,
  mit_msgs__msg__MITLowState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__FUNCTIONS_H_
