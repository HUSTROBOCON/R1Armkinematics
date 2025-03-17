// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsm_msg:msg/Path.idl
// generated code does not contain a copyright notice

#ifndef XSM_MSG__MSG__DETAIL__PATH__BUILDER_HPP_
#define XSM_MSG__MSG__DETAIL__PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xsm_msg/msg/detail/path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xsm_msg
{

namespace msg
{

namespace builder
{

class Init_Path_data
{
public:
  explicit Init_Path_data(::xsm_msg::msg::Path & msg)
  : msg_(msg)
  {}
  ::xsm_msg::msg::Path data(::xsm_msg::msg::Path::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsm_msg::msg::Path msg_;
};

class Init_Path_cols
{
public:
  explicit Init_Path_cols(::xsm_msg::msg::Path & msg)
  : msg_(msg)
  {}
  Init_Path_data cols(::xsm_msg::msg::Path::_cols_type arg)
  {
    msg_.cols = std::move(arg);
    return Init_Path_data(msg_);
  }

private:
  ::xsm_msg::msg::Path msg_;
};

class Init_Path_rows
{
public:
  Init_Path_rows()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Path_cols rows(::xsm_msg::msg::Path::_rows_type arg)
  {
    msg_.rows = std::move(arg);
    return Init_Path_cols(msg_);
  }

private:
  ::xsm_msg::msg::Path msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsm_msg::msg::Path>()
{
  return xsm_msg::msg::builder::Init_Path_rows();
}

}  // namespace xsm_msg

#endif  // XSM_MSG__MSG__DETAIL__PATH__BUILDER_HPP_
