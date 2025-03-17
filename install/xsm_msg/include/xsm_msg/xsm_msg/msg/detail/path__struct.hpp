// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__PATH__STRUCT_HPP_
#define XSM_MSG__MSG__DETAIL__PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xsm_msg__msg__Path __attribute__((deprecated))
#else
# define DEPRECATED__xsm_msg__msg__Path __declspec(deprecated)
#endif

namespace xsm_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Path_
{
  using Type = Path_<ContainerAllocator>;

  explicit Path_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rows = 0l;
      this->cols = 0l;
    }
  }

  explicit Path_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rows = 0l;
      this->cols = 0l;
    }
  }

  // field types and members
  using _rows_type =
    int32_t;
  _rows_type rows;
  using _cols_type =
    int32_t;
  _cols_type cols;
  using _data_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__rows(
    const int32_t & _arg)
  {
    this->rows = _arg;
    return *this;
  }
  Type & set__cols(
    const int32_t & _arg)
  {
    this->cols = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsm_msg::msg::Path_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsm_msg::msg::Path_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsm_msg::msg::Path_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsm_msg::msg::Path_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsm_msg::msg::Path_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsm_msg::msg::Path_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsm_msg::msg::Path_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsm_msg::msg::Path_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsm_msg::msg::Path_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsm_msg::msg::Path_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsm_msg__msg__Path
    std::shared_ptr<xsm_msg::msg::Path_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsm_msg__msg__Path
    std::shared_ptr<xsm_msg::msg::Path_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Path_ & other) const
  {
    if (this->rows != other.rows) {
      return false;
    }
    if (this->cols != other.cols) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Path_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Path_

// alias to use template instance with default allocator
using Path =
  xsm_msg::msg::Path_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsm_msg

#endif  // XSM_MSG__MSG__DETAIL__PATH__STRUCT_HPP_
