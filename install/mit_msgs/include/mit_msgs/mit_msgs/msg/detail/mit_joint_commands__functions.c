// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice
#include "mit_msgs/msg/detail/mit_joint_commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `commands`
#include "mit_msgs/msg/detail/mit_joint_command__functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
mit_msgs__msg__MITJointCommands__init(mit_msgs__msg__MITJointCommands * msg)
{
  if (!msg) {
    return false;
  }
  // commands
  if (!mit_msgs__msg__MITJointCommand__Sequence__init(&msg->commands, 0)) {
    mit_msgs__msg__MITJointCommands__fini(msg);
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    mit_msgs__msg__MITJointCommands__fini(msg);
    return false;
  }
  return true;
}

void
mit_msgs__msg__MITJointCommands__fini(mit_msgs__msg__MITJointCommands * msg)
{
  if (!msg) {
    return;
  }
  // commands
  mit_msgs__msg__MITJointCommand__Sequence__fini(&msg->commands);
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
mit_msgs__msg__MITJointCommands__are_equal(const mit_msgs__msg__MITJointCommands * lhs, const mit_msgs__msg__MITJointCommands * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // commands
  if (!mit_msgs__msg__MITJointCommand__Sequence__are_equal(
      &(lhs->commands), &(rhs->commands)))
  {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
mit_msgs__msg__MITJointCommands__copy(
  const mit_msgs__msg__MITJointCommands * input,
  mit_msgs__msg__MITJointCommands * output)
{
  if (!input || !output) {
    return false;
  }
  // commands
  if (!mit_msgs__msg__MITJointCommand__Sequence__copy(
      &(input->commands), &(output->commands)))
  {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

mit_msgs__msg__MITJointCommands *
mit_msgs__msg__MITJointCommands__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITJointCommands * msg = (mit_msgs__msg__MITJointCommands *)allocator.allocate(sizeof(mit_msgs__msg__MITJointCommands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mit_msgs__msg__MITJointCommands));
  bool success = mit_msgs__msg__MITJointCommands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mit_msgs__msg__MITJointCommands__destroy(mit_msgs__msg__MITJointCommands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mit_msgs__msg__MITJointCommands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mit_msgs__msg__MITJointCommands__Sequence__init(mit_msgs__msg__MITJointCommands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITJointCommands * data = NULL;

  if (size) {
    data = (mit_msgs__msg__MITJointCommands *)allocator.zero_allocate(size, sizeof(mit_msgs__msg__MITJointCommands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mit_msgs__msg__MITJointCommands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mit_msgs__msg__MITJointCommands__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mit_msgs__msg__MITJointCommands__Sequence__fini(mit_msgs__msg__MITJointCommands__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mit_msgs__msg__MITJointCommands__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mit_msgs__msg__MITJointCommands__Sequence *
mit_msgs__msg__MITJointCommands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITJointCommands__Sequence * array = (mit_msgs__msg__MITJointCommands__Sequence *)allocator.allocate(sizeof(mit_msgs__msg__MITJointCommands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mit_msgs__msg__MITJointCommands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mit_msgs__msg__MITJointCommands__Sequence__destroy(mit_msgs__msg__MITJointCommands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mit_msgs__msg__MITJointCommands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mit_msgs__msg__MITJointCommands__Sequence__are_equal(const mit_msgs__msg__MITJointCommands__Sequence * lhs, const mit_msgs__msg__MITJointCommands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mit_msgs__msg__MITJointCommands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mit_msgs__msg__MITJointCommands__Sequence__copy(
  const mit_msgs__msg__MITJointCommands__Sequence * input,
  mit_msgs__msg__MITJointCommands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mit_msgs__msg__MITJointCommands);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mit_msgs__msg__MITJointCommands * data =
      (mit_msgs__msg__MITJointCommands *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mit_msgs__msg__MITJointCommands__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mit_msgs__msg__MITJointCommands__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mit_msgs__msg__MITJointCommands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
