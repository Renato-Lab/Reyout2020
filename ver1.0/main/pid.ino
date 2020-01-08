
float calc_pid(float target, float kp, float ki, float kd){
    float preTime, dt, gap, I, D, preGap, duty;
    dt = (micros() - preTime) / 1000000;
    preTime = micros();

    gap  = target - get_bno055_yaw();
    I += gap * dt;
    D  = (gap - preGap) / dt;
    preGap = gap;
    return duty += kp * gap + ki * I + kd * D;
}

