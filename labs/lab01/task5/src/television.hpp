#ifndef TELEVISION_HPP
#define TELEVISION_HPP

#include <cstdint>
#include <iostream>

class Television
{
public:
    Television() = default;
    Television(uint8_t initialVolume, uint8_t initialChannel)
        : _volume{initialVolume}
        , _channel{initialChannel}
    {
        normalizeValues();
    }

    bool increaseVolume();
    bool decreaseVolume();
    void setVolume(uint8_t volume);

    bool nextChannel();
    bool previousChannel();
    void setChannel(uint8_t channel);

    inline uint8_t volume() const { return _volume; }
    inline uint8_t channel() const { return _channel; }

    void printStatus() const;
    void powerOn();
    void powerOff();
    inline bool isOn() const { return _poweredOn; }

private:
    void normalizeValues();

    uint8_t _volume;
    uint8_t _channel;
    bool _poweredOn{true};
};

#endif
