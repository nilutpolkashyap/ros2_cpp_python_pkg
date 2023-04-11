#include "rclcpp/rclcpp.hpp"

class MyCustomCPPNode : public rclcpp::Node
{
    public:
        MyCustomCPPNode(): Node("my_node")
        {
            RCLCPP_INFO(this->get_logger(), "TEST CPP Node");
        }

    private:
}