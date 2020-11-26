#include <sstream>
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv) {

  ros::init(argc, argv, "walker_node");
  /*Turtlebot3Drive turtlebot3_drive;*/

  ros::NodeHandle nh;


  ros::Publisher control_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);
  
  ros::Subscriber sub = nh.subscribe("scan", 1000, chatterCallback);

  geometry_msgs::Twist cmd_vel_msg;
  cmd_vel_msg.linear.x = .1;
  cmd_vel_msg.angular.z = 0;

  ros::Rate loop_rate(125);

  while (ros::ok())
  {
    /*turtlebot3_drive.controlLoop();*/
    control_pub.publish(cmd_vel_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;

} 