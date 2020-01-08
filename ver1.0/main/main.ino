#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <PID_v1.h>

bool isGAME_START = false; 

#define HOLD_F 22
#define HOLD_B 23
bool isHOLD_F = false;
bool isHOLD_B = false;

Servo escF;
Servo escB;

#define SW1 6
#define SW2 13

bool isBLUE_GOAl = false;
bool isYELLOW_GOAL = true;

int ballX, ballY, highByte_ballX, lowByte_ballX, highByte_ballY, lowByte_ballY;
int blueX, blueY, highByte_blueX, lowByte_blueX, highByte_blueY, lowByte_blueY;
int yellowX, yellowY, highByte_yellowX, lowByte_yellowX, highByte_yellowY, lowByte_yellowY;
float fBallX, fBallY, fBallDis, fBallDir, fBlueX, fBlueY, fBlueDis, fBlueDir, fYellowX, fYellowY, fYellowDis, fYellowDir, move_dir;
#define CENTER_CAMERA_X 160
#define CENTER_CAMERA_Y 120

int mPower = 90;

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200);
  Wire.begin();
  //Wire.setClock(400000); // use 400 kHz I2C

  pinMode(SW1,INPUT);
  pinMode(SW2,OUTPUT);

  motor_pin_define();
  esc_setup();
  kicker_setup();
  tof_setup();
  bno055_setup();
  
}

void loop(){
  
  get_cam_data();
  calc_cam_data();
  check_hold();

  //print_camera_data();

  if(digitalRead(SW1) == HIGH){
    if(ballX == 0 && ballY == 0){
      motor_set(0,0,0);
      escF.write(1000);
      escB.write(1000);
    }else{
      if(isBLUE_GOAl){
        if(isHOLD_F){
          escF.write(2000);
          if(fBlueDis < 50){
            kick();
          }else{
            motor_set(mPower,fBlueDir,get_bno055_yaw());
          }
        }else if(isHOLD_B){
          escB.write(2000);
          if(fBlueDis < 20){
            japan();
          }else{
            motor_set(mPower,fBlueDir,get_bno055_yaw());
          }
        }else{//青攻めでホールドしてないとき
          if(abs(fBallDir) < 80 ){
            escF.write(2000);
            motor_set(mPower,ball_tracking_dir(fBallX,fBallY),get_bno055_yaw());
          }else if(abs(fBallDir) < 60){
            motor_set(mPower,ball_tracking_dir(fBallX,fBallY),fBallDir);
          }else{
            motor_set(mPower,ball_tracking_dir(fBallX,fBallY),get_bno055_yaw());
          }
        }
      }else if(isYELLOW_GOAL){
        if(isHOLD_F){
          escF.write(2000);
          if(fYellowDis < 50){
            kick();
          }else{
            motor_set(mPower,fYellowDir,get_bno055_yaw());
          }
        }else if(isHOLD_B){
          escB.write(2000);
          if(fYellowDis < 20){
            japan();
          }else{
            motor_set(mPower,fYellowDir,get_bno055_yaw());
          }
        }else{//青攻めでホールドしてないとき
          if(abs(fBallDir) < 80 ){
            escF.write(2000);
            motor_set(mPower,ball_tracking_dir(fBallX,fBallY),get_bno055_yaw());
          }else if(abs(fBallDir) < 60){
            motor_set(mPower,ball_tracking_dir(fBallX,fBallY),fBallDir);
          }else{
            motor_set(mPower,ball_tracking_dir(fBallX,fBallY),get_bno055_yaw());
          }
        }
      }
    }
  }else if(digitalRead(SW1) == LOW){
    motor_set(0,0,0);
    escF.write(1000);
    escB.write(1000);
  }

  /*if(digitalRead(SW1) == HIGH){
    if (ballX == 0 && ballY == 0){
      motor_set(0,0,0);
    }else if(isHOLD_F == true && isBLUE_GOAl == true){//青ゴール攻め、前でホールド
      motor_set(motorPower,ball_tracking_dir(fBlueX, fBlueY),0);
      kick(0);
    }else if(isHOLD_F == true && isYELLOW_GOAL == true){//黄ゴール攻め、前でホールド
      motor_set(motorPower,ball_tracking_dir(fYellowX, fYellowY),0);
    }else if(isHOLD_B == true && isBLUE_GOAl == true){//青ゴール攻め、後ろでホールド
      //makao-shot
    }else if(isHOLD_B == true && isYELLOW_GOAL == true){//黄ゴール攻め、後ろでホールド
      //makao-shoot
    }else{
      motor_set(motorPower,ball_tracking_dir(fBallX, fBallY),0);
    }
  }else if (digitalRead(SW1) == LOW){
    motor_set(0,0,0);
  }*/
}

/*
考慮すべき条件
攻め方向
ボールの角度と距離→ドリブラーの発動と方位修正のターゲット
ゴールの角度と距離→キックのタイミングと向き
ホールドされているか

*/