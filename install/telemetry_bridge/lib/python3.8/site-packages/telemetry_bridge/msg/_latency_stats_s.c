// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from telemetry_bridge:msg/LatencyStats.idl
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
#include "telemetry_bridge/msg/detail/latency_stats__struct.h"
#include "telemetry_bridge/msg/detail/latency_stats__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool telemetry_bridge__msg__latency_stats__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("telemetry_bridge.msg._latency_stats.LatencyStats", full_classname_dest, 48) == 0);
  }
  telemetry_bridge__msg__LatencyStats * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // mean_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mean_ms = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p95_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "p95_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p95_ms = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p99_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "p99_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p99_ms = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_ms = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // sequence_gap_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "sequence_gap_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sequence_gap_count = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // stale_packet_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "stale_packet_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->stale_packet_count = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * telemetry_bridge__msg__latency_stats__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LatencyStats */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("telemetry_bridge.msg._latency_stats");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LatencyStats");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  telemetry_bridge__msg__LatencyStats * ros_message = (telemetry_bridge__msg__LatencyStats *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mean_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mean_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p95_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p95_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p95_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p99_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p99_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p99_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sequence_gap_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->sequence_gap_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sequence_gap_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stale_packet_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->stale_packet_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stale_packet_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
