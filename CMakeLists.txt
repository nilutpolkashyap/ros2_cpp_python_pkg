cmake_minimum_required(VERSION 3.8)
project(ros2_cpp_python_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate custom interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/OddEvenCheck.srv"
  "srv/TurnCamera.srv"
  DEPENDENCIES 
  sensor_msgs action_msgs geometry_msgs std_msgs
  ADD_LINTER_TESTS
)

# Set support for using custom interfaces in C++ code
rosidl_get_typesupport_target(cpp_typesupport_target "${PROJECT_NAME}" "rosidl_typesupport_cpp")

# Include CPP "include" directory
include_directories(include)

# Create CPP Executables
add_executable(cpp_node src/cpp_test_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(string_publisher src/string_publisher.cpp)
ament_target_dependencies(string_publisher rclcpp std_msgs)

add_executable(string_subscriber src/string_subscriber.cpp)
ament_target_dependencies(string_subscriber rclcpp std_msgs)

add_executable(rpm_publisher src/rpm_publisher.cpp)
ament_target_dependencies(rpm_publisher rclcpp std_msgs)

add_executable(speed_calculator src/speed_calculator.cpp)
ament_target_dependencies(speed_calculator rclcpp std_msgs)

add_executable(service_server src/service_server.cpp)
ament_target_dependencies(service_server rclcpp) 
target_link_libraries(service_server "${cpp_typesupport_target}")

add_executable(service_client src/service_client.cpp)
ament_target_dependencies(service_client rclcpp) 
target_link_libraries(service_client "${cpp_typesupport_target}")

add_executable(turn_camera_service src/turn_camera_service.cpp)
ament_target_dependencies(turn_camera_service rclcpp sensor_msgs OpenCV cv_bridge) 
target_link_libraries(turn_camera_service "${cpp_typesupport_target}")

add_executable(turn_camera_client src/turn_camera_client.cpp)
ament_target_dependencies(turn_camera_client rclcpp sensor_msgs OpenCV cv_bridge) 
target_link_libraries(turn_camera_client "${cpp_typesupport_target}")

# Install CPP Executables
install(TARGETS
  cpp_node
  string_publisher
  string_subscriber
  rpm_publisher
  speed_calculator
  service_server
  service_client
  turn_camera_service
  turn_camera_client
  DESTINATION lib/${PROJECT_NAME}
)

# Install for Launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)


# Install Python Modules
ament_python_install_package(${PROJECT_NAME})
ament_python_install_package(scripts)

# Install Python Executables
install(PROGRAMS
  scripts/py_test_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
