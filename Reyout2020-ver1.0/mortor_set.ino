void motor_set(int power, float move_dir, float initial_dir)
{
     const int M1_dir = 30;
     const int M2_dir = 31;
     const int M3_dir = 32;
     const int M4_dir = 33;
     const int M1_pwm = 2;
     const int M2_pwm = 3;
     const int M3_pwm = 4;
     const int M4_pwm = 5;

     M1_po1wer = sin((move_dir - 45) + (initial_dir - 45)) * power;
     M2_po1wer = sin((move_dir - 135) + (initial_dir - 135)) * power;
     M3_po1wer = sin((move_dir + 45) + (initial_dir + 45)) * power;
     M4_po1wer = sin((move_dir + 135) + (initial_dir + 135)) * power;

     //M1-------------------------------------------------
     if (M1_po1wer > 0) {
          digitalWrite(M1_dir, 0);
          analogWrite(M1_pwm, abs(M1_po1wer));
     } else if (M1_po1wer < 0) {
          digitalWrite(M1_dir, 1);
          analogWrite(M1_pwm, abs(M1_po1wer));
     } else {
          digitalWrite(M1_dir, 0);
          analogWrite(M1_pwm, 0);
     }
     //M2-------------------------------------------------
     if (M2_po1wer > 0) {
          digitalWrite(M2_dir, 0);
          analogWrite(M2_pwm, abs(M2_po1wer));
     } else if (M2_po1wer < 0) {
          digitalWrite(M2_dir, 1);
          analogWrite(M2_pwm, abs(M2_po1wer));
     } else {
          digitalWrite(M2_dir, 0);
          analogWrite(M2_pwm, 0);
     }
     //M3-------------------------------------------------
     if (M3_po1wer > 0) {
          digitalWrite(M3_dir, 0);
          analogWrite(M3_pwm, abs(M3_po1wer));
     } else if (M3_po1wer < 0) {
          digitalWrite(M3_dir, 1);
          analogWrite(M3_pwm, abs(M3_po1wer));
     } else {
          digitalWrite(M3_dir, 0);
          analogWrite(M3_pwm, 0);
     }
     //M4-------------------------------------------------
     if (M4_po1wer > 0) {
          digitalWrite(M4_dir, 0);
          analogWrite(M4_pwm, abs(M4_po1wer));
     } else if (M4_po1wer < 0) {
          digitalWrite(M1_dir, 1);
          analogWrite(M4_pwm, abs(M4_po1wer));
     } else {
          digitalWrite(M4_dir, 0);
          analogWrite(M4_pwm, 0);
     }
}