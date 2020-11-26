# Aditya Goswami - ENPM808x
# Simple_walker_ROS
[![License](https://img.shields.io/badge/license-MIT-green)](https://opensource.org/licenses/MIT)
---
## Overview
This ROS based project simulates a turtlebot object avoidance behaviour. It does so by simply moving forward until it senses an obstacle within a particular range. Whenever there is any obstacle along the path, it rotates around its center until the path is clear and then again starts moving forward.

## Dependencies
This program works on a device running Ubuntu 18.04 and ROS Melodic. It will also need Gazebo 7.x (part of ros-kinetic-desktop-full package) and Turtlebot simulation stack. If full destop option was selecting while installing ROS kinetic, it is not required to install Gazebo separately.

* To install ROS Melodic in Ubuntu 18.04, follow the steps in this [link](http://wiki.ros.org/melodic/Installation/Ubuntu).

* To install catkin, follow the installation steps in this [link](http://wiki.ros.org/catkin).

* To install turtlebot simulation stack. In a terminal:

```
sudo apt-get install ros-melodic-turtlebot-gazebo ros-melodic-turtlebot-apps ros-melodic-turtlebot-rviz-launchers
source /opt/ros/melodic/setup.bash
```
## Dependencies
* This project assumses that you have turtlebot3_simulations installed:

```
cd ~/catkin_ws/src
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
```
* It also assumes the user has a created a catkin workspace by following this tutorial or you can follow the commands given further down this page under 'Build Instructions':
```
http://wiki.ros.org/catkin/Tutorials/create_a_workspace
```

## Build Instructions

To run this code in a catkin workspace:
```
cd ~/catkin_ws/
source devel/setup.bash
cd src/
git clone https://github.com/adigoswami/Simple_walker_ROS
cd ..
catkin_make
```
If you do not have a catkin workspace:
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/adigoswami/Simple_walker_ROS
cd ..
catkin_make
```
## Running

* After completing the building step, go to the workspace in the terminal and give the following commands.
```
cd ~/catkin_ws/
source devel/setup.bash
roslaunch Simple_walker_ROS walker.launch
```
The above command will automatically start the Gazebo application and the turtlebot will start moving while avoiding obstacles.

* Optional: add the argument record:=true to record all the data for 30 seconds. The default will be set to false.
```
cd ~/catkin_ws/
source devel/setup.bash
roslaunch Simple_walker_ROS walker.launch record:=true
```
## Inspecting Rosbag

* To inspect rosbag, locate where the rosbag is saved. These usually are saved in the home/.ros/ directory. Run the following:

```
rosbag info ROSBAG FILE
```