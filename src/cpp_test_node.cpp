#include "rclcpp/rclcpp.hpp"
#include "ros2_cpp_python_pkg/cpp_test_header.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyCustomCPPNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}