#include "rclcpp/rclcpp.hpp"

class MyCustomCPPNode : public rclcpp::Node
{
    public:
        MyCustomCPPNode(): Node("my_cpp_test_node")
        {
            RCLCPP_INFO(this->get_logger(), "TEST CPP Node");
        }

    private:
};