  #define SENSOR_NUM  4 // 使用するセンサーの数
  #define ADDRESS_DEFALUT 0b01010010 // 0x52
  #define ADDRESS_00 (ADDRESS_DEFALUT + 2)

  const int XSHUT[SENSOR_NUM] = {9, 10, 11, 12};
  VL53L1X tof[SENSOR_NUM]; // 使用するセンサークラス配列


void tof_setup()
{
  for (int i = 0; i < SENSOR_NUM; i++)
  {
    pinMode(XSHUT[i], OUTPUT);
    digitalWrite(XSHUT[i], LOW);
    Serial.print(i);
    Serial.println("  off");
  }

  for (int i = 0; i < SENSOR_NUM; i++) {

    pinMode(XSHUT[i], INPUT);// センサを初期化

    Serial.print("XSHUT");
    Serial.print(i);
    Serial.println("INPUT");
    //digitalWrite(SW2,HIGH);
    //delay(500);
    
    
    
    if (tof[i].init() == true){
      Serial.print(i);
      Serial.println("  true");
      tof[i].setTimeout(500);
      tof[i].setDistanceMode(VL53L1X::Long);
      tof[i].setMeasurementTimingBudget(50000);
      tof[i].startContinuous(50);
      int address = ADDRESS_00 + (i * 2);
      tof[i].setAddress(address);
    }else{
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(" error");
    }
    //digitalWrite(SW2,LOW);
    //delay(500);
    }
  Serial.println("tof setup success!!");
}

float get_distance_VL53L1X(int tof_pos)
{
  float distance = 0;

  if(tof_pos == 1)
  {
    distance = tof[0].read();
    return distance;
  }else if(tof_pos == 2)
  {
    distance = tof[1].read();
    return distance;
  }else if(tof_pos == 3)
  {
    distance = tof[2].read();
    return distance;
  }else if(tof_pos == 4)
  {
    distance = tof[3].read();
    return distance;
  }
}
