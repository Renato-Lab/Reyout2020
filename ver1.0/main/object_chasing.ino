float ball_tracking_dir(float X,float Y)
{
    float a = 28.59776;
    float b = 1.41069;
    float c = -0.86659;
    float d = -0.00139;
    float e = -0.00138;
    float f = 0.00578;

    float dis = sqrt(X * X + Y * Y);
    dis = 0.01638*(dis*dis) - 1.2726*dis + 34.105;
    float dir = atan2(X,Y);
    dir = dir * 180/PI;

    if (dir < 0) {
        move_dir = -(a + b * abs(dir) + c * abs(dis) + d * (dir * dir) + e * abs(dir) * abs(dis) + f * (dis * dis));
    } else if (dir > 0) {
        move_dir = a + b * abs(dir) + c * abs(dis) + d * (dir * dir) + e * abs(dir) * abs(dis) + f * (dis * dis);
    }
    return move_dir;
}

void check_hold(){
    if(analogRead(HOLD_F) < 15){
        isHOLD_F = true;
    }else{
        isHOLD_F = false;
    }

    if(analogRead(HOLD_B) < 15){
        isHOLD_B = true;
    }else{
        isHOLD_B = false;
    }
}




//30  y=-20000000x^5 + 700000x^4 - 0.008x^3 + 0.4593x^2 -12.625x + 162.33 
//40  y=4000000x^4 - 0.001x^3 + 0.1019x^2 - 4.4784x + 113.25
//50  y=-0.0002x^3 + 0.0329x^2 - 2.3744x + 117.27
//60  y=-0.0002x^3 + 0.0391x^2 - 2.7979x + 138.1
//70  y=-0.0002x^3 + 0.-0359x^2 - 2.5849x + 143.6
//80  y=-0.0002x^3 + 0.034x^2 - 2.5491x + 151.53
//90  y=-0.0002x^3 + 0.0465x^2 -3.1679x + 172.63
//100 y=-0.0001x^3 + 0.0315x^2 - 2.3492x +170.63
//110 y=-0.0001x^3 + 0.0344x^2 - 2.5375x + 185.93
//120 y=-10000x^3 + 0.0238x^2 -1.9706x + 186.03
//130 y=-0.0001x^3 + 0.0293x^2 - 1.9825x + 196.73
//140 y=-0.0002x^3 + 0.0428x^2 -3.0051x + 222.77
//150 y = -0.0002x3 + 0.0331x2 - 2.4063x + 220
//160 y = -0.0001x3 + 0.0242x2 - 1.8529x + 220.37
//170 y = -0.0002x3 + 0.0343x2 - 2.4699x + 241.67
//180 y = -0.0001x3 + 0.0312x2 - 2.2542x + 246.97


