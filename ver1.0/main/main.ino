#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <PID_v1.h>

Servo escF;
Servo escB;

#define HOLD_F A8
#define FOLD_B A9

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire1.begin();
  Wire2.begin();
  Wire.setClock(400000); // use 400 kHz I2C
  Wire1.setClock(400000); // use 400 kHz I2C
  Wire2.setClock(400000); // use 400 kHz I2C

  motor_pin_define();
  adc_setup();
  tof_setup();
  bno055_setup();
  
}

void loop()
{
  motor_set(50,0,0);
}
