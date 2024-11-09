cmake_minimum_required(VERSION 3.8)
project(motion_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/motion_control/)
include_directories(/root/oxbot/src/ros2_ws/install/oxbot_config/include/)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(oxbot_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(oxbot_config REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

add_executable(motion_controller src/motion_controller.cpp src/MotionControllerNode.cpp src/SerialCommunicator.cpp src/FeedbackFrame.cpp)
ament_target_dependencies(motion_controller rclcpp oxbot_interfaces geometry_msgs nav_msgs oxbot_config tf2 tf2_ros)

add_executable(oxbot_teleop src/oxbot_teleop.cpp src/OxbotTeleopNode.cpp)
ament_target_dependencies(oxbot_teleop rclcpp sensor_msgs oxbot_config)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(${PROJECT_NAME}_motion_controller_node_test test/MotionControllerNodeTest.cpp)
  target_include_directories(${PROJECT_NAME}_motion_controller_node_test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  )
  ament_target_dependencies(${PROJECT_NAME}_motion_controller_node_test
    std_msgs
    rclcpp 
    oxbot_interfaces 
    geometry_msgs 
    oxbot_config
  )
  target_link_libraries(${PROJECT_NAME}_motion_controller_node_test)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  motion_controller
  oxbot_teleop
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
