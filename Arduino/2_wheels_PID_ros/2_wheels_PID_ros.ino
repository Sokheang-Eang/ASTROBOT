#define USE_USBCON
#include "variable.h"
#include <ros.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Twist.h>
#include <ros/time.h>
/*-------------------- PID Control Motion  ----------*/
PID pid_left_motor(&left_motor_speed, &max_speed, &speed_req_left, Kp, Ki, Kd, DIRECT);    //  Speed motor left
PID pid_right_motor(&right_motor_speed, &max_speed, &speed_req_right, Kp, Ki, Kd, DIRECT); //  Speed motor right

/*-------------------------------- Request Velocity ROS -------------------------------*/
ros::NodeHandle astrobot;
void handle_cmd(const geometry_msgs::Twist &cmd_vel)
{
  speed_req_x = cmd_vel.linear.x * 10;
  speed_req_z = cmd_vel.angular.z * 10;
  speed_req_left = speed_req_x - speed_req_z * (wheelbase / 2);
  speed_req_right = speed_req_x + speed_req_z * (wheelbase / 2);
}
ros::Subscriber<geometry_msgs::Twist> cmd_vel("cmd_vel", handle_cmd);
geometry_msgs::Vector3Stamped motor_speed_msg;
ros::Publisher vector_speed("motor_speed", &motor_speed_msg);
void setup()
{
  Serial.begin(GLOBLE_BOADRATE);
  Serial1.begin(GLOBLE_BOADRATE);
  Serial2.begin(GLOBLE_BOADRATE);
  Serial3.begin(GLOBLE_BOADRATE);
  /*-------------------------------- attachInterupt Pin ------------------------------*/
  pinMode(EncoderI_A, INPUT_PULLUP);
  pinMode(EncoderI_B, INPUT_PULLUP);
  pinMode(EncoderII_A, INPUT_PULLUP);
  pinMode(EncoderII_B, INPUT_PULLUP);
  /*-------------------------------- attachInterupt Pin ------------------------------*/
  attachInterrupt(digitalPinToInterrupt(EncoderI_A), ReadEncoderI_B, RISING);
  attachInterrupt(digitalPinToInterrupt(EncoderII_A), ReadEncoderII_B, RISING);
  /*-------------------------------- ROS ---------------------------------------------*/
  astrobot.initNode();
  astrobot.getHardware()->setBaud(GLOBLE_BOADRATE);
  astrobot.subscribe(cmd_vel);
  astrobot.advertise(vector_speed);

  // setting PID parameters
  pid_left_motor.SetSampleTime(5);
  pid_right_motor.SetSampleTime(5);
  pid_left_motor.SetOutputLimits(-max_robot_speed, max_robot_speed);
  pid_right_motor.SetOutputLimits(-max_robot_speed, max_robot_speed);
  pid_left_motor.SetMode(AUTOMATIC);
  pid_right_motor.SetMode(AUTOMATIC);
}

void loop()
{
  astrobot.spinOnce();
  motor_left_control();
  motor_right_control();
  // Control Motor ***
  MotorDrive(pwm_left, pwm_left, pwm_right, pwm_right);

  if ((millis() - lastMillis) >= LOOPTIME)
  {
    lastMillis = millis();
    // Read Encoder ***
    RotaryEncoder_L = RotaryEncoder_L - Rotary_L;
    RotaryEncoder_R = RotaryEncoder_R - Rotary_R;
    interrupts();
    // Read IMU Sensor ***
    UART2_rxBuffer();
    // ros odom calculation ***
    LastEncoder_L = Rotary_L;
    LastEncoder_R = Rotary_R;
    // calculated motor speed ***
    get_motor_speed();
    // reset encoder
    RotaryEncoder_L = LastEncoder_L;
    RotaryEncoder_R = LastEncoder_R;
    // *** Publish /speed ***
    //*----- vector data ------------*/
    motor_speed_msg.header.stamp = astrobot.now();
    motor_speed_msg.vector.x = left_motor_speed;
    motor_speed_msg.vector.y = right_motor_speed;
    motor_speed_msg.vector.z = gZ;
    vector_speed.publish(&motor_speed_msg);
    astrobot.spinOnce();
  }
}
