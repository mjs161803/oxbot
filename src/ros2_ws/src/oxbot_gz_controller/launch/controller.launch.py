import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    use_sim_time_arg = DeclareLaunchArgument(
        "use_sim_time",
        default_value="true"
    )

    wheel_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["simple_velocity_controller",
                "--controller-manager",
                "/controller_manager"
        ],
        parameters=[{"use_sim_time": LaunchConfiguration("use_sim_time")}]
    )

    gz_motion_controller = Node(
        package="oxbot_gz_controller",
        executable="gz_motion_controller",
        output="screen",
        parameters=[{"use_sim_time": LaunchConfiguration("use_sim_time")}]
    )

    joy_node = Node(
        package = 'joy',
        executable = 'joy_node',
        name="joystick",
        parameters=[
            os.path.join(get_package_share_directory("oxbot_gz_controller"), "config", "joy_config.yaml"),
            {"use_sim_time": LaunchConfiguration("use_sim_time")}
        ],
    )

    teleop_node = Node(
        package="oxbot_gz_controller",
        executable="oxbot_teleop_node",
        parameters=[{"use_sim_time": LaunchConfiguration("use_sim_time")}]
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
        parameters=[{"use_sim_time": LaunchConfiguration("use_sim_time")}]
    )
     
    return LaunchDescription([
        wheel_controller,
        gz_motion_controller,
        joy_node,
        teleop_node,
        joint_state_broadcaster_spawner
    ])