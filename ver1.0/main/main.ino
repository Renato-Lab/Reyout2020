#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>

Servo escF;
Servo escB;
VL53L1X sensor;

void setup()
{
  Serial.begin(115200);
  motor_pin_define();
  tof_setup();
  esc_setup();
}

void loop()
{
  Serial.println(get_tof("front"));
}
