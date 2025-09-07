#include "television.hpp"

bool Television::increaseVolume()
{
    if (!_poweredOn) return false;

    if (_volume < 100) {
        _volume++;
        return true;
    }
    return false;
}

bool Television::decreaseVolume()
{
    if (!_poweredOn) return false;

    if (_volume > 0) {
        _volume--;
        return true;
    }
    return false;
}

void Television::setVolume(uint8_t volume)
{
    if (!_poweredOn) return;

    _volume = volume;
    normalizeValues();
}

bool Television::nextChannel()
{
    if (!_poweredOn) return false;

    if (_channel < 75) {
        _channel++;
        return true;
    }
    return false;
}

bool Television::previousChannel()
{
    if (!_poweredOn) return false;

    if (_channel > 0) {
        _channel--;
        return true;
    }
    return false;
}

void Television::setChannel(uint8_t channel)
{
    if (!_poweredOn) return;

    _channel = channel;
    normalizeValues();
}

void Television::normalizeValues()
{
    /** Normalize volume to 0-100 range */
    if (_volume > 100) {
        _volume = 100;
    }

    /** Normalize channel to 0-75 range */
    if (_channel > 75) {
        _channel = 75;
    }
}

void Television::printStatus() const
{
    std::cout << "========== Television Status ==========" << std::endl;
    std::cout << "Power: " << (_poweredOn ? "ON" : "OFF") << std::endl;
    std::cout << "Volume: " << static_cast<int>(_volume) << "/100" << std::endl;
    std::cout << "Channel: " << static_cast<int>(_channel) << "/75" << std::endl;
    std::cout << "=======================================" << std::endl;
}

void Television::powerOn()
{
    _poweredOn = true;
}

void Television::powerOff()
{
    _poweredOn = false;
}
