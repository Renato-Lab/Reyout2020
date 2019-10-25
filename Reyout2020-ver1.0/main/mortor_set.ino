
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


void motor_set(int power, float move_dir, float initial_dir)
{




     float M1_power = (sin((move_dir - 45) * PI / 180) + initial_dir) * power;
     float M2_power = (sin((move_dir - 135) * PI / 180) + initial_dir) * power;
     float M3_power = (sin((move_dir - 225) * PI / 180) + initial_dir) * power;
     float M4_power = (sin((move_dir - 315) * PI / 180) + initial_dir) * power;

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
          digitalWrite(M1_dir, HIGH);
          analogWrite(M4_pwm, abs(M4_power));
     } else {
          digitalWrite(M4_dir, LOW);
          analogWrite(M4_pwm, 0);
     }
}