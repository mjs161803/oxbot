// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from oxbot_interfaces:msg/HoverboardFeedback.idl
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
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__struct.h"
#include "oxbot_interfaces/msg/detail/hoverboard_feedback__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool oxbot_interfaces__msg__hoverboard_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[61];
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
    assert(strncmp("oxbot_interfaces.msg._hoverboard_feedback.HoverboardFeedback", full_classname_dest, 60) == 0);
  }
  oxbot_interfaces__msg__HoverboardFeedback * ros_message = _ros_message;
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
  {  // right_wheel_rpm
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_wheel_rpm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_wheel_rpm = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_wheel_rpm
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_wheel_rpm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_wheel_rpm = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // batt_voltage_x100
    PyObject * field = PyObject_GetAttrString(_pymsg, "batt_voltage_x100");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->batt_voltage_x100 = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->temperature = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // led
    PyObject * field = PyObject_GetAttrString(_pymsg, "led");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->led = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // timestamp_ns
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp_ns");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp_ns = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // front_or_back
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_or_back");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->front_or_back, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * oxbot_interfaces__msg__hoverboard_feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HoverboardFeedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("oxbot_interfaces.msg._hoverboard_feedback");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HoverboardFeedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  oxbot_interfaces__msg__HoverboardFeedback * ros_message = (oxbot_interfaces__msg__HoverboardFeedback *)raw_ros_message;
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
  {  // right_wheel_rpm
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_wheel_rpm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_wheel_rpm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_wheel_rpm
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_wheel_rpm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_wheel_rpm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // batt_voltage_x100
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->batt_voltage_x100);
    {
      int rc = PyObject_SetAttrString(_pymessage, "batt_voltage_x100", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // led
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->led);
    {
      int rc = PyObject_SetAttrString(_pymessage, "led", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp_ns
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->timestamp_ns);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp_ns", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // front_or_back
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->front_or_back.data,
      strlen(ros_message->front_or_back.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_or_back", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
