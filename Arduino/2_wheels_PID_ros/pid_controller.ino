#include "variable.h"
void motor_left_control(void) {
  max_speed = constrain(max_speed, -max_robot_speed, max_robot_speed);
  pid_left_motor.Compute();
  // compute PWM value for left motor. Check constant definition comments for more information.
  pwm_left = constrain(((speed_req_left + signed(speed_req_left) * min_speed_cmd) / speed_to_pwm_ratio) + (max_speed / speed_to_pwm_ratio), -Vmax, Vmax);
}
void motor_right_control(void) {
  max_speed = constrain(max_speed, -max_robot_speed, max_robot_speed);
  pid_right_motor.Compute();
  // compute PWM value for left motor. Check constant definition comments for more information.
  pwm_right = constrain(((speed_req_right + signed(speed_req_right) * min_speed_cmd) / speed_to_pwm_ratio) + (max_speed / speed_to_pwm_ratio), -Vmax, Vmax);
}
