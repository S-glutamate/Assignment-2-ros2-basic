
from example_interfaces.srv import ###两数之和###
import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node


class ExampleService(###继承自###):

    def __init__(self):
        super().__init__('example_service')
        self.srv = self.create_service(###自己看###)

    def add_two_ints_callback(self, request, response):
        response.sum = ###加法###
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))

        return response


def main(args=None):
    try:
        rclpy.init()
        ###声明example_service###
        rclpy.spin(example_service)
    except (KeyboardInterrupt, ExternalShutdownException):
        print("external interrupt")
        pass


if __name__ == '__main__':
    main()