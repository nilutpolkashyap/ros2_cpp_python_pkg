#!/usr/bin/env python3

import rclpy
from scripts.py_test_module import MyCustomPYNode

def main(args=None):
    rclpy.init(args=args)
    node = MyCustomPYNode()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()