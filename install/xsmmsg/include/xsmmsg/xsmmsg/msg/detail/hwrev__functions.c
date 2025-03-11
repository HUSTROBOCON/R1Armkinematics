// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice
#include "xsmmsg/msg/detail/hwrev__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
xsmmsg__msg__Hwrev__init(xsmmsg__msg__Hwrev * msg)
{
  if (!msg) {
    return false;
  }
  // tau
  return true;
}

void
xsmmsg__msg__Hwrev__fini(xsmmsg__msg__Hwrev * msg)
{
  if (!msg) {
    return;
  }
  // tau
}

bool
xsmmsg__msg__Hwrev__are_equal(const xsmmsg__msg__Hwrev * lhs, const xsmmsg__msg__Hwrev * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tau
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->tau[i] != rhs->tau[i]) {
      return false;
    }
  }
  return true;
}

bool
xsmmsg__msg__Hwrev__copy(
  const xsmmsg__msg__Hwrev * input,
  xsmmsg__msg__Hwrev * output)
{
  if (!input || !output) {
    return false;
  }
  // tau
  for (size_t i = 0; i < 3; ++i) {
    output->tau[i] = input->tau[i];
  }
  return true;
}

xsmmsg__msg__Hwrev *
xsmmsg__msg__Hwrev__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsmmsg__msg__Hwrev * msg = (xsmmsg__msg__Hwrev *)allocator.allocate(sizeof(xsmmsg__msg__Hwrev), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsmmsg__msg__Hwrev));
  bool success = xsmmsg__msg__Hwrev__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xsmmsg__msg__Hwrev__destroy(xsmmsg__msg__Hwrev * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xsmmsg__msg__Hwrev__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xsmmsg__msg__Hwrev__Sequence__init(xsmmsg__msg__Hwrev__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsmmsg__msg__Hwrev * data = NULL;

  if (size) {
    data = (xsmmsg__msg__Hwrev *)allocator.zero_allocate(size, sizeof(xsmmsg__msg__Hwrev), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsmmsg__msg__Hwrev__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsmmsg__msg__Hwrev__fini(&data[i - 1]);
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
xsmmsg__msg__Hwrev__Sequence__fini(xsmmsg__msg__Hwrev__Sequence * array)
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
      xsmmsg__msg__Hwrev__fini(&array->data[i]);
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

xsmmsg__msg__Hwrev__Sequence *
xsmmsg__msg__Hwrev__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsmmsg__msg__Hwrev__Sequence * array = (xsmmsg__msg__Hwrev__Sequence *)allocator.allocate(sizeof(xsmmsg__msg__Hwrev__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xsmmsg__msg__Hwrev__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xsmmsg__msg__Hwrev__Sequence__destroy(xsmmsg__msg__Hwrev__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xsmmsg__msg__Hwrev__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xsmmsg__msg__Hwrev__Sequence__are_equal(const xsmmsg__msg__Hwrev__Sequence * lhs, const xsmmsg__msg__Hwrev__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xsmmsg__msg__Hwrev__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xsmmsg__msg__Hwrev__Sequence__copy(
  const xsmmsg__msg__Hwrev__Sequence * input,
  xsmmsg__msg__Hwrev__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xsmmsg__msg__Hwrev);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xsmmsg__msg__Hwrev * data =
      (xsmmsg__msg__Hwrev *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xsmmsg__msg__Hwrev__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xsmmsg__msg__Hwrev__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xsmmsg__msg__Hwrev__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
