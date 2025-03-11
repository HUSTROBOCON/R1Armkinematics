import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class LinkStateSubscriber(Node):
    def __init__(self):
        super().__init__('link_state_subscriber')

        # 创建订阅者
        self.subscription = self.create_subscription(
            Odometry,
            '/basepos/link_pose',  # 根据插件中设置的话题名修改
            self.link_state_callback,
            10)

    def link_state_callback(self, msg):
        # 位置
        position = msg.pose.pose.position
        # 姿态
        orientation = msg.pose.pose.orientation
        # 线速度
        linear_velocity = msg.twist.twist.linear
        # 角速度
        angular_velocity = msg.twist.twist.angular

        self.get_logger().info(
            f'Position: x={position.x:.3f}, y={position.y:.3f}, z={position.z:.3f}\n'
            f'Orientation: x={orientation.x:.3f}, y={orientation.y:.3f}, '
            f'z={orientation.z:.3f}, w={orientation.w:.3f}\n'
            f'Linear velocity: x={linear_velocity.x:.3f}, y={linear_velocity.y:.3f}, '
            f'z={linear_velocity.z:.3f}\n'
            f'Angular velocity: x={angular_velocity.x:.3f}, y={angular_velocity.y:.3f}, '
            f'z={angular_velocity.z:.3f}'
        )

def main(args=None):
    rclpy.init(args=args)
    link_subscriber = LinkStateSubscriber()
    rclpy.spin(link_subscriber)
    link_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
