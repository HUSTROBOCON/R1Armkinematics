// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsm_msg:msg/Hwrev.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__HWREV__BUILDER_HPP_
#define XSM_MSG__MSG__DETAIL__HWREV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xsm_msg/msg/detail/hwrev__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xsm_msg
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
  ::xsm_msg::msg::Hwrev tau(::xsm_msg::msg::Hwrev::_tau_type arg)
  {
    msg_.tau = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsm_msg::msg::Hwrev msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsm_msg::msg::Hwrev>()
{
  return xsm_msg::msg::builder::Init_Hwrev_tau();
}

}  // namespace xsm_msg

#endif  // XSM_MSG__MSG__DETAIL__HWREV__BUILDER_HPP_
