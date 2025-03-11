// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__FUNCTIONS_H_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mit_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "mit_msgs/msg/detail/mit_joint_command__struct.h"

/// Initialize msg/MITJointCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mit_msgs__msg__MITJointCommand
 * )) before or use
 * mit_msgs__msg__MITJointCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITJointCommand__init(mit_msgs__msg__MITJointCommand * msg);

/// Finalize msg/MITJointCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITJointCommand__fini(mit_msgs__msg__MITJointCommand * msg);

/// Create msg/MITJointCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mit_msgs__msg__MITJointCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
mit_msgs__msg__MITJointCommand *
mit_msgs__msg__MITJointCommand__create();

/// Destroy msg/MITJointCommand message.
/**
 * It calls
 * mit_msgs__msg__MITJointCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITJointCommand__destroy(mit_msgs__msg__MITJointCommand * msg);

/// Check for msg/MITJointCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITJointCommand__are_equal(const mit_msgs__msg__MITJointCommand * lhs, const mit_msgs__msg__MITJointCommand * rhs);

/// Copy a msg/MITJointCommand message.
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
mit_msgs__msg__MITJointCommand__copy(
  const mit_msgs__msg__MITJointCommand * input,
  mit_msgs__msg__MITJointCommand * output);

/// Initialize array of msg/MITJointCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * mit_msgs__msg__MITJointCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITJointCommand__Sequence__init(mit_msgs__msg__MITJointCommand__Sequence * array, size_t size);

/// Finalize array of msg/MITJointCommand messages.
/**
 * It calls
 * mit_msgs__msg__MITJointCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITJointCommand__Sequence__fini(mit_msgs__msg__MITJointCommand__Sequence * array);

/// Create array of msg/MITJointCommand messages.
/**
 * It allocates the memory for the array and calls
 * mit_msgs__msg__MITJointCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
mit_msgs__msg__MITJointCommand__Sequence *
mit_msgs__msg__MITJointCommand__Sequence__create(size_t size);

/// Destroy array of msg/MITJointCommand messages.
/**
 * It calls
 * mit_msgs__msg__MITJointCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
void
mit_msgs__msg__MITJointCommand__Sequence__destroy(mit_msgs__msg__MITJointCommand__Sequence * array);

/// Check for msg/MITJointCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mit_msgs
bool
mit_msgs__msg__MITJointCommand__Sequence__are_equal(const mit_msgs__msg__MITJointCommand__Sequence * lhs, const mit_msgs__msg__MITJointCommand__Sequence * rhs);

/// Copy an array of msg/MITJointCommand messages.
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
mit_msgs__msg__MITJointCommand__Sequence__copy(
  const mit_msgs__msg__MITJointCommand__Sequence * input,
  mit_msgs__msg__MITJointCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__FUNCTIONS_H_
