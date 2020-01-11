

void get_cam_data(){
  if (Serial1.available() >= 13) {
    int head = Serial1.read();
    if (head == 128) {
      highByte_ballX = Serial1.read();
      lowByte_ballX = Serial1.read();
      highByte_ballY = Serial1.read();
      lowByte_ballY = Serial1.read();

      highByte_blueX = Serial1.read();
      lowByte_blueX = Serial1.read();
      highByte_blueY = Serial1.read();
      lowByte_blueY = Serial1.read();

      highByte_yellowX = Serial1.read();
      lowByte_yellowX = Serial1.read();
      highByte_yellowY = Serial1.read();
      lowByte_yellowY = Serial1.read();
    }
  }

  ballX = (highByte_ballX << 7) + lowByte_ballX;
  ballY = (highByte_ballY << 7) + lowByte_ballY;

  blueX = (highByte_blueX << 7) + lowByte_blueX;
  blueY = (highByte_blueY << 7) + lowByte_blueY;

  yellowX = (highByte_yellowX << 7) + lowByte_yellowX;
  yellowY = (highByte_yellowY << 7) + lowByte_yellowY;
}

void calc_cam_data(){

  //カメラの向きの問題で座標を入れ替えている。
  fBallX = ballY - CENTER_CAMERA_Y;
  fBallY = ballX - CENTER_CAMERA_X;
  fBlueX = blueY - CENTER_CAMERA_Y;
  fBlueY = blueX - CENTER_CAMERA_X;
  fYellowX = yellowY - CENTER_CAMERA_Y;
  fYellowY - yellowX - CENTER_CAMERA_X;

  fBallDis = sqrt(ballX * ballX + ballY * ballY);
  fBallDis = 0.01638 * (fBallDis * fBallDis) - 1.2726 * fBallDis + 34.105;
  fBallDir = atan2(ballX, ballY);
  fBallDir = fBallDir * 180 / PI;

  fBlueDis = sqrt(blueX * blueX + blueY * blueY);
  fBlueDis = 0.01638 * (fBlueDis * fBlueDis) - 1.2726 * fBlueDis + 34.105;
  fBlueDir = atan2(blueX, blueY);
  fBlueDir = fBlueDir * 180 / PI;

  fYellowDis = sqrt(yellowX * yellowX + yellowY * yellowY);
  fYellowDis = 0.01638 * (fYellowDis * fYellowDis) - 1.2726 * fYellowDis + 34.105;
  fYellowDir = atan2(yellowX, yellowY);
  fYellowDir = fYellowDir * 180/PI;


}

void print_camera_data(){
  Serial.print(fBallX);
  Serial.print("\t");
  Serial.print(fBallY);
  Serial.print("\t");
  Serial.print(fBallDir);
  Serial.print("\t");
  Serial.print(fBallDis);
  Serial.print("\t");
  Serial.print(fBlueX);
  Serial.print("\t");
  Serial.print(fBlueY);
  Serial.print("\t");
  Serial.print(fBlueDir);
  Serial.print("\t");
  Serial.print(fBlueDis);
  Serial.print("\t");
  Serial.print(fYellowX);
  Serial.print("\t");
  Serial.print(fYellowY);
  Serial.println("\t");
  Serial.print(fYellowDir);
  Serial.print("\t");
  Serial.print(fYellowDis);
  Serial.print("\t");
}
