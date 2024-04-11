#include "ShowNum.h"

ShowNum::ShowNum(std::array<uint8_t, 7> pin, std::vector<uint8_t> numLoc, uint8_t dot)
{
    this->pin = pin;
    this->numLoc = numLoc;
    this->numSize = this->numLoc.size();
    this->dot = dot;
    pinMode(this->dot, OUTPUT);
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

void ShowNum::setLoc(char loc)
{
    digitalWrite(this->dot, LOW);
    if (loc == '1')
    {
        digitalWrite(pin[0], LOW);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], LOW);
    }
    else if (loc == '2')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], LOW);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '3')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '4')
    {
        digitalWrite(pin[0], LOW);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '5')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], LOW);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '6')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], LOW);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '7')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], LOW);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], LOW);
        digitalWrite(pin[6], LOW);
    }
    else if (loc == '8')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '9')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], LOW);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], HIGH);
    }
    else if (loc == '0')
    {
        digitalWrite(pin[0], HIGH);
        digitalWrite(pin[1], HIGH);
        digitalWrite(pin[2], HIGH);
        digitalWrite(pin[3], HIGH);
        digitalWrite(pin[4], HIGH);
        digitalWrite(pin[5], HIGH);
        digitalWrite(pin[6], LOW);
    }
    else if (loc == '.')
    {
        digitalWrite(this->dot, HIGH);
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
    int numCount = -1;
    for (int i = 0; i < num.size(); i++)
    {
        char c = num[i];
        if (c >= '0' && c <= '9')
        {
            numCount++;
        }
        digitalWrite(numLoc[numCount], LOW);
        setLoc(c);
        delay(1);
        digitalWrite(numLoc[numCount], HIGH);
    }
}

uint8_t ShowNum::getNumSize()
{
    return this->numSize;
}
