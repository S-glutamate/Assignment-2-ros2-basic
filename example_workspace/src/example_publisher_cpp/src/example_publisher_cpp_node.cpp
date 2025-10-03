#include <string> 
#include "rclcpp/rclcpp.hpp" 
#include "std_msgs/msg/string.hpp" 

class ExamplePublisher : public rclcpp::Node
{
public:
  ExamplePublisher()
  : Node("example_publisher"), count_(1)//初始化count为1
  {
    publisher_ = this->//请填写
    timer_ = this->create_wall_timer/*创建定时器*/

  }

private:
  void timer_callback()
  {
    auto message = /*初始化消息类型*/
    std::string content;
    message.data = "Hello, world! " + std::to_string(this->count_);
    RCLCPP_INFO(/*logger*/, "Publishing: '%s'", message.data.c_str());
    publisher_->/*发布消息*/
    this->count_++;
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);//初始化
  rclcpp::spin(std::make_shared<//请填写>());
  return 0;
}