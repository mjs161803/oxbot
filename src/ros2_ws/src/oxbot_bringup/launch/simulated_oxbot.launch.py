import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    gazebo = IncludeLaunchDescription(
        os.path.join(
            get_package_share_directory("oxbot_description"),
            "launch",
            "gazebo.launch.py"
        ),
    )
    
    controller = IncludeLaunchDescription(
        os.path.join(
            get_package_share_directory("oxbot_gz_controller"),
            "launch",
            "controller.launch.py"
        ),
    )

    slam = IncludeLaunchDescription(
        os.path.join(
            get_package_share_directory("oxbot_mapping"),
            "launch",
            "slam.launch.py"
        ),
    )

    rviz_slam = Node(
        package="rviz2",
        executable="rviz2",
        arguments=["-d", os.path.join(
                get_package_share_directory("oxbot_mapping"),
                "rviz",
                "slam.rviz"
            )
        ],
        output="screen",
        parameters=[{"use_sim_time": True}],
    )

    return LaunchDescription([
        gazebo,
        controller,
        slam,
        rviz_slam
    ])