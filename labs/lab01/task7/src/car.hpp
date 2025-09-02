#ifndef CAR_HPP
#define CAR_HPP

#include <cstdint>
#include <iostream>

class Car
{
public:
    Car() = default;
    Car(double initialFuel)
        : _fuel{initialFuel}
        , _totalDistance{0.0}
    {
        normalizeFuel();
    }

    bool refuel(double liters);
    bool consumeFuel(double liters);

    bool move(double distance);

    inline double fuel() const { return _fuel; }
    inline double totalDistance() const { return _totalDistance; }
    inline double fuelEfficiency() const { return _fuelEfficiency; }
    inline double maxFuelCapacity() const { return _maxFuelCapacity; }

    void printStatus() const;
    double getRemainingRange() const;

private:
    void normalizeFuel();

    double _fuel{0.0};
    double _totalDistance{0.0};
    const double _maxFuelCapacity{50.0};
    const double _fuelEfficiency{15.0};
};

#endif
