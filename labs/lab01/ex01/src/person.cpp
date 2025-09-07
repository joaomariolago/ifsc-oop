#include "person.hpp"

void Person::print() const
{
    std::cout << "========== Person Details ==========" << std::endl;
    std::cout << "Nome: " << name() << std::endl;
    std::cout << "Idade: " << static_cast<int>(age()) << " anos" << std::endl;
    std::cout << "Altura: " << height() << " m" << std::endl;
    std::cout << "=====================================" << std::endl;
}
