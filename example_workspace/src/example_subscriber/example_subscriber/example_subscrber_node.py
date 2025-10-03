#头文件？#

class ExampleSubscriber(#继承自哪个节点？#):

    def __init__(self):
        super().__init__('example_subscriber')
        self.subscription = self.#创建subscription#
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
        rclpy.init(args=args)
        example_subscriber = ExampleSubscriber()
        rclpy.spin(#spin什么？#)


if __name__ == '__main__':
    main()