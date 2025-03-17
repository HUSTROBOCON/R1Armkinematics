// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice
#include "xsm_msg/msg/detail/path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
xsm_msg__msg__Path__init(xsm_msg__msg__Path * msg)
{
  if (!msg) {
    return false;
  }
  // rows
  // cols
  // data
  if (!rosidl_runtime_c__double__Sequence__init(&msg->data, 0)) {
    xsm_msg__msg__Path__fini(msg);
    return false;
  }
  return true;
}

void
xsm_msg__msg__Path__fini(xsm_msg__msg__Path * msg)
{
  if (!msg) {
    return;
  }
  // rows
  // cols
  // data
  rosidl_runtime_c__double__Sequence__fini(&msg->data);
}

bool
xsm_msg__msg__Path__are_equal(const xsm_msg__msg__Path * lhs, const xsm_msg__msg__Path * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rows
  if (lhs->rows != rhs->rows) {
    return false;
  }
  // cols
  if (lhs->cols != rhs->cols) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
xsm_msg__msg__Path__copy(
  const xsm_msg__msg__Path * input,
  xsm_msg__msg__Path * output)
{
  if (!input || !output) {
    return false;
  }
  // rows
  output->rows = input->rows;
  // cols
  output->cols = input->cols;
  // data
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

xsm_msg__msg__Path *
xsm_msg__msg__Path__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsm_msg__msg__Path * msg = (xsm_msg__msg__Path *)allocator.allocate(sizeof(xsm_msg__msg__Path), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsm_msg__msg__Path));
  bool success = xsm_msg__msg__Path__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xsm_msg__msg__Path__destroy(xsm_msg__msg__Path * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xsm_msg__msg__Path__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xsm_msg__msg__Path__Sequence__init(xsm_msg__msg__Path__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsm_msg__msg__Path * data = NULL;

  if (size) {
    data = (xsm_msg__msg__Path *)allocator.zero_allocate(size, sizeof(xsm_msg__msg__Path), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsm_msg__msg__Path__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsm_msg__msg__Path__fini(&data[i - 1]);
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
xsm_msg__msg__Path__Sequence__fini(xsm_msg__msg__Path__Sequence * array)
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
      xsm_msg__msg__Path__fini(&array->data[i]);
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

xsm_msg__msg__Path__Sequence *
xsm_msg__msg__Path__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsm_msg__msg__Path__Sequence * array = (xsm_msg__msg__Path__Sequence *)allocator.allocate(sizeof(xsm_msg__msg__Path__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xsm_msg__msg__Path__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xsm_msg__msg__Path__Sequence__destroy(xsm_msg__msg__Path__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xsm_msg__msg__Path__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xsm_msg__msg__Path__Sequence__are_equal(const xsm_msg__msg__Path__Sequence * lhs, const xsm_msg__msg__Path__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xsm_msg__msg__Path__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xsm_msg__msg__Path__Sequence__copy(
  const xsm_msg__msg__Path__Sequence * input,
  xsm_msg__msg__Path__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xsm_msg__msg__Path);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xsm_msg__msg__Path * data =
      (xsm_msg__msg__Path *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xsm_msg__msg__Path__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xsm_msg__msg__Path__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xsm_msg__msg__Path__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
