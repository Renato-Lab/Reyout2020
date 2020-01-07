//int ballX,ballY,ballQty,highByte_ballX,lowByte_ballX,highByte_ballY,lowByte_ballY,highByte_qty_ball,lowByte_qty_ball;
//int blueGoalX,blueGoalY,blueGoalQty,highByte_blueGoalX,lowByte_blueGoalX,highByte_blueGoalY,lowByte_blueGoalY,highByte_qty_blue_goal,lowByte_qty_blue_goal;
//int yellowGoalX,yellowGoalY,yellowGoalQty,highByte_yellowGoalX,lowByte_yellowGoalX,highByte_yellowGoalY,lowByte_yellowGoalY,highByte_qty_yellow_goal,lowByte_qty_yellow_goal;

void get_camera_data()
{
    if (Serial1.available() >= 16) {
    int head = Serial1.read();
    if (head == 128) {
      highByte_ballX = Serial1.read();
      lowByte_ballX = Serial1.read();
      highByte_ballY = Serial1.read();
      lowByte_ballY = Serial1.read();
      //highByte_qty_ball = Serial.read();
      //lowByte_qty_ball = Serial.read();
      ballQty = Serial.read();
      highByte_blueGoalX = Serial1.read();
      lowByte_blueGoalX = Serial1.read();
      highByte_blueGoalY = Serial1.read();
      lowByte_blueGoalY = Serial1.read();
      //highByte_qty_blue_goal = Serial1.read();
      //lowByte_qty_blue_goal = Serial1.read();
      blueGoalQty = Serial.read();
      highByte_yellowGoalX = Serial1.read();
      lowByte_yellowGoalX = Serial1.read();
      highByte_yellowGoalY = Serial1.read();
      lowByte_yellowGoalY = Serial1.read();
      //highByte_qty_yellow_goal = Serial1.read();
      //lowByte_qty_yellow_goal = Serial1.read();
      yellowGoalQty = Serial.read();
      
      ballX = (highByte_ballX << 7) + lowByte_ballX;
      ballY = (highByte_ballY << 7) + lowByte_ballY;
      //ballQty = (highByte_qty_ball << 7) + lowByte_qty_ball;
      blueGoalX = (highByte_blueGoalX << 7) + lowByte_blueGoalX;
      blueGoalY = (highByte_blueGoalY << 7) + lowByte_blueGoalY;
      //blueGoalQty = (highByte_qty_blue_goal << 7) + lowByte_qty_blue_goal;
      yellowGoalX = (highByte_yellowGoalX << 7) + lowByte_yellowGoalX;
      yellowGoalY = (highByte_yellowGoalY << 7) + lowByte_yellowGoalY;
      //yellowGoalQty = (highByte_qty_yellow_goal << 7) + lowByte_qty_yellow_goal;

      //カメラの向きの問題で座標を入れ替えている。
      fixedBallX = ballY - CENTER_CAMERA_Y;
      fixedBallY = ballX - CENTER_CAMERA_X;
      fixedBlueGoalX = blueGoalY - CENTER_CAMERA_Y;
      fixedBlueGoalY = blueGoalX - CENTER_CAMERA_X;
      fixedYellowGoalX = yellowGoalY - CENTER_CAMERA_Y;
      fixedYellowGoalY - yellowGoalX - CENTER_CAMERA_X;
    }
  }
}

void print_camera_data(){
  Serial.print(ballX);
  Serial.print("\t");
  Serial.print(ballY);
  Serial.print("\t");
  Serial.print(blueGoalX);
  Serial.print("\t");
  Serial.print(blueGoalY);
  Serial.print("\t");
  Serial.print(yellowGoalX);
  Serial.print("\t");
  Serial.print(yellowGoalY);
  Serial.println("\t");
}
