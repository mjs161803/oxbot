from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    #rplidar_node
    rplidar_channel_type =  LaunchConfiguration('rplidar_channel_type', default='serial')
    rplidar_serial_port = LaunchConfiguration('rplidar_serial_port', default='/dev/ttyUSB2')
    rplidar_serial_baudrate = LaunchConfiguration('rplidar_serial_baudrate', default='115200')
    rplidar_frame_id = LaunchConfiguration('rplidar_frame_id', default='laser')
    rplidar_inverted = LaunchConfiguration('rplidar_inverted', default='false')
    rplidar_angle_compensate = LaunchConfiguration('rplidar_angle_compensate', default='true')
    rplidar_scan_mode = LaunchConfiguration('rplidar_scan_mode', default='Sensitivity')
    #realsense_d455
    #oxbot_teleop
    #motion_control    

    return LaunchDescription([
        #rplidar_node
        DeclareLaunchArgument(
            'rplidar_channel_type',
            default_value=rplidar_channel_type,
            description='Specifying channel type of lidar'),
        DeclareLaunchArgument(
            'rplidar_serial_port',
            default_value=rplidar_serial_port,
            description='Specifying usb port to connected lidar'),
        DeclareLaunchArgument(
            'rplidar_serial_baudrate',
            default_value=rplidar_serial_baudrate,
            description='Specifying usb port baudrate to connected lidar'),
        DeclareLaunchArgument(
            'rplidar_frame_id',
            default_value=rplidar_frame_id,
            description='Specifying frame_id of lidar'),
        DeclareLaunchArgument(
            'rplidar_inverted',
            default_value=rplidar_inverted,
            description='Specifying whether or not to invert scan data'),
        DeclareLaunchArgument(
            'rplidar_angle_compensate',
            default_value=rplidar_angle_compensate,
            description='Specifying whether or not to enable angle_compensate of scan data'),
        DeclareLaunchArgument(
            'rplidar_scan_mode',
            default_value=rplidar_scan_mode,
            description='Specifying scan mode of lidar'),
        Node(
            package='rplidar_ros',
            executable='rplidar_node',
            name='rplidar_node',
            parameters=[{'channel_type':rplidar_channel_type,
                         'serial_port': rplidar_serial_port,
                         'serial_baudrate': rplidar_serial_baudrate,
                         'frame_id': rplidar_frame_id,
                         'inverted': rplidar_inverted,
                         'angle_compensate': rplidar_angle_compensate}]
        )
        #realsense_d455
        #oxbot_teleop
        #motion_control    

    ])
