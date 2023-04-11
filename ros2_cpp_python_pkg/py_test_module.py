#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyCustomPYNode(Node):

    def __init__(self):
        super().__init__("TEST PYTHON Node")
        self.get_logger().info("TEST Python")