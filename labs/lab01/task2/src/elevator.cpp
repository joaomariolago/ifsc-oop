#include "elevator.hpp"

bool Elevator::enter()
{
    if (_currentOccupancy < _capacity) {
        _currentOccupancy++;
        return true;
    }
    return false;
}

bool Elevator::exit()
{
    if (_currentOccupancy > 0) {
        _currentOccupancy--;
        return true;
    }
    return false;
}

bool Elevator::goUp()
{
    if (_currentFloor < _totalFloors) {
        _currentFloor++;
        return true;
    }
    return false;
}

bool Elevator::goDown()
{
    if (_currentFloor > 0) {
        _currentFloor--;
        return true;
    }
    return false;
}

void Elevator::printStatus() const
{
    std::cout << "========== Elevator Status ==========" << std::endl;
    std::cout << "Current Floor: " << static_cast<int>(_currentFloor) << std::endl;
    std::cout << "Total Floors: " << static_cast<int>(_totalFloors) << std::endl;
    std::cout << "Capacity: " << static_cast<int>(_capacity) << " people" << std::endl;
    std::cout << "Current Occupancy: " << static_cast<int>(_currentOccupancy) << " people" << std::endl;
    std::cout << "=====================================" << std::endl;
}
