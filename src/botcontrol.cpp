/**
 * @file       control.cpp
 * @version    1.0
 * @brief      Implementing the botcontrol class
 * @created    25th Nov 2020
 * @copyright  Copyright 2020. All rights reserved
 * @Author :   Aditya Goswami 
 */

// user defined header files for PID Controller
#include "../include/botcontrol.hpp"


/**
 * @brief control default constructor
 * @param none
 * @return none
 */
botcontrol::botcontrol() { 
  init();
}

/**
 * @brief initializer to initialize publishers and subscrivers
 * @param none
 * @return none
 */
void botcontrol::init() {
  cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);
  scan_sub = nh.subscribe("scan", 10, &botcontrol::scanCallback, this);
}

/**
 * @brief method to publish new cmd_vel 
 * @param linear the linear velocity of the turtlebot 
 * @param angular the angular velocity of the turtlebot 
 * @return none
 */
void botcontrol::updateCmdVel(double linear, double angular) {
  geometry_msgs::Twist cmd_vel_msg;
  cmd_vel_msg.linear.x = linear;
  cmd_vel_msg.angular.z = angular;

  cmd_vel_pub.publish(cmd_vel_msg);
}

/**
 * @brief callback that reads scanner measurements at 0deg, 30deg, and 330deg 
 * @param &msg the message being transcribed on the scan topic
 * @return none
 */
void botcontrol::scanCallback(const sensor_msgs::LaserScan::ConstPtr &msg) {
  std::array<int, 3> scan_angles = {0, 30, 330};
  for (int i = 0; i < 3; i++) {
    if (std::isinf(msg->ranges.at(scan_angles[i]))) {
      scan_data[i] = msg->range_max;
    } else {
      scan_data[i] = msg->ranges.at(scan_angles[i]);
    }
  }
}

/**
 * @brief method that controls the robot based on the scanner data 
 * @param none
 * @return none
 */
void botcontrol::solve() {
  double forward_clearance = .4;
  double side_clearance = .3;

  if (scan_data[0] < forward_clearance) {
    if (scan_data[1] < scan_data[2]) {
      updateCmdVel(0, -1);
    } else {
      updateCmdVel(0, 1);
    }
  } else if (scan_data[1] < side_clearance) {
    updateCmdVel(0, -1);
  } else if (scan_data[2] < side_clearance) {
    updateCmdVel(0, 1);
  } else {
    updateCmdVel(.2, 0);
  }
}