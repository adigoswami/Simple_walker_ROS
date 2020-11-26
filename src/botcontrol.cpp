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

// c++ header file
#include <iostream>

/**
 * @brief PID default constructor
 * @param none
 * @return none
 */
botcontrol::botcontrol() { }

/**
 * @brief    PID parameterized constructor sets values of gains
 * @param[1] prop_gain, which is the proportional gain
 * @param[2] int_gain, which is the intgral gain
 * @param[3] diff_gain, which is the differential gain
 * @return 	 none
 */
botcontrol::botcontrol(double prop_gain, double int_gain, double diff_gain){
	kp = prop_gain;
	ki = int_gain;
	kd = diff_gain;
}
/**
 * @brief      Next three functions return values of kp, ki and kd
 * @param      none
 * @return     The propotional gain.
 * @return     The integral gain
 * @return     The differential gain
 */
double botcontrol::GetKp() {
	return kp;
}
double botcontrol::GetKi() {
	return ki;
}
double botcontrol::GetKd() {
	return kd;
}