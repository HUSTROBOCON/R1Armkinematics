// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice
#include "mit_msgs/msg/detail/mit_low_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `imu`
#include "sensor_msgs/msg/detail/imu__functions.h"
// Member `joint_states`
#include "sensor_msgs/msg/detail/joint_state__functions.h"

bool
mit_msgs__msg__MITLowState__init(mit_msgs__msg__MITLowState * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    mit_msgs__msg__MITLowState__fini(msg);
    return false;
  }
  // imu
  if (!sensor_msgs__msg__Imu__init(&msg->imu)) {
    mit_msgs__msg__MITLowState__fini(msg);
    return false;
  }
  // joint_states
  if (!sensor_msgs__msg__JointState__init(&msg->joint_states)) {
    mit_msgs__msg__MITLowState__fini(msg);
    return false;
  }
  return true;
}

void
mit_msgs__msg__MITLowState__fini(mit_msgs__msg__MITLowState * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // imu
  sensor_msgs__msg__Imu__fini(&msg->imu);
  // joint_states
  sensor_msgs__msg__JointState__fini(&msg->joint_states);
}

bool
mit_msgs__msg__MITLowState__are_equal(const mit_msgs__msg__MITLowState * lhs, const mit_msgs__msg__MITLowState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // imu
  if (!sensor_msgs__msg__Imu__are_equal(
      &(lhs->imu), &(rhs->imu)))
  {
    return false;
  }
  // joint_states
  if (!sensor_msgs__msg__JointState__are_equal(
      &(lhs->joint_states), &(rhs->joint_states)))
  {
    return false;
  }
  return true;
}

bool
mit_msgs__msg__MITLowState__copy(
  const mit_msgs__msg__MITLowState * input,
  mit_msgs__msg__MITLowState * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // imu
  if (!sensor_msgs__msg__Imu__copy(
      &(input->imu), &(output->imu)))
  {
    return false;
  }
  // joint_states
  if (!sensor_msgs__msg__JointState__copy(
      &(input->joint_states), &(output->joint_states)))
  {
    return false;
  }
  return true;
}

mit_msgs__msg__MITLowState *
mit_msgs__msg__MITLowState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITLowState * msg = (mit_msgs__msg__MITLowState *)allocator.allocate(sizeof(mit_msgs__msg__MITLowState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mit_msgs__msg__MITLowState));
  bool success = mit_msgs__msg__MITLowState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mit_msgs__msg__MITLowState__destroy(mit_msgs__msg__MITLowState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mit_msgs__msg__MITLowState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mit_msgs__msg__MITLowState__Sequence__init(mit_msgs__msg__MITLowState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITLowState * data = NULL;

  if (size) {
    data = (mit_msgs__msg__MITLowState *)allocator.zero_allocate(size, sizeof(mit_msgs__msg__MITLowState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mit_msgs__msg__MITLowState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mit_msgs__msg__MITLowState__fini(&data[i - 1]);
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
mit_msgs__msg__MITLowState__Sequence__fini(mit_msgs__msg__MITLowState__Sequence * array)
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
      mit_msgs__msg__MITLowState__fini(&array->data[i]);
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

mit_msgs__msg__MITLowState__Sequence *
mit_msgs__msg__MITLowState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mit_msgs__msg__MITLowState__Sequence * array = (mit_msgs__msg__MITLowState__Sequence *)allocator.allocate(sizeof(mit_msgs__msg__MITLowState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mit_msgs__msg__MITLowState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mit_msgs__msg__MITLowState__Sequence__destroy(mit_msgs__msg__MITLowState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mit_msgs__msg__MITLowState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mit_msgs__msg__MITLowState__Sequence__are_equal(const mit_msgs__msg__MITLowState__Sequence * lhs, const mit_msgs__msg__MITLowState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mit_msgs__msg__MITLowState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mit_msgs__msg__MITLowState__Sequence__copy(
  const mit_msgs__msg__MITLowState__Sequence * input,
  mit_msgs__msg__MITLowState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mit_msgs__msg__MITLowState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mit_msgs__msg__MITLowState * data =
      (mit_msgs__msg__MITLowState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mit_msgs__msg__MITLowState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mit_msgs__msg__MITLowState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mit_msgs__msg__MITLowState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
