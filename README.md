# 这是一个基于 esp32-c3-devkitm-1 开发的小模块

> 查看不同的分支去寻找模块

1. [共阴极四位数码管](https://github.com/CnsMaple/esp32-c3-devkitm-1/tree/common-cathode-4seg)
   > 只接了共阴极四位数码管，主要功能是串口设置数字显示。
2. [oled12864](https://github.com/CnsMaple/esp32-c3-devkitm-1/tree/oled12864)
   > 只接了 oled12864，主要实现了屏幕的点亮并显示文字。
3. [touch 触摸开关](https://github.com/CnsMaple/esp32-c3-devkitm-1/tree/touch)
   > 只接了 touch 触摸开关，主要是获取了开关的信号。
4. [dht22 温湿度传感器](https://github.com/CnsMaple/esp32-c3-devkitm-1/tree/dht22)
   > 只接了 dht22 温湿度传感器，主要是实现数据获取。
5. [室内温度检测](https://github.com/CnsMaple/esp32-c3-devkitm-1/tree/dht22-oled12864-touch)
   > 使用了 touch 触摸开关，dht22 温湿度传感器，oled12864 屏幕，主要是实现数据获取，然后通过屏幕展示数据。
