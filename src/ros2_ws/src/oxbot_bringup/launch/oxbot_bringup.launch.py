from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.conditions import UnlessCondition, IfCondition

def generate_launch_description():
    #rplidar_node
    rplidar_channel_type =  LaunchConfiguration('rplidar_channel_type')
    rplidar_channel_type_arg = DeclareLaunchArgument(
        'rplidar_channel_type',
        default_value='serial',
        description='Specifying channel type of lidar',
    )
    rplidar_serial_port = LaunchConfiguration('rplidar_serial_port')
    rplidar_serial_port_arg = DeclareLaunchArgument(
        'rplidar_serial_port',
        default_value='/dev/ttyUSB2',
        description='Specifying usb port to connected lidar',
    )
    rplidar_serial_baudrate = LaunchConfiguration('rplidar_serial_baudrate')
    rplidar_serial_baudrate_arg = DeclareLaunchArgument(
        'rplidar_serial_baudrate',
        default_value='115200',
        description='Specifying usb port baudrate to connected lidar'
    )
    rplidar_frame_id = LaunchConfiguration('rplidar_frame_id')
    rplidar_frame_id_arg = DeclareLaunchArgument(
        'rplidar_frame_id',
        default_value='laser',
        description='Specifying frame_id of lidar'
    )
    rplidar_inverted = LaunchConfiguration('rplidar_inverted')
    rplidar_inverted_arg = DeclareLaunchArgument(
        'rplidar_inverted',
        default_value='false',
        description='Specifying whether or not to invert scan data'
    )
    rplidar_angle_compensate = LaunchConfiguration('rplidar_angle_compensate')
    rplidar_angle_compensate_arg = DeclareLaunchArgument(
        'rplidar_angle_compensate',
        default_value='true',
        description='Specifying whether or not to enable angle_compensate of scan data'
    )
    rplidar_scan_mode = LaunchConfiguration('rplidar_scan_mode')
    rplidar_scan_mode_arg = DeclareLaunchArgument(
        'rplidar_scan_mode',
        default_value='Sensitivity',
        description='Specifying scan mode of lidar'
    )

    #realsense_d455
    #oxbot_teleop
    use_teleop_mode = LaunchConfiguration('use_teleop_mode')
    use_teleop_mode_arg = DeclareLaunchArgument(
        'use_teleop_mode',
        default_value='false',
        description='Specifying whether robot is using joystick for manual control. If false, robot is under autonomous control.',
    )
    #motion_control    
    teleoperated_oxbot = GroupAction(
        condition = IfCondition(use_teleop_mode),
        actions=[
            Node(
                package = 'motion_control',
                executable = 'oxbot_teleop'
            ),
            Node(
                package = 'motion_control',
                executable = 'motion_controller'
            ),
        ]
    )
    autonomous_oxbot = GroupAction(
        condition = UnlessCondition(use_teleop_mode),
            actions=[
                Node(
                    package = 'motion_control',
                    executable = 'motion_controller'
                ),
        ]
    )

    return LaunchDescription(
        [
            rplidar_channel_type_arg,
            rplidar_serial_port_arg,
            rplidar_serial_baudrate_arg,
            rplidar_frame_id_arg,
            rplidar_inverted_arg,
            rplidar_angle_compensate_arg,
            rplidar_scan_mode_arg,
            use_teleop_mode_arg,
            teleoperated_oxbot,
            autonomous_oxbot,
        ]
    )
