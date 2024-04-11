#include <Arduino.h>

// 设置传感器引脚
int Sensor_pin = 2;

void setup()
{
  Serial.begin(115200);
}
void loop()
{
  int sensorValue = digitalRead(Sensor_pin);
  Serial.println(sensorValue);
  delay(100);
}