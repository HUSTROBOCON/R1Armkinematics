// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsmmsg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSMMSG__MSG__DETAIL__HWREV__BUILDER_HPP_
#define XSMMSG__MSG__DETAIL__HWREV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xsmmsg/msg/detail/hwrev__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xsmmsg
{

namespace msg
{

namespace builder
{

class Init_Hwrev_tau
{
public:
  Init_Hwrev_tau()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::xsmmsg::msg::Hwrev tau(::xsmmsg::msg::Hwrev::_tau_type arg)
  {
    msg_.tau = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsmmsg::msg::Hwrev msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsmmsg::msg::Hwrev>()
{
  return xsmmsg::msg::builder::Init_Hwrev_tau();
}

}  // namespace xsmmsg

#endif  // XSMMSG__MSG__DETAIL__HWREV__BUILDER_HPP_
