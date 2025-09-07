/**
 * @file main.cpp
 * @brief Elevator task 2 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 02
 *
 * Create a class called **Elevator** to store information about an elevator
 * in a building. The class must store the current floor (0 = ground floor),
 * total floors in the building (excluding ground floor), elevator capacity,
 * and how many people are currently in it.
 *
 * The class must implement the following interface:
 * - Constructor: Must receive as parameters: elevator capacity and total
 *   floors in the building (elevators always start at ground floor and empty)
 * - enter: Add a person to the elevator (only add if there's still space)
 * - exit: Remove a person from the elevator (only remove if there's someone inside)
 * - goUp: Go up one floor (should not go up if already at the top floor)
 * - goDown: Go down one floor (should not go down if already at ground floor)
 * - Access methods: Return the value of each class attribute
 *
 */

#include <iostream>

#include "elevator.hpp"

/**
 * @brief Test the interface of the Elevator class
 * @return void
 */
void test_elevator()
{
    std::cout << "=== Testing the Elevator Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating an elevator with default constructor:" << std::endl;
    Elevator elevator1;
    elevator1.printStatus();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating an elevator with constructor parameters:" << std::endl;
    Elevator elevator2(8, 10);
    elevator2.printStatus();
    std::cout << std::endl;

    /** Test 3: Testing getter methods */
    std::cout << "3. Testing the getter methods:" << std::endl;
    std::cout << "Current Floor: " << static_cast<int>(elevator2.currentFloor()) << std::endl;
    std::cout << "Total Floors: " << static_cast<int>(elevator2.totalFloors()) << std::endl;
    std::cout << "Capacity: " << static_cast<int>(elevator2.capacity()) << std::endl;
    std::cout << "Current Occupancy: " << static_cast<int>(elevator2.currentOccupancy()) << std::endl;
    std::cout << std::endl;

    /** Test 4: Testing people entering and exiting */
    std::cout << "4. Testing people entering and exiting:" << std::endl;

    std::cout << "People entering the elevator:" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (elevator2.enter()) {
            std::cout << "Person " << (i + 1) << " entered successfully" << std::endl;
        } else {
            std::cout << "Person " << (i + 1) << " could not enter (elevator full)" << std::endl;
        }
    }
    elevator2.printStatus();
    std::cout << std::endl;

    std::cout << "People exiting the elevator:" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (elevator2.exit()) {
            std::cout << "Person " << (i + 1) << " exited successfully" << std::endl;
        } else {
            std::cout << "Person " << (i + 1) << " could not exit (elevator empty)" << std::endl;
        }
    }
    elevator2.printStatus();
    std::cout << std::endl;

    /** Test 5: Testing elevator movement */
    std::cout << "5. Testing elevator movement:" << std::endl;

    std::cout << "Going up floors:" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (elevator2.goUp()) {
            std::cout << "Elevator went up to floor " << static_cast<int>(elevator2.currentFloor()) << std::endl;
        } else {
            std::cout << "Elevator cannot go up further (already at top floor)" << std::endl;
        }
    }
    elevator2.printStatus();
    std::cout << std::endl;

    std::cout << "Going down floors:" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (elevator2.goDown()) {
            std::cout << "Elevator went down to floor " << static_cast<int>(elevator2.currentFloor()) << std::endl;
        } else {
            std::cout << "Elevator cannot go down further (already at ground floor)" << std::endl;
        }
    }
    elevator2.printStatus();
    std::cout << std::endl;

    /** Test 6: Testing edge cases */
    std::cout << "6. Testing edge cases:" << std::endl;

    std::cout << "Trying to go up beyond the top floor:" << std::endl;
    for (int i = 0; i < 15; i++) {
        if (!elevator2.goUp()) {
            std::cout << "Elevator stopped at floor " << static_cast<int>(elevator2.currentFloor())
                      << " (cannot go higher)" << std::endl;
            break;
        }
    }

    std::cout << "Trying to go down below ground floor:" << std::endl;
    for (int i = 0; i < 15; i++) {
        if (!elevator2.goDown()) {
            std::cout << "Elevator stopped at floor " << static_cast<int>(elevator2.currentFloor())
                      << " (cannot go lower)" << std::endl;
            break;
        }
    }

    std::cout << "Trying to fill elevator beyond capacity:" << std::endl;
    for (int i = 0; i < 15; i++) {
        if (!elevator2.enter()) {
            std::cout << "Elevator is full at " << static_cast<int>(elevator2.currentOccupancy())
                      << " people (capacity: " << static_cast<int>(elevator2.capacity()) << ")" << std::endl;
            break;
        }
    }

    std::cout << "Trying to remove people from empty elevator:" << std::endl;
    for (int i = 0; i < 15; i++) {
        if (!elevator2.exit()) {
            std::cout << "Elevator is empty (cannot remove more people)" << std::endl;
            break;
        }
    }

    elevator2.printStatus();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_elevator();
    return 0;
}
