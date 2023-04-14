#include <chrono>
#include <functional> 
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

const float RPM_VALUE = 10.0;

using namespace std::chrono_literals;

class RpmPubNode : public rclcpp::Node
{
  public: 
    RpmPubNode() : Node("rpm_publisher_node") 
    {
      publisher_ = this->create_publisher<std_msgs::msg::Float64>("rpm", 10);
      timer_ = this->create_wall_timer(1s, std::bind(&RpmPubNode::publish_rpm, this));
      std::cout << "RPM Publisher Node Is Running..." << std:: endl;
    }

  private:
    void publish_rpm()
    {
      auto message = std_msgs::msg::Float64();
      message.data = RPM_VALUE;
      publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RpmPubNode>());
  rclcpp::shutdown();
  
  return 0;
}