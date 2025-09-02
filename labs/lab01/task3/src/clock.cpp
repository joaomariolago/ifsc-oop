#include "clock.hpp"
#include <iomanip>

void Clock::setTime(uint8_t hour, uint8_t minute, uint8_t second)
{
    _hour = hour;
    _minute = minute;
    _second = second;
    normalizeTime();
}

void Clock::getTime(uint8_t& hour, uint8_t& minute, uint8_t& second) const
{
    hour = _hour;
    minute = _minute;
    second = _second;
}

void Clock::tick()
{
    _second++;
    normalizeTime();
}

void Clock::normalizeTime()
{
    if (_second >= 60) {
        _minute += _second / 60;
        _second %= 60;
    }

    if (_minute >= 60) {
        _hour += _minute / 60;
        _minute %= 60;
    }

    if (_hour >= 24) {
        _hour %= 24;
    }
}

void Clock::printTime() const
{
    std::cout << "========== Clock Time ==========" << std::endl;
    std::cout << "Current Time: "
              << std::setfill('0') << std::setw(2) << static_cast<int>(_hour) << ":"
              << std::setfill('0') << std::setw(2) << static_cast<int>(_minute) << ":"
              << std::setfill('0') << std::setw(2) << static_cast<int>(_second) << std::endl;
    std::cout << "===============================" << std::endl;
}
