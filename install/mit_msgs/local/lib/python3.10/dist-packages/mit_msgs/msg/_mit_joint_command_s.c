// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mit_msgs:msg/MITJointCommand.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mit_msgs/msg/detail/mit_joint_command__struct.h"
#include "mit_msgs/msg/detail/mit_joint_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mit_msgs__msg__mit_joint_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mit_msgs.msg._mit_joint_command.MITJointCommand", full_classname_dest, 47) == 0);
  }
  mit_msgs__msg__MITJointCommand * ros_message = _ros_message;
  {  // kp
    PyObject * field = PyObject_GetAttrString(_pymsg, "kp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->kp = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // kd
    PyObject * field = PyObject_GetAttrString(_pymsg, "kd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->kd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // eff
    PyObject * field = PyObject_GetAttrString(_pymsg, "eff");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->eff = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mit_msgs__msg__mit_joint_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MITJointCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mit_msgs.msg._mit_joint_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MITJointCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mit_msgs__msg__MITJointCommand * ros_message = (mit_msgs__msg__MITJointCommand *)raw_ros_message;
  {  // kp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->kp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "kp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // kd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->kd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "kd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eff
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->eff);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eff", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
