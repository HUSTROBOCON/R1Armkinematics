// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mit_msgs:msg/MITJointCommands.idl
// generated code does not contain a copyright notice

#ifndef MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__STRUCT_HPP_
#define MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'commands'
#include "mit_msgs/msg/detail/mit_joint_command__struct.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mit_msgs__msg__MITJointCommands __attribute__((deprecated))
#else
# define DEPRECATED__mit_msgs__msg__MITJointCommands __declspec(deprecated)
#endif

namespace mit_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MITJointCommands_
{
  using Type = MITJointCommands_<ContainerAllocator>;

  explicit MITJointCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    (void)_init;
  }

  explicit MITJointCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _commands_type =
    std::vector<mit_msgs::msg::MITJointCommand_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mit_msgs::msg::MITJointCommand_<ContainerAllocator>>>;
  _commands_type commands;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__commands(
    const std::vector<mit_msgs::msg::MITJointCommand_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mit_msgs::msg::MITJointCommand_<ContainerAllocator>>> & _arg)
  {
    this->commands = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mit_msgs::msg::MITJointCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const mit_msgs::msg::MITJointCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mit_msgs::msg::MITJointCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mit_msgs::msg::MITJointCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mit_msgs__msg__MITJointCommands
    std::shared_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mit_msgs__msg__MITJointCommands
    std::shared_ptr<mit_msgs::msg::MITJointCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MITJointCommands_ & other) const
  {
    if (this->commands != other.commands) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const MITJointCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MITJointCommands_

// alias to use template instance with default allocator
using MITJointCommands =
  mit_msgs::msg::MITJointCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mit_msgs

#endif  // MIT_MSGS__MSG__DETAIL__MIT_JOINT_COMMANDS__STRUCT_HPP_
