Adafruit_BNO055 bno = Adafruit_BNO055(55,0x28);

void bno055_setup()
{
    // Check I2C device address and correct line below (by default address is 0x29 or 0x28)
    //                                   id, address
    
    /* Initialise the sensor */
    if (!bno.begin())
    {
        for(int i = 0;i < 5; i++){
            digitalWrite(SW2,HIGH);
            delay(100);
            digitalWrite(SW2,LOW);
            delay(100);
        }
        
  
        /* There was a problem detecting the BNO055 ... check your connections */
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
        while (1);
    }

    bno.setExtCrystalUse(true);
    Serial.print("bno055 setup success!!");
}


double get_bno055_yaw()
{
    sensors_event_t event;
    bno.getEvent(&event);
    double x = -1000000;

    x = event.orientation.x;

    if(x > 180)
    {
        x = x-360;
    }

    return x;

    /*Serial.print(": x= ");
    Serial.print(x);
    Serial.print(" | y= ");
    Serial.print(y);
    Serial.print(" | z= ");
    Serial.print(z);
    Serial.println();*/
    
}

double get_bno055_pitch()
{
    sensors_event_t event;
    bno.getEvent(&event);
    double y = -1000000;

    y = event.orientation.y;

    if(y > 180)
    {
        y = y - 360;
    }

    return y;
}

double get_bno055_roll()
    {sensors_event_t event;
    bno.getEvent(&event);
    double z = -1000000;

    z = event.orientation.z;

    if(z > 180)
    {
        z = z-360;
    }

    return z;
}