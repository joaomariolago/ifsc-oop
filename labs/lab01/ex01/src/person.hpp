#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <cstdint>
#include <iostream>

class Person
{
public:
    Person() = default;
    Person(std::string name, uint8_t age, float height)
        : _name{name}
        , _age{age}
        , _height{height}
    {
    }

    inline void name(const std::string &name) { _name = name; };
    inline void age(const uint8_t age) { _age = age; };
    inline void height(const float height) { _height = height; };

    inline std::string name() const { return _name; };
    inline uint8_t age() const { return _age; };
    inline float height() const { return _height; };

    void print() const;

private:
    std::string _name;
    uint8_t _age;
    float _height;
};

#endif
