#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>

Servo escF;
Servo escB;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  motor_pin_define();
  tof_setup();
  //esc_setup();
}

void loop()
{
  get_tof();
}
