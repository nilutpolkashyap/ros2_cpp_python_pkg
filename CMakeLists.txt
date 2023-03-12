cmake_minimum_required(VERSION 3.8)
project(ros2_getting_started)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)  

# For including C++ header files from include folder
include_directories(include)     

## Create CPP Executable
add_executable(cpp_publisher src/topic_publisher.cpp)
ament_target_dependencies(cpp_publisher rclcpp std_msgs)

add_executable(cpp_subscriber src/topic_subscriber.cpp)
ament_target_dependencies(cpp_subscriber rclcpp std_msgs)

## Install CPP Executable
install(TARGETS
	 cpp_publisher
   cpp_subscriber
   DESTINATION lib/${PROJECT_NAME}
 )

## Install Python Module
ament_python_install_package(${PROJECT_NAME})

## Install Python 
install(PROGRAMS
	 scripts/topic_publisher.py 
   scripts/topic_subscriber.py 
   DESTINATION lib/${PROJECT_NAME}
 )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()



ament_package()
