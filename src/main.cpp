#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <string>

#include <iomanip>
#include <sstream>

// 设置屏幕分辨率为 128x64
// 一个1号字的大小是w:6，h:8
Adafruit_SSD1306 display(128, 64, &Wire);

#define DHTPIN 1

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // 设置针脚，sda为3，scl为2
  Wire.setPins(3, 2);
  Serial.begin(115200);

  // 设置电压3.3v，然后设置默认的I2C地址为 0x3C (128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(64 - 36, 32 - 8);
  display.println("Hello!");
  display.display();
}

bool isPress = false;
std::array<std::string, 3> dhtList = {"No Data", "No Data", "No Data"};
int dhtTimeCount = 0;
int delayTime = 10;

std::string getDHTStr(int index = -1)
{
  if (index == 0)
  {
    return dhtList[0];
  }
  else if (index == 1)
  {
    return dhtList[1];
  }
  else if (index == 2)
  {
    return dhtList[2];
  }
  else
  {
    std::string retStr = "";
    for (int i = 0; i < 3; i++)
    {
      retStr += dhtList[i];
      if (i != 2)
      {
        retStr += "\n";
      }
    }
    return retStr;
  }
}

static const unsigned char temp_icon[] = {
    0b01100000, 0b00000000,
    0b10010001, 0b11110100,
    0b10010110, 0b00001100,
    0b01101100, 0b00000100,
    0b00001000, 0b00000100,
    0b00011000, 0b00000000,
    0b00011000, 0b00000000,
    0b00011000, 0b00000000,
    0b00011000, 0b00000000,
    0b00011000, 0b00000000,
    0b00011000, 0b00000000,
    0b00001000, 0b00000000,
    0b00001100, 0b00000100,
    0b00000110, 0b00001000,
    0b00000001, 0b11110000,
    0b00000000, 0b00000000};

static const unsigned char precent_icon[] = {
    0b00000000, 0b00000000,
    0b00011000, 0b00000100,
    0b00100100, 0b00001000,
    0b00100100, 0b00010000,
    0b00100100, 0b00100000,
    0b00100100, 0b01000000,
    0b00100100, 0b10000000,
    0b00011001, 0b00000000,
    0b00000010, 0b01100000,
    0b00000100, 0b10010000,
    0b00001000, 0b10010000,
    0b00010000, 0b10010000,
    0b00100000, 0b10010000,
    0b01000000, 0b10010000,
    0b00000000, 0b01100000,
    0b00000000, 0b00000000};

void loop()
{
  delay(delayTime);
  dhtTimeCount += delayTime;
  if (dhtTimeCount >= 2000)
  {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t))
    {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    float hic = dht.computeHeatIndex(t, h, false);

    // 使用std::stringstream和流操作符来格式化浮点数
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << h;
    dhtList[0] = ss.str();

    ss.str("");
    ss.clear();

    ss << t;
    dhtList[1] = ss.str();

    ss.str("");
    ss.clear();
    ss << hic;
    dhtList[2] = ss.str();

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);

    display.setCursor(128 / 2 - 36, 64 / 2 - 24);
    display.println(getDHTStr(0).c_str());
    display.drawBitmap(128 / 2 + 30, 64 / 2 - 24, precent_icon, 16, 16, WHITE);

    display.setCursor(128 / 2 - 36, 64 / 2 - 8);
    display.println(getDHTStr(1).c_str());
    display.drawBitmap(128 / 2 + 30, 64 / 2 - 8, temp_icon, 16, 16, WHITE);

    display.setCursor(128 / 2 - 36, 64 / 2 + 8);
    display.println(getDHTStr(2).c_str());
    display.drawBitmap(128 / 2 + 30, 64 / 2 + 8, temp_icon, 16, 16, WHITE);

    display.display();

    dhtTimeCount = 0;
  }
  int sensorValue = digitalRead(10);
  if (sensorValue == 0 && isPress)
  {
    Serial.println("you release");
    isPress = false;
    Serial.println(getDHTStr().c_str());
  }
  else if (sensorValue == 1 && !isPress)
  {
    Serial.println("you press");
    isPress = true;
  }
}
