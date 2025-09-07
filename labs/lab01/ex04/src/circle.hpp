#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>
#include <iostream>

class Circle
{
public:
    Circle() = default;
    Circle(double radius, double centerX = 0.0, double centerY = 0.0)
        : _radius{radius}
        , _centerX{centerX}
        , _centerY{centerY}
    {
    }

    void setRadius(double radius);
    void increaseRadius(double percentage);
    void setCenter(double x, double y);
    void printRadius() const;
    void printCenter() const;
    void printArea() const;

    inline double radius() const { return _radius; }
    inline double centerX() const { return _centerX; }
    inline double centerY() const { return _centerY; }

private:
    double calculateArea() const;
    double calculateDistance(const Circle& other) const;
    double calculateCircumference() const;

    double _radius;
    double _centerX;
    double _centerY;
};

#endif
