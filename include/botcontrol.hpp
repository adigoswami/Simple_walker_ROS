/**
 * @file       control.hpp
 * @version    1.0
 * @brief      Header file for control class.
 * @created    25th Nov 2020
 * @copyright  Copyright 2020. All rights reserved
 * @Author :   Aditya Goswami 
 */
#pragma once

// c++ header file
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <array>

/**
 * creates the control class
 */
class botcontrol {
 /**
  * contains public data members
  */
 public:
  botcontrol();
  void init();
  void solve();

 /**
  * contains private data members
  */ 
 private:
  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub;

  ros::Subscriber scan_sub;

  std::array<double, 3> scan_data = {0.0, 0.0, 0.0};

  void updateCmdVel(double linear, double angular);
  void scanCallback(const sensor_msgs::LaserScan::ConstPtr &msg);
};
