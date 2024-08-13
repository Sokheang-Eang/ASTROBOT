#include "variable.h"

void get_motor_speed(void) {
  //*--------- diff Drive ---------------*/
  left_motor_speed = (2 * pi * (RotaryEncoder_L / Encoder_tick) * encoder_wheel) * (1000 / LOOPTIME);
  right_motor_speed = (2 * pi * (RotaryEncoder_R / Encoder_tick) * encoder_wheel) * (1000 / LOOPTIME);
  // Orentation rad
  gZ = ((AngleRobot * pi) / 180);
  gZ = gZ * 0.1;
}
