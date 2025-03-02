// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__STRUCT_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mit_msgs__msg__MITJointCommand __attribute__((deprecated))
#else
# define DEPRECATED__mit_msgs__msg__MITJointCommand __declspec(deprecated)
#endif

namespace mit_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MITJointCommand_
{
  using Type = MITJointCommand_<ContainerAllocator>;

  explicit MITJointCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->kp = 0.0f;
      this->kd = 0.0f;
      this->pos = 0.0f;
      this->vel = 0.0f;
      this->eff = 0.0f;
    }
  }

  explicit MITJointCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->kp = 0.0f;
      this->kd = 0.0f;
      this->pos = 0.0f;
      this->vel = 0.0f;
      this->eff = 0.0f;
    }
  }

  // field types and members
  using _kp_type =
    float;
  _kp_type kp;
  using _kd_type =
    float;
  _kd_type kd;
  using _pos_type =
    float;
  _pos_type pos;
  using _vel_type =
    float;
  _vel_type vel;
  using _eff_type =
    float;
  _eff_type eff;

  // setters for named parameter idiom
  Type & set__kp(
    const float & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const float & _arg)
  {
    this->kd = _arg;
    return *this;
  }
  Type & set__pos(
    const float & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__vel(
    const float & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__eff(
    const float & _arg)
  {
    this->eff = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mit_msgs::msg::MITJointCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const mit_msgs::msg::MITJointCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mit_msgs::msg::MITJointCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mit_msgs::msg::MITJointCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mit_msgs__msg__MITJointCommand
    std::shared_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mit_msgs__msg__MITJointCommand
    std::shared_ptr<mit_msgs::msg::MITJointCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MITJointCommand_ & other) const
  {
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    if (this->eff != other.eff) {
      return false;
    }
    return true;
  }
  bool operator!=(const MITJointCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MITJointCommand_

// alias to use template instance with default allocator
using MITJointCommand =
  mit_msgs::msg::MITJointCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mit_msgs

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMAND__STRUCT_HPP_
