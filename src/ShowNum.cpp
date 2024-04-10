#include "ShowNum.h"

ShowNum::ShowNum(std::array<uint8_t, 7> pin, std::vector<uint8_t> numLoc)
{
    this->pin = pin;
    this->numLoc = numLoc;
    this->numSize = this->numLoc.size();
    for (auto i : this->pin)
    {
        pinMode(i, OUTPUT);
    }

    for (auto i : this->numLoc)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }
}

void ShowNum::setNum(char num)
{
    if (num == '1')
    {
        digitalWrite(pin[0], LOW);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], LOW);
    }
    else if (num == '2')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], LOW);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '3')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '4')
    {
        digitalWrite(pin[0], LOW);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '5')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], LOW);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '6')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], LOW);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '7')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], LOW);
    }
    else if (num == '8')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '9')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (num == '0')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], LOW);
    }
    else
    {
        digitalWrite(pin[0], LOW);
        digitalWrite(pin[1], LOW);
        digitalWrite(pin[2], LOW);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], LOW);
    }
}

void ShowNum::setNum(std::string num)
{
    if (num.size() != this->numLoc.size())
    {
        return;
    }

    for (int i = 0; i < num.size(); i++)
    {
        digitalWrite(numLoc[i], LOW);
        setNum(num[i]);
        delay(1);
        digitalWrite(numLoc[i], HIGH);
    }
}

uint8_t ShowNum::getNumSize()
{
    return this->numSize;
}
