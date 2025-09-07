#include "circle.hpp"

void Circle::setRadius(double radius)
{
    if (radius > 0) {
        _radius = radius;
    }
}

void Circle::increaseRadius(double percentage)
{
    if (percentage > 0) {
        _radius *= (1.0 + percentage / 100.0);
    }
}

void Circle::setCenter(double x, double y)
{
    _centerX = x;
    _centerY = y;
}

void Circle::printRadius() const
{
    std::cout << "========== Circle Radius ==========" << std::endl;
    std::cout << "Radius: " << _radius << " units" << std::endl;
    std::cout << "===================================" << std::endl;
}

void Circle::printCenter() const
{
    std::cout << "========== Circle Center ==========" << std::endl;
    std::cout << "Center: (" << _centerX << ", " << _centerY << ")" << std::endl;
    std::cout << "===================================" << std::endl;
}

void Circle::printArea() const
{
    std::cout << "========== Circle Area ==========" << std::endl;
    std::cout << "Area: " << calculateArea() << " square units" << std::endl;
    std::cout << "=================================" << std::endl;
}

double Circle::calculateArea() const
{
    return M_PI * _radius * _radius;
}

double Circle::calculateDistance(const Circle& other) const
{
    double dx = _centerX - other._centerX;
    double dy = _centerY - other._centerY;
    return std::sqrt(dx * dx + dy * dy);
}

double Circle::calculateCircumference() const
{
    return 2.0 * M_PI * _radius;
}
