#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"  // 使用示例服务接口

using namespace std::placeholders;//占位符

class ExampleService : public rclcpp::Node
{
public:
    ExampleService() : Node("example_service")
    {
        // 创建服务，服务名称为 "add_two_ints"，回调函数为 add_two_ints_callback
        //服务的类型是 example_interfaces::srv::AddTwoInts
        srv_ = this->create_service<example_interfaces::srv::AddTwoInts>(
            "add_two_ints", std::bind(&ExampleService::/*哪个回调函数？*/, this, _1, _2));
        /*绑定函数，用法如上，效果类似this->add_two_ints_callback(request,response)*/
    }

private:
    // 回调函数，执行加法操作
    void add_two_ints_callback(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                               std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
    {
        response->sum = // 计算和
        RCLCPP_INFO(this->get_logger(), "Incoming request\na: %ld b: %ld", request->a, request->b);
    }

    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr srv_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto example_service = std::make_shared</*类名*/>();  // 声明 example_service 对象
    rclcpp::spin(example_service);
    rclcpp::shutdown();
    return 0;
}
