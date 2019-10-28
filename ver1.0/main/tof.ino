  #define SENSOR_NUM  4 // 使用するセンサーの数
  #define ADDRESS_DEFALUT 0b01010010 // 0x52
  #define ADDRESS_00 (ADDRESS_DEFALUT + 2)

  const int XSHUT[SENSOR_NUM] = {10, 11, 12, 13};
  VL53L1X tof[SENSOR_NUM]; // 使用するセンサークラス配列


void tof_setup()
{
  for (int i = 0; i < SENSOR_NUM; i++)
  {
    pinMode(XSHUT[i], OUTPUT);
    digitalWrite(XSHUT[i], LOW);
  }

  Serial.println("Success!");

  for (int i = 0; i < SENSOR_NUM; i++) {

    pinMode(XSHUT[i], INPUT);// センサを初期化
    if (tof[i].init() == true)
    {
      tof[i].setTimeout(500);
      tof[i].setDistanceMode(VL53L1X::Long);
      tof[i].setMeasurementTimingBudget(50000);
      tof[i].startContinuous(50);
      int address = ADDRESS_00 + (i * 2);
      tof[i].setAddress(address);
    }
    else
    {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(" error");
    }
  }

  Serial.print("Success!!");
}

void get_tof()
{
  Serial.println(tof[1].read());
  if(tof[0].timeoutOccurred())
  {
    Serial.println("TIMEOUT");
  }
  /*if(tof_pos == "front")
  {
    return tof[0].read();
  }else if(tof_pos == "right")
  {
    return tof[1].read();
  }else if(tof_pos == "back")
  {
    return tof[2].read();
  }else if(tof_pos == "left")
  {
    return tof[3].read();
  }*/
}
