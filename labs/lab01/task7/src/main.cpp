/**
 * @file main.cpp
 * @brief Car task 7 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 07
 *
 * Implement a car abstraction. The car's fuel tank stores a maximum of
 * 50 liters of gasoline. The car consumes 15 km/liter. It must be possible to:
 *
 * - Refuel the car with a certain amount of gasoline
 * - Move the car a certain distance (measured in km)
 * - Return the amount of fuel and the total distance traveled
 *
 * Develop a program to test your abstraction. Remember to perform a
 * complete test of your interface and consider possible state inconsistencies
 * (e.g., a car cannot travel a certain distance if it does not have
 * sufficient fuel for this).
 *
 */

#include <iostream>
#include <iomanip>

#include "car.hpp"

/**
 * @brief Test the interface of the Car class
 * @return void
 */
void test_car()
{
    std::cout << "=== Testing the Car Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating a car with default constructor:" << std::endl;
    Car car1;
    car1.printStatus();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating a car with constructor parameters:" << std::endl;
    Car car2(25.0);  /** 25 liters of fuel */
    car2.printStatus();
    std::cout << std::endl;

    /** Test 3: Testing refuel method */
    std::cout << "3. Testing the refuel method:" << std::endl;

    std::cout << "Adding 10 liters of fuel:" << std::endl;
    if (car2.refuel(10.0)) {
        std::cout << "Refueled successfully" << std::endl;
    } else {
        std::cout << "Refuel failed" << std::endl;
    }
    car2.printStatus();

    std::cout << "Adding 20 more liters of fuel:" << std::endl;
    if (car2.refuel(20.0)) {
        std::cout << "Refueled successfully" << std::endl;
    } else {
        std::cout << "Refuel failed" << std::endl;
    }
    car2.printStatus();

    std::cout << "Trying to add 10 more liters (should fill to max capacity):" << std::endl;
    if (car2.refuel(10.0)) {
        std::cout << "Refueled successfully (filled to maximum)" << std::endl;
    } else {
        std::cout << "Refuel failed" << std::endl;
    }
    car2.printStatus();
    std::cout << std::endl;

    /** Test 4: Testing move method */
    std::cout << "4. Testing the move method:" << std::endl;

    std::cout << "Moving 50 km:" << std::endl;
    if (car2.move(50.0)) {
        std::cout << "Moved successfully" << std::endl;
    } else {
        std::cout << "Move failed (insufficient fuel)" << std::endl;
    }
    car2.printStatus();

    std::cout << "Moving 100 km:" << std::endl;
    if (car2.move(100.0)) {
        std::cout << "Moved successfully" << std::endl;
    } else {
        std::cout << "Move failed (insufficient fuel)" << std::endl;
    }
    car2.printStatus();

    std::cout << "Moving 200 km:" << std::endl;
    if (car2.move(200.0)) {
        std::cout << "Moved successfully" << std::endl;
    } else {
        std::cout << "Move failed (insufficient fuel)" << std::endl;
    }
    car2.printStatus();
    std::cout << std::endl;

    /** Test 5: Testing edge cases */
    std::cout << "5. Testing edge cases:" << std::endl;

    std::cout << "Trying to move 0 km:" << std::endl;
    if (!car2.move(0.0)) {
        std::cout << "Move correctly rejected (distance must be positive)" << std::endl;
    }

    std::cout << "Trying to move negative distance:" << std::endl;
    if (!car2.move(-50.0)) {
        std::cout << "Move correctly rejected (distance must be positive)" << std::endl;
    }

    std::cout << "Trying to refuel 0 liters:" << std::endl;
    if (!car2.refuel(0.0)) {
        std::cout << "Refuel correctly rejected (amount must be positive)" << std::endl;
    }

    std::cout << "Trying to refuel negative amount:" << std::endl;
    if (!car2.refuel(-10.0)) {
        std::cout << "Refuel correctly rejected (amount must be positive)" << std::endl;
    }

    car2.printStatus();
    std::cout << std::endl;

    /** Test 6: Testing fuel consumption calculations */
    std::cout << "6. Testing fuel consumption calculations:" << std::endl;

    std::cout << "Current fuel: " << car2.fuel() << " liters" << std::endl;
    std::cout << "Fuel efficiency: " << car2.fuelEfficiency() << " km/liter" << std::endl;
    std::cout << "Remaining range: " << car2.getRemainingRange() << " km" << std::endl;

    std::cout << "Moving exactly the remaining range:" << std::endl;
    double remainingRange = car2.getRemainingRange();
    if (car2.move(remainingRange)) {
        std::cout << "Moved successfully to empty tank" << std::endl;
    } else {
        std::cout << "Move failed" << std::endl;
    }
    car2.printStatus();

    std::cout << "Trying to move 1 km with empty tank:" << std::endl;
    if (!car2.move(1.0)) {
        std::cout << "Move correctly rejected (insufficient fuel)" << std::endl;
    }
    std::cout << std::endl;

    /** Test 7: Testing refuel after empty */
    std::cout << "7. Testing refuel after empty tank:" << std::endl;

    std::cout << "Refueling with 30 liters:" << std::endl;
    if (car2.refuel(30.0)) {
        std::cout << "Refueled successfully" << std::endl;
    }
    car2.printStatus();

    std::cout << "Moving 100 km:" << std::endl;
    if (car2.move(100.0)) {
        std::cout << "Moved successfully" << std::endl;
    }
    car2.printStatus();
    std::cout << std::endl;

    /** Test 8: Testing multiple cars */
    std::cout << "8. Testing multiple cars:" << std::endl;

    std::cout << "Creating a new car with full tank:" << std::endl;
    Car car3(50.0);
    car3.printStatus();

    std::cout << "Moving both cars different distances:" << std::endl;
    car2.move(50.0);
    car3.move(75.0);

    std::cout << "Car 2 status:" << std::endl;
    car2.printStatus();

    std::cout << "Car 3 status:" << std::endl;
    car3.printStatus();
    std::cout << std::endl;

    /** Test 9: Testing long journey scenario */
    std::cout << "9. Testing long journey scenario:" << std::endl;

    std::cout << "Creating a car for a long journey:" << std::endl;
    Car journeyCar(50.0);  /** Full tank */
    journeyCar.printStatus();

    std::cout << "Planning a 400 km journey:" << std::endl;
    double journeyDistance = 400.0;
    double fuelNeeded = journeyDistance / journeyCar.fuelEfficiency();
    std::cout << "Fuel needed: " << std::fixed << std::setprecision(2)
              << fuelNeeded << " liters" << std::endl;

    if (journeyCar.fuel() >= fuelNeeded) {
        std::cout << "Journey is possible with current fuel" << std::endl;
        if (journeyCar.move(journeyDistance)) {
            std::cout << "Journey completed successfully!" << std::endl;
        }
    } else {
        std::cout << "Journey requires refueling" << std::endl;
        double additionalFuel = fuelNeeded - journeyCar.fuel();
        std::cout << "Need to add " << additionalFuel << " more liters" << std::endl;

        if (journeyCar.refuel(additionalFuel)) {
            std::cout << "Refueled for journey" << std::endl;
            if (journeyCar.move(journeyDistance)) {
                std::cout << "Journey completed successfully!" << std::endl;
            }
        }
    }

    journeyCar.printStatus();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_car();
    return 0;
}
