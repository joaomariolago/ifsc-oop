#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <cstdint>
#include <iostream>

class Clock
{
public:
    Clock() = default;
    Clock(uint8_t hour, uint8_t minute, uint8_t second)
        : _hour{hour}
        , _minute{minute}
        , _second{second}
    {
        normalizeTime();
    }

    void setTime(uint8_t hour, uint8_t minute, uint8_t second);

    void getTime(uint8_t& hour, uint8_t& minute, uint8_t& second) const;

    void tick();

    void printTime() const;

private:
    void normalizeTime();

    uint8_t _hour;
    uint8_t _minute;
    uint8_t _second;
};

#endif
