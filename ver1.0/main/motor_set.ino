
/* You have to add this code.
  pinMode(M1_dir,OUTPUT);
  pinMode(M2_dir,OUTPUT);
  pinMode(M3_dir,OUTPUT);
  pinMode(M4_dir,OUTPUT);

  #define M1_dir 6
  #define M2_dir 7
  #define M3_dir 8
  #define M4_dir 9
  #define M1_pwm 2
  #define M2_pwm 3
  #define M3_pwm 4
  #define M4_pwm 5
*/

void motor_pin_define()
{

  #define M1_pwm 2
  #define M2_pwm 3
  #define M3_pwm 4
  #define M4_pwm 5
  #define M1_dir 30
  #define M2_dir 31
  #define M3_dir 32
  #define M4_dir 33

  analogWriteFrequency(M1_pwm, 100000);
  analogWriteFrequency(M2_pwm, 100000);
  analogWriteFrequency(M3_pwm, 100000);
  analogWriteFrequency(M4_pwm, 100000);

  pinMode(M1_dir, OUTPUT);
  pinMode(M2_dir, OUTPUT);
  pinMode(M3_dir, OUTPUT);
  pinMode(M4_dir, OUTPUT);
}

void motor_set(int power, float move_dir, float initial_dir)
{

  if (move_dir < 0) {
    move_dir = move_dir + 360;
  }

  power = map(power,0,100,0,255);

  float yaw = get_bno055_yaw();
  yaw = yaw * 0.006;
  //Serial.println(yaw);

  float M1_power = (sin((move_dir - 45) * PI / 180) - yaw);
  float M2_power = (sin((move_dir - 135) * PI / 180) - yaw);
  float M3_power = (sin((move_dir - 225) * PI / 180) - yaw);
  float M4_power = (sin((move_dir - 315) * PI / 180) - yaw);

  float prepreMax =max(M1_power,M2_power);
  float preMax = max(prepreMax,M3_power);
  float Max = max(preMax,M4_power);

  M1_power = M1_power * power/Max;
  M2_power = M2_power * power/Max;
  M3_power = M3_power * power/Max;
  M4_power = M4_power * power/Max;

  //M1-------------------------------------------------
  if (M1_power > 0) {
    digitalWrite(M1_dir, LOW);
    analogWrite(M1_pwm, abs(M1_power));
  } else if (M1_power < 0) {
    digitalWrite(M1_dir, HIGH);
    analogWrite(M1_pwm, abs(M1_power));
  } else {
    digitalWrite(M1_dir, LOW);
    analogWrite(M1_pwm, 0);
  }
  //M2-------------------------------------------------
  if (M2_power > 0) {
    digitalWrite(M2_dir, LOW);
    analogWrite(M2_pwm, abs(M2_power));
  } else if (M2_power < 0) {
    digitalWrite(M2_dir, HIGH);
    analogWrite(M2_pwm, abs(M2_power));
  } else {
    digitalWrite(M2_dir, LOW);
    analogWrite(M2_pwm, 0);
  }
  //M3-------------------------------------------------
  if (M3_power > 0) {
    digitalWrite(M3_dir, LOW);
    analogWrite(M3_pwm, abs(M3_power));
  } else if (M3_power < 0) {
    digitalWrite(M3_dir, HIGH);
    analogWrite(M3_pwm, abs(M3_power));
  } else {
    digitalWrite(M3_dir, LOW);
    analogWrite(M3_pwm, 0);
  }
  //M4-------------------------------------------------
  if (M4_power > 0) {
    digitalWrite(M4_dir, LOW);
    analogWrite(M4_pwm, abs(M4_power));
  } else if (M4_power < 0) {
    digitalWrite(M4_dir, HIGH);
    analogWrite(M4_pwm, abs(M4_power));
  } else {
    digitalWrite(M4_dir, LOW);
    analogWrite(M4_pwm, 0);
  }
  /*Serial.print(M1_power);
  Serial.print("\t");
  Serial.print(M2_power);
  Serial.print("\t");
  Serial.print(M3_power);
  Serial.print("\t");
  Serial.print(M4_power);
  Serial.println("\t");*/
}
