# generated from rosidl_generator_py/resource/_idl.py.em
# with input from oxbot_interfaces:msg/HoverboardCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HoverboardCommand(type):
    """Metaclass of message 'HoverboardCommand'."""

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
            module = import_type_support('oxbot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'oxbot_interfaces.msg.HoverboardCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hoverboard_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hoverboard_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hoverboard_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hoverboard_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hoverboard_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoverboardCommand(metaclass=Metaclass_HoverboardCommand):
    """Message class 'HoverboardCommand'."""

    __slots__ = [
        '_start_frame',
        '_steer_or_brake',
        '_speed_or_throttle',
        '_xor_checksum',
    ]

    _fields_and_field_types = {
        'start_frame': 'uint16',
        'steer_or_brake': 'int16',
        'speed_or_throttle': 'int16',
        'xor_checksum': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.start_frame = kwargs.get('start_frame', int())
        self.steer_or_brake = kwargs.get('steer_or_brake', int())
        self.speed_or_throttle = kwargs.get('speed_or_throttle', int())
        self.xor_checksum = kwargs.get('xor_checksum', int())

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
        if self.start_frame != other.start_frame:
            return False
        if self.steer_or_brake != other.steer_or_brake:
            return False
        if self.speed_or_throttle != other.speed_or_throttle:
            return False
        if self.xor_checksum != other.xor_checksum:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start_frame(self):
        """Message field 'start_frame'."""
        return self._start_frame

    @start_frame.setter
    def start_frame(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'start_frame' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'start_frame' field must be an unsigned integer in [0, 65535]"
        self._start_frame = value

    @builtins.property
    def steer_or_brake(self):
        """Message field 'steer_or_brake'."""
        return self._steer_or_brake

    @steer_or_brake.setter
    def steer_or_brake(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'steer_or_brake' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'steer_or_brake' field must be an integer in [-32768, 32767]"
        self._steer_or_brake = value

    @builtins.property
    def speed_or_throttle(self):
        """Message field 'speed_or_throttle'."""
        return self._speed_or_throttle

    @speed_or_throttle.setter
    def speed_or_throttle(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed_or_throttle' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'speed_or_throttle' field must be an integer in [-32768, 32767]"
        self._speed_or_throttle = value

    @builtins.property
    def xor_checksum(self):
        """Message field 'xor_checksum'."""
        return self._xor_checksum

    @xor_checksum.setter
    def xor_checksum(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xor_checksum' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'xor_checksum' field must be an unsigned integer in [0, 65535]"
        self._xor_checksum = value
