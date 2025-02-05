import os
from os import pathsep
from pathlib import Path 
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription
from launch.substitutions import Command, LaunchConfiguration, PathJoinSubstitution, PythonExpression
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():
    oxbot_description_dir = get_package_share_directory("oxbot_description")
    
    model_arg = DeclareLaunchArgument(
        name="model", 
        default_value=os.path.join(oxbot_description_dir, "urdf", "oxbot.urdf.xacro"),
        description="Absolute path to robot urdf file"
    )
    
    world_name_arg = DeclareLaunchArgument(name="world_name", default_value="empty")

    world_path = PathJoinSubstitution([
            oxbot_description_dir,
            "worlds",
            PythonExpression(expression=["'", LaunchConfiguration("world_name"), "'", " + '.world'"])
        ]
    )

    model_path = str(Path(oxbot_description_dir).parent.resolve())
    model_path += pathsep + os.path.join(get_package_share_directory("oxbot_description"), 'models')

    gazebo_resource_path = SetEnvironmentVariable(
        "GZ_SIM_RESOURCE_PATH",
        model_path
        )
    
    ros_distro = os.environ["ROS_DISTRO"]
    is_ignition = "True" if ros_distro == "humble" else "False"
    
    robot_description = ParameterValue(
        Command([
            "xacro ", 
            LaunchConfiguration("model"),
            " is_ignition:=",
            is_ignition
        ]), 
        value_type=str
    )
    
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description,
                     "use_sim_time": True}]
    )
        
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(get_package_share_directory("ros_gz_sim"), "launch"),
            "/gz_sim.launch.py"
        ]),
        launch_arguments={
            "gz_args": PythonExpression(["'", world_path, " -v 4 -r'"])
        }.items()
    )
    
    gz_spawn_entity = Node(
        package="ros_gz_sim",
        executable="create",
        output="screen",
        arguments=["-topic", "robot_description", "-name", "oxbot"]
    )

    # joint_state_broadcaster_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=[
    #         "joint_state_broadcaster",
    #         "--controller-manager",
    #         "/controller_manager",
    #     ],
    # )

    # wheel_controller = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["simple_velocity_controller",
    #             "--controller-manager",
    #             "/controller_manager"
    #     ]
    # )

    gz_motion_controller = Node(
        package="oxbot_gz_controller",
        executable="gz_motion_controller",
        output="screen"
    )

    joy_node = Node(
        package = 'joy',
        executable = 'joy_node',
        name="joystick",
        parameters=[os.path.join(get_package_share_directory("oxbot_bringup"), "config", "joy_config.yaml")],
    )

    rviz_node = Node(
        package = 'rviz2',
        executable = 'rviz2',
        name='rviz2',
        output='screen',
        arguments=["-d", os.path.join(oxbot_description_dir, "rviz", "rvizconfig2.rviz")]
    )

    teleop_node = Node(
        package="oxbot_gz_controller",
        executable="oxbot_teleop_node"
    )

    gz_ros2_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            "/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock",
            "imu@sensor_msgs/msg/Imu[gz.msgs.IMU",
            "/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan"
        ],
        remappings=[
            ('/imu', '/realsense/camera/imu'),
        ]
    )
    
    return LaunchDescription([
        model_arg,
        world_name_arg,
        robot_state_publisher_node,
        gazebo_resource_path,
        gazebo,
        gz_spawn_entity,
        gz_ros2_bridge,
        # joint_state_broadcaster_spawner,
        # wheel_controller,
        gz_motion_controller,
        joy_node,
        rviz_node,
        teleop_node
    ])
    
# be sure to update package.xml for oxbot_bringup: <exec_depend>ros_gz_sim</exec_depend>