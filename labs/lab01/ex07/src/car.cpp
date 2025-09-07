#include "car.hpp"
#include <cmath>
#include <iomanip>

bool Car::refuel(double liters)
{
    if (liters <= 0) {
        return false;
    }

    if (_fuel + liters <= _maxFuelCapacity) {
        _fuel += liters;
        return true;
    } else {
        /** Fill to maximum capacity */
        _fuel = _maxFuelCapacity;
        return true;
    }
}

bool Car::consumeFuel(double liters)
{
    if (liters <= 0) {
        return false;
    }

    if (_fuel >= liters) {
        _fuel -= liters;
        return true;
    }
    return false;
}

bool Car::move(double distance)
{
    if (distance <= 0) {
        return false;
    }

    /** Calculate fuel needed for this distance */
    double fuelNeeded = distance / _fuelEfficiency;

    if (_fuel >= fuelNeeded) {
        _fuel -= fuelNeeded;
        _totalDistance += distance;
        return true;
    }
    return false;
}

void Car::normalizeFuel()
{
    if (_fuel > _maxFuelCapacity) {
        _fuel = _maxFuelCapacity;
    }
    if (_fuel < 0) {
        _fuel = 0;
    }
}

void Car::printStatus() const
{
    std::cout << "========== Car Status ==========" << std::endl;
    std::cout << "Current Fuel: " << std::fixed << std::setprecision(2)
              << _fuel << "/" << _maxFuelCapacity << " liters" << std::endl;
    std::cout << "Fuel Efficiency: " << _fuelEfficiency << " km/liter" << std::endl;
    std::cout << "Total Distance Traveled: " << _totalDistance << " km" << std::endl;
    std::cout << "Remaining Range: " << getRemainingRange() << " km" << std::endl;
    std::cout << "===============================" << std::endl;
}

double Car::getRemainingRange() const
{
    return _fuel * _fuelEfficiency;
}
