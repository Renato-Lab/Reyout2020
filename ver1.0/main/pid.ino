double Setpoint, Input, Output;
float pidOutput;
double Kp=0, Ki=0, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void pid_setup()
{
    Setpoint = 0;
    myPID.SetMode(AUTOMATIC);
}

void pid_compute()
{
    Input = get_bno055_yaw();
    myPID.Compute();
    pidOutput = Output;
}