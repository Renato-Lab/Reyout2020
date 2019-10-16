#include <Wire.h>

void setup()
{
    Serial.begin(115200);
    pinMode(13,OUTPUT);
}

void loop()
{
    digitalWrite(13,HIGH);
    delay(50);
    digitalWrite(13,LOW);
    delay(50);

    if (Data>0)
    {
        digitalWrite(13,HIGH);
    }else
    {
        digitalWrite(13,LOW);
    }

    Serial.print("Hello,World");
}