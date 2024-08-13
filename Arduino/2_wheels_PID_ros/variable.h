#ifndef _VARIABLE_H
#define _VARIABLE_H

#include <Arduino.h>
#include <PID_v1.h>

/*--------------------- Globle BoadRate ---------------------------*/
#define GLOBLE_BOADRATE 115200

/*--------------------- Rotary Encoder Pin ------------------------*/
#define EncoderI_A 2
#define EncoderI_B 3
#define EncoderII_A 4
#define EncoderII_B 5
#define pi 3.14
#define LOOPTIME 100
#define encoder_wheel 0.03
#define wheelbase 0.35
/*------------------------ Encoder Parameter ----------------------*/
volatile signed long Rotary_L, Rotary_R;
volatile long RotaryEncoder_L, RotaryEncoder_R;
unsigned int LastEncoder_L, LastEncoder_R;
double Encoder_tick = 100;

/*--------------------- Invers Kinematic Parameter ----------------*/
int V[5] = { 0, 0, 0, 0, 0 };  // InversKinematic Parameter
int AngleRobot = 0;
int pwm_left, pwm_right = 0;
double Vmax = 10;
double max_robot_speed = 0.2;  // speed (m/s)
double max_speed;
double gZ;
unsigned long lastMillis = 0;
/*--------------------- Feedback VEL ------------------------------*/
float speed_req_x = 0, speed_req_y, speed_req_z = 0;
double speed_req_left = 0, speed_req_right = 0;
double left_motor_speed, right_motor_speed;
const double speed_to_pwm_ratio = 0.00235;
const double min_speed_cmd = 0.0882;
/*--------------------- PID Gain ----------------------------------*/
double Kp = 0.01, Ki = 0.00, Kd = 0.001;
#endif
