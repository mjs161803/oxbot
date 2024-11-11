import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import LaunchConfiguration, Command
from launch.conditions import UnlessCondition, IfCondition
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    oxbot_description_path = get_package_share_directory("oxbot_description")
    urdf_path = os.path.join(oxbot_description_path, "urdf", "oxbot.urdf.xacro")

    model_arg = DeclareLaunchArgument(
        name="model",
        default_value=urdf_path,
        description="Absolute path to oxbot URDF file",          
    )
    
    robot_description = ParameterValue(Command(["xacro ", LaunchConfiguration("model")]), value_type=str)

    use_teleop_mode = LaunchConfiguration('use_teleop_mode')
    use_teleop_mode_arg = DeclareLaunchArgument(
        'use_teleop_mode',
        default_value='False',
        description='Specifying whether robot is using joystick for manual control. If false, robot is under autonomous control.',
    )

    #joy_node and rviz     
    teleoperated_oxbot = GroupAction(
        condition = IfCondition(use_teleop_mode),
        actions=[
            Node(
                package = 'joy',
                executable = 'joy_node',
                name="joystick",
                parameters=[os.path.join(get_package_share_directory("oxbot_bringup"), "config", "joy_config.yaml")],
            ),
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                parameters=[{"robot_description": robot_description}]
            ),
            Node(
                package = 'rviz2',
                executable = 'rviz2',
                name='rviz2',
                output='screen',
                arguments=['-d' + os.path.join(get_package_share_directory('oxbot_bringup'), 'config', 'config.rviz')]
            ),
        ]
    )
    autonomous_oxbot = GroupAction(
        condition = UnlessCondition(use_teleop_mode),
        actions=[
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                output='screen',
                parameters=[{"robot_description": robot_description}] 
            ),
            Node(
                package="joint_state_publisher_gui",
                executable="joint_state_publisher_gui",
            ),
            Node(
                package = 'rviz2',
                executable = 'rviz2',
                name='rviz2',
                output='screen',
                arguments=["-d", os.path.join(oxbot_description_path, "rviz", "rvizconfig2.rviz")]
            ),
        ]
    )

    return LaunchDescription(
        [
            model_arg,
            use_teleop_mode_arg,
            teleoperated_oxbot,
            autonomous_oxbot,
        ]
    )
