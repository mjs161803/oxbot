// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from oxbot_interfaces:msg/HoverboardCommand.idl
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
#include "oxbot_interfaces/msg/detail/hoverboard_command__struct.h"
#include "oxbot_interfaces/msg/detail/hoverboard_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool oxbot_interfaces__msg__hoverboard_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[59];
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
    assert(strncmp("oxbot_interfaces.msg._hoverboard_command.HoverboardCommand", full_classname_dest, 58) == 0);
  }
  oxbot_interfaces__msg__HoverboardCommand * ros_message = _ros_message;
  {  // start_frame
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_frame");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->start_frame = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // steer_or_brake
    PyObject * field = PyObject_GetAttrString(_pymsg, "steer_or_brake");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->steer_or_brake = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // speed_or_throttle
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_or_throttle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->speed_or_throttle = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // xor_checksum
    PyObject * field = PyObject_GetAttrString(_pymsg, "xor_checksum");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xor_checksum = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * oxbot_interfaces__msg__hoverboard_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HoverboardCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("oxbot_interfaces.msg._hoverboard_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HoverboardCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  oxbot_interfaces__msg__HoverboardCommand * ros_message = (oxbot_interfaces__msg__HoverboardCommand *)raw_ros_message;
  {  // start_frame
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->start_frame);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_frame", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steer_or_brake
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->steer_or_brake);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steer_or_brake", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_or_throttle
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->speed_or_throttle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_or_throttle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xor_checksum
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->xor_checksum);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xor_checksum", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
