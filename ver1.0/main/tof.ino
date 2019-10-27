  #define SENSOR_NUM  4 // 使用するセンサーの数
  #define ADDRESS_DEFALUT 0b0101001 // 0x29
  #define ADDRESS_00 (ADDRESS_DEFALUT + 2)

  const int XSHUT[SENSOR_NUM] = {34, 35, 36, 37};
  VL53L1X tof[SENSOR_NUM]; // 使用するセンサークラス配列


void tof_setup()
{

  for (int i = 0; i < SENSOR_NUM; i++)
  {
    pinMode(XSHUT[i], OUTPUT);
    digitalWrite(XSHUT[i], LOW);
  }

  for (int i = 0; i < SENSOR_NUM; i++) {

    pinMode(XSHUT[i], INPUT);// センサを初期化
    if (tof[i].init() == true)
    {
      tof[i].setTimeout(1000);
      tof[i].startContinuous(10);
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
}

int get_tof(char tof_pos)
{
  int distance = 0;
  if(tof_pos == "front")
  {
    return tof[0].readRangeContinuousMillimeters() / 10;
  }else if(tof_pos == "right")
  {
    return tof[1].readRangeContinuousMillimeters() / 10;
  }else if(tof_pos == "back")
  {
    return tof[2].readRangeContinuousMillimeters() / 10;
  }else if(tof_pos == "left")
  {
    return tof[3].readRangeContinuousMillimeters() / 10;
  }
}
