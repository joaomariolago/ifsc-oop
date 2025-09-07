/**
 * @file main.cpp
 * @brief Clock task 3 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 03
 *
 * Create a class in C++ called **Clock** to store a time, composed of hour,
 * minute and second. The class must represent these time components and must
 * present the methods described below:
 *
 * - A method called **setTime**, which must receive the desired time as
 *   parameter (hour, minute and second)
 * - A method called **getTime** to return the current time, through 3
 *   variables passed by reference
 * - A method called **tick** to advance the time to the next second
 *   (remember to update the minute and hour when necessary)
 *
 */

#include <iostream>
#include <iomanip>

#include "clock.hpp"

/**
 * @brief Test the interface of the Clock class
 * @return void
 */
void test_clock()
{
    std::cout << "=== Testing the Clock Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating a clock with default constructor:" << std::endl;
    Clock clock1;
    clock1.printTime();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating a clock with constructor parameters:" << std::endl;
    Clock clock2(14, 30, 45);  /** 2:30:45 PM */
    clock2.printTime();
    std::cout << std::endl;

    /** Test 3: Testing setTime method */
    std::cout << "3. Testing the setTime method:" << std::endl;
    std::cout << "Setting time to 23:59:58..." << std::endl;
    clock2.setTime(23, 59, 58);
    clock2.printTime();
    std::cout << std::endl;

    /** Test 4: Testing tick method */
    std::cout << "4. Testing the tick method:" << std::endl;
    std::cout << "Ticking once..." << std::endl;
    clock2.tick();
    clock2.printTime();

    std::cout << "Ticking again..." << std::endl;
    clock2.tick();
    clock2.printTime();

    std::cout << "Ticking one more time..." << std::endl;
    clock2.tick();
    clock2.printTime();
    std::cout << std::endl;

    /** Test 5: Testing getTime method */
    std::cout << "5. Testing the getTime method:" << std::endl;
    uint8_t hour, minute, second;
    clock2.getTime(hour, minute, second);
    std::cout << "Retrieved time: "
              << std::setfill('0') << std::setw(2) << static_cast<int>(hour) << ":"
              << std::setfill('0') << std::setw(2) << static_cast<int>(minute) << ":"
              << std::setfill('0') << std::setw(2) << static_cast<int>(second) << std::endl;
    std::cout << std::endl;

    /** Test 6: Testing time normalization */
    std::cout << "6. Testing time normalization:" << std::endl;

    std::cout << "Setting time to 25:70:80 (invalid values)..." << std::endl;
    clock2.setTime(25, 70, 80);
    std::cout << "After normalization:" << std::endl;
    clock2.printTime();
    std::cout << std::endl;

    /** Test 7: Testing multiple ticks */
    std::cout << "7. Testing multiple ticks:" << std::endl;
    std::cout << "Starting time:" << std::endl;
    clock2.setTime(0, 0, 0);
    clock2.printTime();

    std::cout << "Ticking 10 times:" << std::endl;
    for (int i = 0; i < 10; i++) {
        clock2.tick();
        std::cout << "Tick " << (i + 1) << ": ";
        clock2.printTime();
    }
    std::cout << std::endl;

    /** Test 8: Testing edge cases */
    std::cout << "8. Testing edge cases:" << std::endl;

    std::cout << "Setting time to 23:59:59..." << std::endl;
    clock2.setTime(23, 59, 59);
    clock2.printTime();

    std::cout << "Ticking to test day rollover..." << std::endl;
    clock2.tick();
    clock2.printTime();
    std::cout << std::endl;

    /** Test 9: Testing another clock instance */
    std::cout << "9. Testing another clock instance:" << std::endl;
    Clock clock3(12, 0, 0);  /** Noon */
    std::cout << "New clock created:" << std::endl;
    clock3.printTime();

    std::cout << "Ticking 3600 times (1 hour)..." << std::endl;
    for (int i = 0; i < 3600; i++) {
        clock3.tick();
    }
    std::cout << "After 1 hour:" << std::endl;
    clock3.printTime();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_clock();
    return 0;
}
