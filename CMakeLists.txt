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

# Install CPP Executables
install(TARGETS
  cpp_node
  string_publisher
  string_subscriber
  rpm_publisher
  speed_calculator
  DESTINATION lib/${PROJECT_NAME}
)


# Install Python Modules
ament_python_install_package(${PROJECT_NAME})

# Install Python Executables
install(PROGRAMS
  scripts/py_test_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
