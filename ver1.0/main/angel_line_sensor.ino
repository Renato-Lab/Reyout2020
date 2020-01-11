#define QTY_LINE 24
#define BORDER_WHITE 800

#define SENS_F 16
#define SENS_R 17
#define SENS_B 20
#define SENS_L 21
#define SAMPLE_NUM 100

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

    if(valF > BORDER_WHITE){
        motor_set(100,180,get_bno055_yaw());
        delay(500);
    }else if(valR > BORDER_WHITE){
        motor_set(100,270,get_bno055_yaw());
        delay(500);
    }else if(valB > BORDER_WHITE){
        motor_set(100,0,get_bno055_yaw());
        delay(500);
    }else if(valL > BORDER_WHITE){
        motor_set(100,90,get_bno055_yaw());
        delay(500);
    }
}
