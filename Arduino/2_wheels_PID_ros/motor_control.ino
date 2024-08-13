#include "variable.h"

void MotorDrive(float FL_Motor, float RL_Motor, float RR_Motor, float FR_Motor) {
  // Send RPM to Motor
  V[1] = (int)RR_Motor;
  V[2] = (int)FL_Motor;
  V[3] = (int)RL_Motor;
  V[4] = (int)FR_Motor;
  // Change Direction Motor
  V[2] = -1 * (V[2]);
  V[3] = -1 * (V[3]);

  for (int M = 1; M <= 4; M++) {
    if (V[M] > Vmax) V[M] = Vmax;
    if (V[M] < -Vmax) V[M] = -Vmax;
    MotorControl(M, V[M]);
  }
}
void MotorControl(long ID, int Speed) {  // Driver Motor Control
  int SD;
  SD = ID * 10000 + (Speed > 0 ? 1 : 0) * 1000 + abs(Speed);
  Serial1.println(SD);
}
