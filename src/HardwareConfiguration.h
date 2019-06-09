/**
 * @file HardwareConfiguration.h
 * @brief File that contains the configuratioindetails of the different modules
 * 
 * @author Glenn Huber (glenn.patrick.huber@hsr.ch)
 * 
 * @version 1.0 - switched from define to const int  - Luca Mazzoleni (luca.mazzoleni@hsr.ch)  - 2019-03-20
 * @version 0.0 - BA FTS FS 2018
 * 
 * @date 2019-03-20
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef HARDWARECONFIGURATION_H
#define HARDWARECONFIGURATION_H

//Setup for Drive /////////////////
const double SPEEDFACTOR = 1.3;                                ///< The speed factor can be used to increase or decrease the complete speed. it affects all speed settings.
const unsigned int RIGHT_MOTOR = 1;                            ///< Portnumber of the right motor on the motorshield
const unsigned int LEFT_MOTOR = 2;                             ///< Portnumber of the left motor on the motorshield
const unsigned int SPEED = 70 * SPEEDFACTOR;                   ///< Standard operating speed
const unsigned int REDUCED_SPEED = SPEED * 0.8 * SPEEDFACTOR;  ///< Reduced operating speed
const unsigned int TURNING_SPEED = 70 * SPEEDFACTOR;           ///< Turning speed
// const unsigned int PUSH_SPEED = 80 * SPEEDFACTOR;     ///<

const unsigned int PIN_SENSOR_0 = 13;  ///< Pin number of line detection sensor 0
const unsigned int PIN_SENSOR_1 = 12;  ///< Pin number of line detection sensor 1
const unsigned int PIN_SENSOR_2 = 11;  ///< Pin number of line detection sensor 2
const unsigned int PIN_SENSOR_3 = 10;  ///< Pin number of line detection sensor 3
const unsigned int PIN_SENSOR_4 = 9;   ///< Pin number of line detection sensor 4
/////////////////////////////////////

//Setup for Drive - PID /////////////////////
#if SPEEDFACTOR < 2
const double PID_KP = 10;     ///< P-value of the PID-controller
const double PID_KI = 2;      ///< I-value of the PID-controller
const double PID_KD = 0.005;  ///< D-value of the PID-controller
// const double PID_KP = 5;      ///< P-value of the PID-controller
// const double PID_KI = 2;      ///< I-value of the PID-controller
// const double PID_KD = 0.001;  ///< D-value of the PID-controller
#else  //use an more agressiv PID
const double K_P = 30;    ///< P-value of the PID-controller
const double K_I = 20;    ///< I-value of the PID-controller
const double K_D = 0.05;  ///< D-value of the PID-controller
#endif
/////////////////////////////////////

//Setup for sonar ///////////////////
#define SONAR_SERVO_PIN 5        ///<
#define SONAR_TRIGGER_PIN 15     ///<
#define SONAR_ECHO_PIN 14        ///<
#define SONAR_MAX_DISTANCE 9999  ///<
#define MIN_ERROR -5             ///<
#define MAX_ERROR 5              ///<
#define MIN_TURN_ANGLE 180       ///<
#define MAX_TURN_ANGLE 0         ///<
////////////////////////////////////

//Setup for Hoist //////////////////
#define HOIST_SERVO_PIN 6       ///< Pin-Number for Servocontroll of the Hoist
#define HOIST_SERVO_DELAY 30    ///< Duration of the delay between the position updates of the Servo
#define HOIST_POSITION_MIN 160  ///< Minimal angle of the Servo
#define HOIST_POISITION_MAX 65  ///< Maximal angle of the Servo
////////////////////////////////////

//Setup for Vision /////////////////
#define VISION_SERVO_PIN 5          ///<
#define VISION_DELAY_FACTOR 6       ///<
#define VISION_TOLERANCE_LEFT 165   ///<
#define VISION_TOLERANCE_RIGHT 155  ///<
#define VISION_START_ANGLE 90       ///<
////////////////////////////////////

#endif