#include <Arduino.h>

#include "ShowNum.h"

bool checkString(std::string str)
{
  if (str.empty())
  {
    return false;
  }
  else if (str.size() < 4 || str.size() > 8)
  {
    return false;
  }

  std::string retStr = "";
  bool preDot = false;
  int dotCount = 0;
  int digitCount = 0;
  for (int i = 0; i < str.size(); i++)
  {
    char c = str[i];
    if (c >= '0' && c <= '9')
    {
      retStr += c;
      digitCount++;
      if (preDot)
      {
        preDot = false;
      }
    }
    else if (c == '.')
    {
      if (preDot || i == 0)
      {
        return false;
      }
      else
      {
        preDot = true;
      }
      retStr += c;
      dotCount++;
    }
    else
    {
      return false;
    }
  }
  if (digitCount != 4)
  {
    return false;
  }
  return true;
}

// 这个是需要展示的数字
std::string numStore = "0000";
// 设置针脚，第一个是数字的，从a-g，第二个数字的位置，第三个是小数点
ShowNum showNum({1, 2, 3, 4, 5, 6, 7}, {0, 8, 9, 10}, 19);

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
    Serial.read(buffer, bufferSize);
    bool status = checkString((char *)buffer);
    Serial.println((char *)buffer);
    if (status)
    {
      numStore = (char *)buffer;
    }
    else
    {
      Serial.println("Invalid input");
    }
  }
}