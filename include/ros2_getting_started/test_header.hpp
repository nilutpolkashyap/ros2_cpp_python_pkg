// #include "ros2_getting_started/test_header.hpp"
#include "rclcpp/rclcpp.hpp"

class MyCustomNode : public rclcpp::Node
{
    public:
        MyCustomNode(): Node("my_node")
        {
            RCLCPP_INFO(this->get_logger(), "TEST CPP NODE");
        }

    private:
}