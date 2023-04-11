#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyCustomPYNode(Node):

    def __init__(self):
        super().__init__("my_python_test_node")
        self.get_logger().info("TEST Python Node")