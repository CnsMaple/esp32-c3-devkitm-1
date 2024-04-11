#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 设置屏幕分辨率为 128x64
Adafruit_SSD1306 display(128, 64, &Wire);

void setup()
{
  // 设置针脚，sda为2，scl为3
  Wire.setPins(2, 3);
  Serial.begin(115200);

  // 设置电压3.3v，然后设置默认的I2C地址为 0x3C (128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(128 / 2 - 32, 64 / 2 - 8);
  display.println("hello!");
  display.display();
}
void loop()
{
}