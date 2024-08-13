#include "variable.h"

void ReadEncoderI_B(void) {               // Read Rotary Encoder for Velocity_L !!!
  int even_L = !digitalRead(EncoderI_B);  // Problem Solded
  (even_L > 0) ? Rotary_L-- : Rotary_L++;
}
void ReadEncoderII_B(void) {               // Read Rotary Encoder for Velocity_R !!!
  int even_R = !digitalRead(EncoderII_B);  // Problem Solded
  (even_R > 0) ? Rotary_R++ : Rotary_R--;
}
void CheckUART2(void) {
  if (!Serial2) {
    Serial.println(" Check Serial From GyroScopeSensor !!! ");
    while (1)
      ;
  } else {
    Serial.println(" Ready For GyroScopeSensor !!! ");
  }
}
void UART2_rxBuffer(void) {
  while (Serial2.available() > 1) {
    AngleRobot = Serial2.parseInt();
    AngleRobot = AngleRobot - 450;
  }
}