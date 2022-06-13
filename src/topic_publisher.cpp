#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("topic_publisher");
    auto pub = node->create_publisher<std_msgs::msg::String>("/my_topic", 10);

    std_msgs::msg::String msg;
    size_t counter{0};

    rclcpp::WallRate loop_rate(250ms);

    while ((rclcpp::ok()))
    {
        msg.data = "Hello from Publisher " + std::to_string(counter++);

        RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", msg.data.c_str());

        pub->publish(msg);
        rclcpp::spin_some(node);

        loop_rate.sleep();
    }

    rclcpp::shutdown();

    return 0;
    
}
