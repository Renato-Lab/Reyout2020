//int ballX,ballY,highByte_ballX,lowByte_ballX,highByte_ballY,lowByte_ballY;
//int blueGoalX,blueGoalY,highByte_blueGoalX,lowByte_blueGoalX,highByte_blueGoalY,lowByte_blueGoalY;
//int yellowGoalX,yellowGoalY,highByte_yellowGoalX,lowByte_yellowGoalX,highByte_yellowGoalY,lowByte_yellowGoalY;

void get_camera_data()
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
      Serial.print(ballX);
      Serial.print("\t");
      Serial.print(ballY);
      Serial.println("\t");
    }
  }
}
