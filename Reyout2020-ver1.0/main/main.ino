#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>

Servo escF;
Servo escB;
VL53L1X sensor;

#define M1_dir 6
#define M2_dir 7
#define M3_dir 8
#define M4_dir 9
#define M1_pwm 2
#define M2_pwm 3
#define M3_pwm 4
#define M4_pwm 5

void setup()
{
    pinMode(M1_dir,OUTPUT);
    pinMode(M2_dir,OUTPUT);
    pinMode(M3_dir,OUTPUT);
    pinMode(M4_dir,OUTPUT);
}

void loop()
{
    motor_set(50,0,0);
}