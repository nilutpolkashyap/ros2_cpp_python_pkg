#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <functional>

// using namespace std::chrono_literals;

class HelloWorldPubNode : public rclcpp::Node
{
	public:
		HelloWorldPubNode() : Node("hello_world_pub_node")
		{
			publisher_ = this->create_publisher<std_msgs::msg::String>(
				"string_topic", 10
			);
			timer_ = this->create_wall_timer(
				std::chrono::seconds(1),
				std::bind(&HelloWorldPubNode::publish_hello_world, this)
			);
		}

	private:
		void publish_hello_world()
		{
			auto message = std_msgs::msg::String();
			message.data = "Hello World - " + std::to_string(counter_);
			RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
			// RCLCPP_WARN(this->get_logger(), "Publishing: '%s'", message.data.c_str());
			// RCLCPP_ERROR(this->get_logger(), "Publishing: '%s'", message.data.c_str());
			// RCLCPP_DEBUG(this->get_logger(), "Publishing: '%s'", message.data.c_str());
			publisher_->publish(message);

			counter_++;
		}

		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
		rclcpp::TimerBase::SharedPtr timer_;
		size_t counter_ = 0;

};

int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);

	rclcpp::spin(std::make_shared<HelloWorldPubNode>());
	rclcpp::shutdown();

  return 0;
}












