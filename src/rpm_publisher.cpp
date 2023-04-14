#include <chrono>
#include <functional> 
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

const float RPM_DEFAULT_VALUE = 10.0;

using namespace std::chrono_literals;

class RpmPubNode : public rclcpp::Node
{
  public: 
    RpmPubNode() : Node("rpm_publisher_node") 
    {
      this->declare_parameter<double>("rpm_val", RPM_DEFAULT_VALUE);
      publisher_ = this->create_publisher<std_msgs::msg::Float64>("rpm", 10);
      timer_ = this->create_wall_timer(1s, std::bind(&RpmPubNode::publish_rpm, this));
      std::cout << "RPM Publisher Node Is Running..." << std:: endl;
    }

  private:
    void publish_rpm()
    {
      auto message = std_msgs::msg::Float64();
      this->get_parameter("rpm_val", rpm_param_val_);
      message.data = rpm_param_val_;
      // message.data = RPM_VALUE;

      RCLCPP_INFO(this->get_logger(), "Published RPM: '%f'", message.data);
      publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    double rpm_param_val_ = RPM_DEFAULT_VALUE;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RpmPubNode>());
  rclcpp::shutdown();
  
  return 0;
}