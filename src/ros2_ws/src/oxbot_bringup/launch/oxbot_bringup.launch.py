from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, ExecuteProcess, RegisterEventHandler
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, FindExecutable
from launch.conditions import UnlessCondition, IfCondition
from launch.event_handlers import OnExecutionComplete

def generate_launch_description():
    #rplidar_node parameters
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
        default_value='lidar_link',
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

    #realsense_d455 parameters
    enable_color = LaunchConfiguration('enable_color')
    enable_color_arg = DeclareLaunchArgument(
        'enable_color',
        default_value='false'
        description='Enable/disable the RGB imager'
    )
    enable_infra = LaunchConfiguration('enable_infra')
    enable_infra_arg = DeclareLaunchArgument(
        'enable_infra',
        default_value='true',
        description('Enable/disable infrared imager')
    )
    enable_depth = LaunchConfiguration('enable_depth')
    enable_depth_arg = DeclareLaunchArgument(
        'enable_depth',
        default_value='true',
        description='Enable/disable depth module'
    )
    pointcloud_enable = LaunchConfiguration('pointcloud.enable')
    pointcloud_enable_arg = DeclareLaunchArgument(
        'pointcloud.enable',
        default_value='true'
        description='Enable/disable pointcloud messages from D455'
    )
    enable_gyro = LaunchConfiguration('enable_gyro')
    enable_gyro_arg = DeclareLaunchArgument(
        'enable_gyro',
        default_value='true',
        description='Enable/disable gyroscope sensor feed'
    )
    enable_accel = LaunchConfiguration('enable_accel')
    enable_accel_arg = DeclareLaunchArgument(
        'enable_accel',
        default_value='true',
        description='Enable/disable accelerometer sensor feed'
    )
    unite_imu_method = LaunchConfiguration('unite_imu_method')
    unite_imu_method_arg = DeclareLaunchArgument(
        'unite_imu_method',
        default_value='2',
        description='Specify if accel and gyro sensor readings to be combined into one sensor message'
    )
    publish_tf = LaunchConfiguration('publish_tf')
    publish_tf_arg = DeclareLaunchArgument(
        'publish_tf',
        default_value='true',
        description='Enable/disable publishing dynamic tf from D455'
    )
    tf_publish_rate = LaunchConfiguration('tf_publish_rate')
    tf_publish_rate_arg = DeclareLaunchArgument(
        'tf_publish_rate',
        default_value='10.0'
        description='Set publishing rate for tf messages from D455'
    )
    depth_profile = LaunchConfiguration('depth_module.depth_profile')
    depth_profile_arg = DeclareLaunchArgument(
        'depth_module.depth_profile',
        default_value='640x480x5',
        description='Specifying resolution of the depth module on the D455'
    )
    infra_profile = LaunchConfiguration('depth_module.infra_profile'),
    infra_profile_arg = DeclareLaunchArgument(
        'depth_module.infra_profile',
        default_value='640x480x5',
        description='Specifying resolution for infrared imager stream'
    )
    
    #oxbot_teleop parameters
    use_teleop_mode = LaunchConfiguration('use_teleop_mode')
    use_teleop_mode_arg = DeclareLaunchArgument(
        'use_teleop_mode',
        default_value='false',
        description='Specifying whether robot is using joystick for manual control. If false, robot is under autonomous control.',
    )

    #motion_control parameters

    # GROUP ACTIONS (TELEOP VS AUTONOMOUS)    
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
            Node(
                package = 'rplidar_ros',
                executable = 'rplidar_node',
                name='rplidar_node',
                parameters=[{'channel_type':rplidar_channel_type,
                    'serial_port': rplidar_serial_port,
                    'serial_baudrate': rplidar_serial_baudrate,
                    'frame_id': rplidar_frame_id,
                    'inverted': rplidar_inverted,
                    'angle_compensate': rplidar_angle_compensate}],
                output='screen',
            ),
            Node(
                package = 'realsense2_camera',
                executable = 'realsense2_camera',
                name='realsense_d455_node'
                parameters=[{'enable_color':enable_color,
                    'enable_infra': enable_infra,
                    'enable_depth': enable_depth,
                    'pointcloud.enable': pointcloud_enable,
                    'enable_accel': enable_accel,
                    'enable_gyro': enable_gyro,
                    'unite_imu_method': unite_imu_method,
                    'publish_tf': publish_tf,
                    'tf_publish_rate': tf_publish_rate,
                    'depth_module.depth_profile': depth_profile,
                    'depth_module.infra_profile': infra_profile}],
                output='screen',
            )
        ]
    )
    autonomous_oxbot = GroupAction(
        condition = UnlessCondition(use_teleop_mode),
        actions=[
            Node(
                package = 'motion_control',
                executable = 'motion_controller',
            ),
            Node(
                package = 'rplidar_ros',
                executable = 'rplidar_node',
                name='rplidar_node',
                parameters=[{'channel_type':rplidar_channel_type,
                    'serial_port': rplidar_serial_port,
                    'serial_baudrate': rplidar_serial_baudrate,
                    'frame_id': rplidar_frame_id,
                    'inverted': rplidar_inverted,
                    'angle_compensate': rplidar_angle_compensate}],
                output='screen',
            ),
            Node(
                package = 'realsense2_camera',
                executable = 'realsense2_camera',
                name='realsense_d455_node'
                parameters=[{'enable_color':enable_color,
                    'enable_infra': enable_infra,
                    'enable_depth': enable_depth,
                    'pointcloud.enable': pointcloud_enable,
                    'enable_accel': enable_accel,
                    'enable_gyro': enable_gyro,
                    'unite_imu_method': unite_imu_method,
                    'publish_tf': publish_tf,
                    'tf_publish_rate': tf_publish_rate,
                    'depth_module.depth_profile': depth_profile,
                    'depth_module.infra_profile': infra_profile}],
                output='screen',
            )
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
            enable_color_arg,
            enable_infra_arg,
            enable_depth_arg,
            pointcloud_enable_arg,
            enable_gyro_arg,
            enable_accel_arg,
            unite_imu_method_arg,
            publish_tf_arg,
            tf_publish_rate_arg,
            depth_profile_arg,
            infra_profile_arg,
            use_teleop_mode_arg,
            teleoperated_oxbot,
            autonomous_oxbot,
        ]
    )
