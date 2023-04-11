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

# Install CPP Executables
install(TARGETS
  cpp_node
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
