# generated from rosidl_generator_py/resource/_idl.py.em
# with input from telemetry_bridge:msg/LatencyStats.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LatencyStats(type):
    """Metaclass of message 'LatencyStats'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('telemetry_bridge')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'telemetry_bridge.msg.LatencyStats')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__latency_stats
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__latency_stats
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__latency_stats
            cls._TYPE_SUPPORT = module.type_support_msg__msg__latency_stats
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__latency_stats

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LatencyStats(metaclass=Metaclass_LatencyStats):
    """Message class 'LatencyStats'."""

    __slots__ = [
        '_header',
        '_mean_ms',
        '_p95_ms',
        '_p99_ms',
        '_max_ms',
        '_sequence_gap_count',
        '_stale_packet_count',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'mean_ms': 'double',
        'p95_ms': 'double',
        'p99_ms': 'double',
        'max_ms': 'double',
        'sequence_gap_count': 'uint64',
        'stale_packet_count': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.mean_ms = kwargs.get('mean_ms', float())
        self.p95_ms = kwargs.get('p95_ms', float())
        self.p99_ms = kwargs.get('p99_ms', float())
        self.max_ms = kwargs.get('max_ms', float())
        self.sequence_gap_count = kwargs.get('sequence_gap_count', int())
        self.stale_packet_count = kwargs.get('stale_packet_count', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.mean_ms != other.mean_ms:
            return False
        if self.p95_ms != other.p95_ms:
            return False
        if self.p99_ms != other.p99_ms:
            return False
        if self.max_ms != other.max_ms:
            return False
        if self.sequence_gap_count != other.sequence_gap_count:
            return False
        if self.stale_packet_count != other.stale_packet_count:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def mean_ms(self):
        """Message field 'mean_ms'."""
        return self._mean_ms

    @mean_ms.setter
    def mean_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mean_ms' field must be of type 'float'"
        self._mean_ms = value

    @property
    def p95_ms(self):
        """Message field 'p95_ms'."""
        return self._p95_ms

    @p95_ms.setter
    def p95_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p95_ms' field must be of type 'float'"
        self._p95_ms = value

    @property
    def p99_ms(self):
        """Message field 'p99_ms'."""
        return self._p99_ms

    @p99_ms.setter
    def p99_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p99_ms' field must be of type 'float'"
        self._p99_ms = value

    @property
    def max_ms(self):
        """Message field 'max_ms'."""
        return self._max_ms

    @max_ms.setter
    def max_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_ms' field must be of type 'float'"
        self._max_ms = value

    @property
    def sequence_gap_count(self):
        """Message field 'sequence_gap_count'."""
        return self._sequence_gap_count

    @sequence_gap_count.setter
    def sequence_gap_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sequence_gap_count' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'sequence_gap_count' field must be an unsigned integer in [0, 18446744073709551615]"
        self._sequence_gap_count = value

    @property
    def stale_packet_count(self):
        """Message field 'stale_packet_count'."""
        return self._stale_packet_count

    @stale_packet_count.setter
    def stale_packet_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stale_packet_count' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'stale_packet_count' field must be an unsigned integer in [0, 18446744073709551615]"
        self._stale_packet_count = value
