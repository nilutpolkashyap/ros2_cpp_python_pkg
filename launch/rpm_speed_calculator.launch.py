from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="ros2_cpp_python_pkg", 
            executable="rpm_publisher",
            name="rpm_pub_node",
            parameters=[
                {"rpm_val": 5.0}
            ]
        ),
        Node(
            package="ros2_cpp_python_pkg", 
            executable="speed_calculator",
            name="speed_calc_node",
            parameters=[
                {"wheel_radius": 10/100} ### Centimeters to Meters
            ]
        ),
        ExecuteProcess(
            cmd=['ros2', 'topic', 'list'],
            output='screen'
        )
    ])