#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

std::shared_ptr<rclcpp::Node> node = nullptr;

void TopicCallback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(node->get_logger(), "I heard : '%s'", msg->data.c_str());
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    node = std::make_shared<rclcpp::Node>("topic_subscriber");
    auto sub = node->create_subscription<std_msgs::msg::String>("/my_topic", 10, TopicCallback);

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}