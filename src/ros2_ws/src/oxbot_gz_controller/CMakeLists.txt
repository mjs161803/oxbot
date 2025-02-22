cmake_minimum_required(VERSION 3.8)
project(oxbot_gz_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(Eigen3 REQUIRED)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/oxbot_gz_controller/)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(gz_motion_controller src/gz_motion_controller.cpp src/GZControllerNode.cpp)
ament_target_dependencies(gz_motion_controller rclcpp geometry_msgs std_msgs sensor_msgs nav_msgs tf2_ros tf2 ${Eigen_LIBRARIES})

add_executable(oxbot_teleop_node src/OxbotTeleopNode.cpp)
ament_target_dependencies(oxbot_teleop_node rclcpp sensor_msgs geometry_msgs)

install(
  DIRECTORY include
  DESTINATION include
)

install(
  DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
  gz_motion_controller 
  oxbot_teleop_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
