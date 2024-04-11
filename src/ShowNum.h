#ifndef SHOWNUM_H
#define SHOWNUM_H

#include <array>
#include <vector>
#include <Arduino.h>

class ShowNum
{
public:
    ShowNum(std::array<uint8_t, 7> pin, std::vector<uint8_t> numLoc,uint8_t dot);

    void setLoc(char num);

    void setNum(std::string num);

    uint8_t getNumSize();

private:
    std::array<uint8_t, 7> pin;
    std::vector<uint8_t> numLoc;
    uint8_t dot;
    uint8_t numSize;
};

#endif // !SHOWNUM_H