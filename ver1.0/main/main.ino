#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <PID_v1.h>

Servo escF;
Servo escB;

#define HOLD_F 22
#define FOLD_B 23

int ballX,ballY,highByte_ballX,lowByte_ballX,highByte_ballY,lowByte_ballY;
int blueGoalX,blueGoalY,highByte_blueGoalX,lowByte_blueGoalX,highByte_blueGoalY,lowByte_blueGoalY;
int yellowGoalX,yellowGoalY,highByte_yellowGoalX,lowByte_yellowGoalX,highByte_yellowGoalY,lowByte_yellowGoalY;
float fixedBallX, fixedBallY, fixedBlueGoalX,fixedBlueGoalY,fixedYellowGoalX, fixedYellowGoalY, fixedDistance,move_dir;
#define CENTER_CAMERA_X 160
#define CENTER_CAMERA_Y 120

float a = 28.59776;
float b = 1.41069;
float c = -0.86659;
float d = -0.00139;
float e = -0.00138;
float f = 0.00578;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Wire.begin();
  Wire1.begin();
  Wire2.begin();
  Wire.setClock(400000); // use 400 kHz I2C
  Wire1.setClock(400000); // use 400 kHz I2C
  Wire2.setClock(400000); // use 400 kHz I2C

  

  motor_pin_define();
  //adc_setup();
  //tof_setup();
  //bno055_setup();
  
}

void loop()
{
  if (Serial1.available() >= 13) {
    int head = Serial1.read();
    if (head == 128) {
      highByte_ballX = Serial1.read();
      lowByte_ballX = Serial1.read();
      highByte_ballY = Serial1.read();
      lowByte_ballY = Serial1.read();
      highByte_blueGoalX = Serial1.read();
      lowByte_blueGoalX = Serial1.read();
      highByte_blueGoalY = Serial1.read();
      lowByte_blueGoalY = Serial1.read();
      highByte_yellowGoalX = Serial1.read();
      lowByte_yellowGoalX = Serial1.read();
      highByte_yellowGoalY = Serial1.read();
      lowByte_yellowGoalY = Serial1.read();
      
      ballX = (highByte_ballX << 7) + lowByte_ballX;
      ballY = (highByte_ballY << 7) + lowByte_ballY;
      blueGoalX = (highByte_blueGoalX << 7) + lowByte_blueGoalX;
      blueGoalY = (highByte_blueGoalY << 7) + lowByte_blueGoalY;
      yellowGoalX = (highByte_yellowGoalX << 7) + lowByte_yellowGoalX;
      yellowGoalY = (highByte_yellowGoalY << 7) + lowByte_yellowGoalY;
      //Serial.println(ballX);

      fixedBallX = ballY - CENTER_CAMERA_Y;
      fixedBallY = ballX - CENTER_CAMERA_X;
      float dis = sqrt(fixedBallX * fixedBallX + fixedBallY * fixedBallY);
      fixedDistance = 0.01638*(dis*dis) - 1.2726*dis + 34.105;
      float dir = atan2(fixedBallX,fixedBallY);
      dir = dir * 180/PI;

      if (dir < -20) {
        move_dir = -(a + b * abs(dir) + c * abs(fixedDistance) + d * (dir * dir) + e * abs(dir) * abs(fixedDistance) + f * (fixedDistance * fixedDistance));
        //Serial.println(move_dir);
        //move_dir = -(a + (b * abs(fixedDistance)) + (c * abs(dir)) + (d * abs(fixedDistance) * abs(fixedDistance)) + (e * abs(fixedDistance) * abs(dir)) + (f * abs(dir) * abs(dir)));
      } else if (dir > 20) {
        move_dir = a + b * abs(dir) + c * abs(fixedDistance) + d * (dir * dir) + e * abs(dir) * abs(fixedDistance) + f * (fixedDistance * fixedDistance);
        //Serial.println(move_dir);
        //move_dir = a + (b * abs(fixedDistance)) + (c * abs(dir)) + (d * abs(fixedDistance) * abs(fixedDistance)) + (e * abs(fixedDistance) * abs(dir)) + (f * abs(dir) * abs(dir));
      }else{
        move_dir = dir;
        //Serial.println(move_dir);
      }
      motor_set(200,move_dir,0);


      //Serial.print(fixedDistance);
      //Serial.print("\t");
      //Serial.print(dir);
      //Serial.println("\t");
    }
  }
}
