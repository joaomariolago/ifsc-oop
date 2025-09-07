#include "airconditioner.hpp"
#include <cmath>

void AirConditioner::power(uint8_t power)
{
    _power = power;
    normalizePower();
}

bool AirConditioner::increasePower()
{
    if (_power < 10) {
        _power++;
        return true;
    }
    return false;
}

bool AirConditioner::decreasePower()
{
    if (_power > 0) {
        _power--;
        return true;
    }
    return false;
}

void AirConditioner::turnOff()
{
    _power = 0;
}

void AirConditioner::externalTemperature(double temperature)
{
    _externalTemperature = temperature;
}

double AirConditioner::getRoomTemperature() const
{
    /**
     * Each power unit decreases temperature by 1.8°C
     * Maximum decrease is 18°C (10 power units * 1.8°C)
     */
    double temperatureDecrease = _power * 1.8;
    return _externalTemperature - temperatureDecrease;
}

void AirConditioner::normalizePower()
{
    if (_power > 10) {
        _power = 10;
    }
}

void AirConditioner::printStatus() const
{
    std::cout << "========== Air Conditioner Status ==========" << std::endl;
    std::cout << "Power Level: " << static_cast<int>(_power) << "/10" << std::endl;
    std::cout << "Status: " << (isOn() ? "ON" : "OFF") << std::endl;
    std::cout << "External Temperature: " << _externalTemperature << "°C" << std::endl;
    std::cout << "Room Temperature: " << getRoomTemperature() << "°C" << std::endl;
    std::cout << "Temperature Decrease: " << (_power * 1.8) << "°C" << std::endl;
    std::cout << "=============================================" << std::endl;
}
