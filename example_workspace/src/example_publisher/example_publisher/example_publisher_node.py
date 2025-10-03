import rclpy
from rclpy.node import ###node节点###
from std_msgs.msg import String
class ExamplePublisher(Node):

    def __init__(self):
        super().__init__("example_publisher_node")
        self.publisher_ = ###创建发布者###
        timer_period = 1  
        self.timer = self.create_timer###请填写
        self.i = 1

    def timer_callback(self):
        msg = ###创建消息类型###
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.###创建发布者###
        self.get_logger().info('Publishing: "%s"' % msg.data) 
        self.i += 1

def main(args=None): 

    rclpy.init(args=args) 
    example_publisher = ###初始化发布者节点 ###
    rclpy.spin(example_publisher) 
    

if __name__ == '__main__':
    main() 