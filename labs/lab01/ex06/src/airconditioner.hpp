#ifndef AIRCONDITIONER_HPP
#define AIRCONDITIONER_HPP

#include <cstdint>
#include <iostream>

class AirConditioner
{
public:
    AirConditioner() = default;
    AirConditioner(uint8_t initialPower)
        : _power{initialPower}
        , _externalTemperature{25.0}
    {
        normalizePower();
    }

    void power(uint8_t power);
    bool increasePower();
    bool decreasePower();
    void turnOff();

    void externalTemperature(double temperature);
    double getRoomTemperature() const;

    inline uint8_t power() const { return _power; }
    inline double externalTemperature() const { return _externalTemperature; }
    inline bool isOn() const { return _power > 0; }

    void printStatus() const;

private:
    void normalizePower();

    uint8_t _power{0U};
    double _externalTemperature{25.0};
};

#endif
