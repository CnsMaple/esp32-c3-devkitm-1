#include <Arduino.h>

#include "ShowNum.h"

// warning: 这里要修改成对应的引脚
std::array<uint8_t, 7> numPin = {1, 2, 3, 4, 5, 6, 7};
std::vector<uint8_t> numLoc = {0, 8, 9, 10};

std::string numStore = "1234";
ShowNum showNum(numPin, numLoc);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  showNum.setNum(numStore);
  if (Serial.available() > 0)
  {
    uint8_t bufferSize = 16;
    uint8_t buffer[bufferSize];
    int incomingByte = Serial.read(buffer, bufferSize);
    if (incomingByte > showNum.getNumSize())
    {
      incomingByte = showNum.getNumSize();
    }
    std::string str = "";
    for (int i = 0; i < showNum.getNumSize() && i < incomingByte; i++)
    {
      char c = (char)buffer[i];
      if (c >= '0' && c <= '9')
      {
        str += c;
      }
    }
    for (int i = 0; i < showNum.getNumSize() - incomingByte; i++)
    {
      str = "0" + str;
    }
    numStore = str;
  }
}