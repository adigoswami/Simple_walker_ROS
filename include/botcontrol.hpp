
/**
 * @file       control.hpp
 * @version    1.0
 * @brief      Header file for control class.
 * @created    20th Nov 2020
 * @copyright  Copyright 2020. All rights reserved
 * @Author :   Aditya Goswami 
 */
#pragma once

// c++ header file
#include <iostream>

/**
 * The botcontrol class has variables for each of the term as well as time
 * interval and error variables. It has the method to implement PID controller to achieve the
 * desired goal and methods to get the error variables and time interval.
 */
class botcontrol {
	// Contains public data members
public:
	botcontrol();
	botcontrol(double prop_gain, double int_gain, double diff_gain);
	double GetKp();
	double GetKi();
	double GetKd();
	// Contains private data members
private:
	double kp, ki, kd;
};