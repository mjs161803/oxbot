from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, ExecuteProcess, RegisterEventHandler, OpaqueFunction
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, FindExecutable
from launch.conditions import UnlessCondition, IfCondition
from launch.event_handlers import OnExecutionComplete

realsense_configurable_parameters = [{'name': 'camera_name',        'default': 'camera', 'description': 'camera unique name'},
                           {'name': 'camera_namespace',             'default': 'realsense', 'description': 'namespace for camera'},
                           {'name': 'serial_no',                    'default': "''", 'description': 'choose device by serial number'},
                           {'name': 'usb_port_id',                  'default': "''", 'description': 'choose device by usb port id'},
                           {'name': 'device_type',                  'default': "''", 'description': 'choose device by type'},
                           {'name': 'config_file',                  'default': "''", 'description': 'yaml config file'},
                           {'name': 'json_file_path',               'default': "''", 'description': 'allows advanced configuration'},
                           {'name': 'initial_reset',                'default': 'false', 'description': "''"},
                           {'name': 'accelerate_gpu_with_glsl',     'default': "false", 'description': 'enable GPU acceleration with GLSL'},
                           {'name': 'rosbag_filename',              'default': "''", 'description': 'A realsense bagfile to run from as a device'},
                           {'name': 'log_level',                    'default': 'info', 'description': 'debug log level [DEBUG|INFO|WARN|ERROR|FATAL]'},
                           {'name': 'output',                       'default': 'screen', 'description': 'pipe node output [screen|log]'},
                           {'name': 'enable_color',                 'default': 'true', 'description': 'enable color stream'},
                           {'name': 'color_qos',                    'default': 'DEFAULT', 'description': 'QOS profile for stream'},
                           {'name': 'depth_qos',                    'default': 'DEFAULT', 'description': 'QOS profile for stream'},
                           {'name': 'infra_qos',                    'default': 'DEFAULT', 'description': 'QOS profile for stream'},
                           {'name': 'gyro_qos',                     'default': 'DEFAULT', 'description': 'QOS profile for stream'},
                           {'name': 'accel_qos',                    'default': 'DEFAULT', 'description': 'QOS profile for stream'},
                           {'name': 'pointcloud.pointcloud_qos',    'default': 'DEFAULT', 'description': 'QOS profile for stream'},
                           {'name': 'rgb_camera.color_profile',     'default': '0,0,0', 'description': 'color stream profile'},
                           {'name': 'rgb_camera.color_format',      'default': 'RGB8', 'description': 'color stream format'},
                           {'name': 'rgb_camera.enable_auto_exposure', 'default': 'true', 'description': 'enable/disable auto exposure for color image'},
                           {'name': 'enable_depth',                 'default': 'true', 'description': 'enable depth stream'},
                           {'name': 'enable_infra',                 'default': 'false', 'description': 'enable infra0 stream'},
                           {'name': 'enable_infra1',                'default': 'false', 'description': 'enable infra1 stream'},
                           {'name': 'enable_infra2',                'default': 'false', 'description': 'enable infra2 stream'},
                           {'name': 'depth_module.depth_profile',   'default': '0,0,0', 'description': 'depth stream profile'},
                           {'name': 'depth_module.depth_format',    'default': 'Z16', 'description': 'depth stream format'},
                           {'name': 'depth_module.infra_profile',   'default': '0,0,0', 'description': 'infra streams (0/1/2) profile'},
                           {'name': 'depth_module.infra_format',    'default': 'RGB8', 'description': 'infra0 stream format'},
                           {'name': 'depth_module.infra1_format',   'default': 'Y8', 'description': 'infra1 stream format'},
                           {'name': 'depth_module.infra2_format',   'default': 'Y8', 'description': 'infra2 stream format'},
                           {'name': 'depth_module.exposure',        'default': '8500', 'description': 'Depth module manual exposure value'},
                           {'name': 'depth_module.gain',            'default': '16', 'description': 'Depth module manual gain value'},
                           {'name': 'depth_module.hdr_enabled',     'default': 'false', 'description': 'Depth module hdr enablement flag. Used for hdr_merge filter'},
                           {'name': 'depth_module.enable_auto_exposure', 'default': 'true', 'description': 'enable/disable auto exposure for depth image'},
                           {'name': 'depth_module.exposure.1',      'default': '7500', 'description': 'Depth module first exposure value. Used for hdr_merge filter'},
                           {'name': 'depth_module.gain.1',          'default': '16', 'description': 'Depth module first gain value. Used for hdr_merge filter'},
                           {'name': 'depth_module.exposure.2',      'default': '1', 'description': 'Depth module second exposure value. Used for hdr_merge filter'},
                           {'name': 'depth_module.gain.2',          'default': '16', 'description': 'Depth module second gain value. Used for hdr_merge filter'},
                           {'name': 'enable_sync',                  'default': 'false', 'description': "'enable sync mode'"},
                           {'name': 'enable_rgbd',                  'default': 'false', 'description': "'enable rgbd topic'"},
                           {'name': 'enable_gyro',                  'default': 'true', 'description': "'enable gyro stream'"},
                           {'name': 'enable_accel',                 'default': 'true', 'description': "'enable accel stream'"},
                           {'name': 'gyro_fps',                     'default': '0', 'description': "''"},
                           {'name': 'accel_fps',                    'default': '0', 'description': "''"},
                           {'name': 'unite_imu_method',             'default': "2", 'description': '[0-None, 1-copy, 2-linear_interpolation]'},
                           {'name': 'clip_distance',                'default': '-2.', 'description': "''"},
                           {'name': 'angular_velocity_cov',         'default': '0.01', 'description': "''"},
                           {'name': 'linear_accel_cov',             'default': '0.01', 'description': "''"},
                           {'name': 'diagnostics_period',           'default': '0.0', 'description': 'Rate of publishing diagnostics. 0=Disabled'},
                           {'name': 'publish_tf',                   'default': 'true', 'description': '[bool] enable/disable publishing static & dynamic TF'},
                           {'name': 'tf_publish_rate',              'default': '10.0', 'description': '[double] rate in Hz for publishing dynamic TF'},
                           {'name': 'pointcloud.enable',            'default': 'true', 'description': ''},
                           {'name': 'pointcloud.stream_filter',     'default': '0', 'description': 'texture stream for pointcloud'},
                           {'name': 'pointcloud.stream_index_filter','default': '0', 'description': 'texture stream index for pointcloud'},
                           {'name': 'pointcloud.ordered_pc',        'default': 'false', 'description': ''},
                           {'name': 'pointcloud.allow_no_texture_points', 'default': 'false', 'description': "''"},
                           {'name': 'align_depth.enable',           'default': 'false', 'description': 'enable align depth filter'},
                           {'name': 'colorizer.enable',             'default': 'false', 'description': 'enable colorizer filter'},
                           {'name': 'decimation_filter.enable',     'default': 'false', 'description': 'enable_decimation_filter'},
                           {'name': 'spatial_filter.enable',        'default': 'false', 'description': 'enable_spatial_filter'},
                           {'name': 'temporal_filter.enable',       'default': 'false', 'description': 'enable_temporal_filter'},
                           {'name': 'disparity_filter.enable',      'default': 'false', 'description': 'enable_disparity_filter'},
                           {'name': 'hole_filling_filter.enable',   'default': 'false', 'description': 'enable_hole_filling_filter'},
                           {'name': 'hdr_merge.enable',             'default': 'false', 'description': 'hdr_merge filter enablement flag'},
                           {'name': 'wait_for_device_timeout',      'default': '-1.', 'description': 'Timeout for waiting for device to connect (Seconds)'},
                           {'name': 'reconnect_timeout',            'default': '6.', 'description': 'Timeout(seconds) between consequtive reconnection attempts'},
                          ]


