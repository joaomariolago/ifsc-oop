/**
 * @file main.cpp
 * @brief Person task 1 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 01
 *
 * Create a class called **Person** to represent a person, with the private
 * attributes of name, age and height. Create the public methods necessary to
 * access and modify the attributes of this class and create a method to print
 * the person's data.
 * Implement a test program that uses the created class interface.
 */

#include <iostream>

#include "person.hpp"

/**
 * @brief Test the interface of the Person class
 * @return void
 */
void test_person()
{
    std::cout << "=== Testing the Person Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating a person with default constructor:" << std::endl;
    Person pessoa1;
    pessoa1.print();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating a person with constructor parameters:" << std::endl;
    Person pessoa2("João Silva", 25, 1.75);
    pessoa1.print();
    std::cout << std::endl;

    /** Test 3: Testing the getters methods */
    std::cout << "3. Testing the getters methods:" << std::endl;
    std::cout << "Name: " << pessoa2.name() << std::endl;
    std::cout << "Age: " << static_cast<int>(pessoa2.age()) << std::endl;
    std::cout << "Height: " << pessoa2.height() << std::endl;
    std::cout << std::endl;

    /** Test 4: Testing the setters methods */
    std::cout << "4. Testing the setters methods:" << std::endl;

    std::cout << "Changing name from 'João Silva' to 'João Silva Santos'..." << std::endl;
    pessoa2.name("João Silva Santos");

    std::cout << "Changing age from 25 to 26..." << std::endl;
    pessoa2.age(26);

    std::cout << "Changing height from 1.75 to 1.76..." << std::endl;
    pessoa2.height(1.76);

    std::cout << "Updated data:" << std::endl;
    pessoa2.print();
    std::cout << std::endl;

    /** Test 5: Creating another person for comparison */
    std::cout << "5. Creating another person for comparison:" << std::endl;
    Person pessoa3("Maria Santos", 30, 1.65);
    pessoa3.print();
    std::cout << std::endl;

    /** Test 6: Demonstrating that the changes do not affect other instances */
    std::cout << "6. Demonstrating that the changes do not affect other instances:" << std::endl;
    std::cout << "First person (after changes):" << std::endl;
    pessoa1.print();
    std::cout << std::endl;

    std::cout << "Second person (unaltered):" << std::endl;
    pessoa2.print();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_person();
    return 0;
}
