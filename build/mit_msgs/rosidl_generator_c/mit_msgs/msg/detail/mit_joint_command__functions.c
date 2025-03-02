// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice
#include "mit_msgs/msg/detail/mit_joint_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mit_msgs__msg__MITJointCommand__init(mit_msgs__msg__MITJointCommand * msg)
{
  if (!msg) {
    return false;
  }
  // kp
  // kd
  // pos
  // vel
  // eff
  return true;
}

void
mit_msgs__msg__MITJointCommand__fini(mit_msgs__msg__MITJointCommand * msg)
{
  if (!msg) {
    return;
  }
  // kp
  // kd
  // pos
  // vel
  // eff
}

bool
mit_msgs__msg__MITJointCommand__are_equal(const mit_msgs__msg__MITJointCommand * lhs, const mit_msgs__msg__MITJointCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // kp
  if (lhs->kp != rhs->kp) {
    return false;
  }
  // kd
  if (lhs->kd != rhs->kd) {
    return false;
  }
  // pos
  if (lhs->pos != rhs->pos) {
    return false;
  }
  // vel
  if (lhs->vel != rhs->vel) {
    return false;
  }
  // eff
  if (lhs->eff != rhs->eff) {
    return false;
  }
  return true;
}

bool
mit_msgs__msg__MITJointCommand__copy(
  const mit_msgs__msg__MITJointCommand * input,
  mit_msgs__msg__MITJointCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // kp
  output->kp = input->kp;
  // kd
  output->kd = input->kd;
  // pos
  output->pos = input->pos;
  // vel
  output->vel = input->vel;
  // eff
  output->eff = input->eff;
  return true;
}

mit_msgs__msg__MITJointCommand *
mit_msgs__msg__MITJointCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITJointCommand * msg = (mit_msgs__msg__MITJointCommand *)allocator.allocate(sizeof(mit_msgs__msg__MITJointCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mit_msgs__msg__MITJointCommand));
  bool success = mit_msgs__msg__MITJointCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mit_msgs__msg__MITJointCommand__destroy(mit_msgs__msg__MITJointCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mit_msgs__msg__MITJointCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mit_msgs__msg__MITJointCommand__Sequence__init(mit_msgs__msg__MITJointCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITJointCommand * data = NULL;

  if (size) {
    data = (mit_msgs__msg__MITJointCommand *)allocator.zero_allocate(size, sizeof(mit_msgs__msg__MITJointCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mit_msgs__msg__MITJointCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mit_msgs__msg__MITJointCommand__fini(&data[i - 1]);
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
mit_msgs__msg__MITJointCommand__Sequence__fini(mit_msgs__msg__MITJointCommand__Sequence * array)
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
      mit_msgs__msg__MITJointCommand__fini(&array->data[i]);
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

mit_msgs__msg__MITJointCommand__Sequence *
mit_msgs__msg__MITJointCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITJointCommand__Sequence * array = (mit_msgs__msg__MITJointCommand__Sequence *)allocator.allocate(sizeof(mit_msgs__msg__MITJointCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mit_msgs__msg__MITJointCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mit_msgs__msg__MITJointCommand__Sequence__destroy(mit_msgs__msg__MITJointCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mit_msgs__msg__MITJointCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mit_msgs__msg__MITJointCommand__Sequence__are_equal(const mit_msgs__msg__MITJointCommand__Sequence * lhs, const mit_msgs__msg__MITJointCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mit_msgs__msg__MITJointCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mit_msgs__msg__MITJointCommand__Sequence__copy(
  const mit_msgs__msg__MITJointCommand__Sequence * input,
  mit_msgs__msg__MITJointCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mit_msgs__msg__MITJointCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mit_msgs__msg__MITJointCommand * data =
      (mit_msgs__msg__MITJointCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mit_msgs__msg__MITJointCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mit_msgs__msg__MITJointCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mit_msgs__msg__MITJointCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
