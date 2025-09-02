#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <cstdint>
#include <iostream>

class Elevator
{
public:
    Elevator() = default;
    Elevator(uint8_t capacity, uint8_t totalFloors)
        : _currentFloor{0}
        , _totalFloors{totalFloors}
        , _capacity{capacity}
        , _currentOccupancy{0}
    {
    }

    bool enter();
    bool exit();
    bool goUp();
    bool goDown();

    inline uint8_t currentFloor() const { return _currentFloor; }
    inline uint8_t totalFloors() const { return _totalFloors; }
    inline uint8_t capacity() const { return _capacity; }
    inline uint8_t currentOccupancy() const { return _currentOccupancy; }

    void printStatus() const;

private:
    uint8_t _currentFloor;
    uint8_t _totalFloors;
    uint8_t _capacity;
    uint8_t _currentOccupancy;
};

#endif
