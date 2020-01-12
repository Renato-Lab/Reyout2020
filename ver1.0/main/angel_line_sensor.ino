#define QTY_LINE 24
#define BORDER_WHITE_F 984
#define BORDER_WHITE_R 984
#define BORDER_WHITE_B 984
#define BORDER_WHITE_L 984

#define SENS_F 21
#define SENS_R 20
#define SENS_B 16
#define SENS_L 17
#define SAMPLE_NUM 30

int bufF, bufR, bufB, bufL;
int valF, valR, valB, valL;

void check_line(){
    for(int i = 0; i <SAMPLE_NUM; i++){
        bufF += analogRead(SENS_F);
        bufR += analogRead(SENS_R);
        bufB += analogRead(SENS_B);
        bufL += analogRead(SENS_L);
    }
    valF = bufF / SAMPLE_NUM;
    valR = bufR / SAMPLE_NUM;
    valB = bufB / SAMPLE_NUM;
    valL = bufL / SAMPLE_NUM;

    Serial.print(valF);
    Serial.print("\t");
    Serial.print(valR);
    Serial.print("\t");
    Serial.print(valB);
    Serial.print("\t");
    Serial.println(valL);

    if(valF > BORDER_WHITE_F){
        motor_set(50,180,get_bno055_yaw());
        delay(500);
    }else if(valR > BORDER_WHITE_R){
        motor_set(50,270,get_bno055_yaw());
        delay(500);
    }else if(valB > BORDER_WHITE_B){
        motor_set(50,0,get_bno055_yaw());
        delay(500);
    }else if(valL > BORDER_WHITE_L){
        motor_set(50,90,get_bno055_yaw());
        delay(500);
    }

    bufF = 0;
    bufR = 0;
    bufB = 0;
    bufL = 0;
}
