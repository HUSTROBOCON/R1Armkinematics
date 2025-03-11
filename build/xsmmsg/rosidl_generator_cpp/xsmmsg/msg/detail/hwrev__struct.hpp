// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSMMSG__MSG__DETAIL__HWREV__STRUCT_HPP_
#define XSMMSG__MSG__DETAIL__HWREV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xsmmsg__msg__Hwrev __attribute__((deprecated))
#else
# define DEPRECATED__xsmmsg__msg__Hwrev __declspec(deprecated)
#endif

namespace xsmmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Hwrev_
{
  using Type = Hwrev_<ContainerAllocator>;

  explicit Hwrev_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
    }
  }

  explicit Hwrev_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tau(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
    }
  }

  // field types and members
  using _tau_type =
    std::array<double, 3>;
  _tau_type tau;

  // setters for named parameter idiom
  Type & set__tau(
    const std::array<double, 3> & _arg)
  {
    this->tau = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsmmsg::msg::Hwrev_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsmmsg::msg::Hwrev_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsmmsg::msg::Hwrev_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsmmsg::msg::Hwrev_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsmmsg__msg__Hwrev
    std::shared_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsmmsg__msg__Hwrev
    std::shared_ptr<xsmmsg::msg::Hwrev_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hwrev_ & other) const
  {
    if (this->tau != other.tau) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hwrev_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hwrev_

// alias to use template instance with default allocator
using Hwrev =
  xsmmsg::msg::Hwrev_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsmmsg

#endif  // XSMMSG__MSG__DETAIL__HWREV__STRUCT_HPP_
