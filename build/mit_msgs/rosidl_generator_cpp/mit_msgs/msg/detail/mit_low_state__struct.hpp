// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mit_msgs:msg/MITLowState.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__STRUCT_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'imu'
#include "sensor_msgs/msg/detail/imu__struct.hpp"
// Member 'joint_states'
#include "sensor_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mit_msgs__msg__MITLowState __attribute__((deprecated))
#else
# define DEPRECATED__mit_msgs__msg__MITLowState __declspec(deprecated)
#endif

namespace mit_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MITLowState_
{
  using Type = MITLowState_<ContainerAllocator>;

  explicit MITLowState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init),
    imu(_init),
    joint_states(_init)
  {
    (void)_init;
  }

  explicit MITLowState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    imu(_alloc, _init),
    joint_states(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _imu_type =
    sensor_msgs::msg::Imu_<ContainerAllocator>;
  _imu_type imu;
  using _joint_states_type =
    sensor_msgs::msg::JointState_<ContainerAllocator>;
  _joint_states_type joint_states;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__imu(
    const sensor_msgs::msg::Imu_<ContainerAllocator> & _arg)
  {
    this->imu = _arg;
    return *this;
  }
  Type & set__joint_states(
    const sensor_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->joint_states = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mit_msgs::msg::MITLowState_<ContainerAllocator> *;
  using ConstRawPtr =
    const mit_msgs::msg::MITLowState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mit_msgs::msg::MITLowState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mit_msgs::msg::MITLowState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mit_msgs__msg__MITLowState
    std::shared_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mit_msgs__msg__MITLowState
    std::shared_ptr<mit_msgs::msg::MITLowState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MITLowState_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->imu != other.imu) {
      return false;
    }
    if (this->joint_states != other.joint_states) {
      return false;
    }
    return true;
  }
  bool operator!=(const MITLowState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MITLowState_

// alias to use template instance with default allocator
using MITLowState =
  mit_msgs::msg::MITLowState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mit_msgs

#endif  // MIT_MSGS__MSG__DETAIL__MIT_LOW_STATE__STRUCT_HPP_