def declare_realsense_configurable_parameters(parameters):
    return [DeclareLaunchArgument(param['name'], default_value=param['default'], description=param['description']) for param in parameters]

def set_realsense_configurable_parameters(parameters):
    return dict([(param['name'], LaunchConfiguration(param['name'])) for param in parameters])

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
    
    # Realsense parameters
    rs_param_launch_configs = set_realsense_configurable_parameters(realsense_configurable_parameters) # dictionary where key=parameter name, and value=LaunchConfiguration object
    rs_param_args = declare_realsense_configurable_parameters(realsense_configurable_parameters) # list of DeclareLaunchArgument objects
    
    #oxbot_teleop parameters
    use_teleop_mode = LaunchConfiguration('use_teleop_mode')
    use_teleop_mode_arg = DeclareLaunchArgument(
        'use_teleop_mode',
        default_value='false',
        description='Specifying whether robot is using joystick for manual control. If false, robot is under autonomous control.',
    )

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
                package='realsense2_camera',
                executable='realsense2_camera_node',
                namespace=rs_param_launch_configs['camera_namespace'],   #LaunchConfiguration('camera_namespace'),
                name=rs_param_launch_configs['camera_name'],  #LaunchConfiguration('camera_name' + param_name_suffix),
                parameters=[rs_param_launch_configs], # a list of a single dictionary, with each dictionary entry having key=param name, and value=LaunchConfiguration object
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
                package='realsense2_camera',
                executable='realsense2_camera_node',
                namespace=rs_param_launch_configs['camera_namespace'],   #LaunchConfiguration('camera_namespace'),
                name=rs_param_launch_configs['camera_name'],  #LaunchConfiguration('camera_name' + param_name_suffix),
                parameters=[rs_param_launch_configs], # a list of a single dictionary, with each dictionary entry having key=param name, and value=LaunchConfiguration object
                output='screen',
            ),
        ]
    )

    return LaunchDescription(
        rs_param_args +
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
