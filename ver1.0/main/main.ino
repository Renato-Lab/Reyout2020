#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <PID_v1.h>

Servo escF;
Servo escB;

bool isGAME_START = false; 

#define HOLD_F 22
#define HOLD_B 23
bool isHOLD_F;
bool isHOLD_B;

bool isBLUE_GOAl = true;
bool isYELLOW_GOAL = false;

int ballX,ballY,ballQty,highByte_ballX,lowByte_ballX,highByte_ballY,lowByte_ballY,highByte_qty_ball,lowByte_qty_ball;
int blueGoalX,blueGoalY,blueGoalQty,highByte_blueGoalX,lowByte_blueGoalX,highByte_blueGoalY,lowByte_blueGoalY,highByte_qty_blue_goal,lowByte_qty_blue_goal;
int yellowGoalX,yellowGoalY,yellowGoalQty,highByte_yellowGoalX,lowByte_yellowGoalX,highByte_yellowGoalY,lowByte_yellowGoalY,highByte_qty_yellow_goal,lowByte_qty_yellow_goal;
float fixedBallX, fixedBallY, fixedBlueGoalX,fixedBlueGoalY,fixedYellowGoalX, fixedYellowGoalY, fixedDistance,move_dir;
#define CENTER_CAMERA_X 160
#define CENTER_CAMERA_Y 120

float a = 28.59776;
float b = 1.41069;
float c = -0.86659;
float d = -0.00139;
float e = -0.00138;
float f = 0.00578;

int motorPower = 70;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  pinMode(6,INPUT);
  pinMode(13,INPUT);

  motor_pin_define();
  esc_setup();
  //tof_setup();
  //bno055_setup();
  
}

void loop(){
  
  //get_camera_data();
  //check_hold();

  //print_camera_data();
  //float dis = sqrt(fixedBallX * fixedBallX + fixedBallY * fixedBallY);
  //fixedDistance = 0.01638*(dis*dis) - 1.2726*dis + 34.105;
  //float dir = atan2(fixedBallX,fixedBallY);
  //dir = dir * 180/PI;

  if(digitalRead(6) == HIGH){
    Serial.println("HIGH");
    /*if (ballX == 0 && ballY == 0){
      motor_set(0,0,0);
    }else if(isHOLD_F == true && isBLUE_GOAl == true){//青ゴール攻め、前でホールド
      motor_set(motorPower,ball_tracking_dir(fixedBlueGoalX,fixedBlueGoalY),0);
    }else if(isHOLD_F == true && isYELLOW_GOAL == true){//黄ゴール攻め、前でホールド
      motor_set(motorPower,ball_tracking_dir(fixedYellowGoalX,fixedYellowGoalY),0);
    }else if(isHOLD_B == true && isBLUE_GOAl == true){//青ゴール攻め、後ろでホールド
      //makao-shot
    }else if(isHOLD_B == true && isYELLOW_GOAL == true){//黄ゴール攻め、後ろでホールド
      //makao-shoot
    }else{
      motor_set(motorPower,ball_tracking_dir(fixedBallX,fixedBallY),0);
    }*/
  }else if (digitalRead(6) == LOW){
    //motor_set(0,0,0);
    Serial.println("LOW");
  }
}