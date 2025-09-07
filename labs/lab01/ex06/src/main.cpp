/**
 * @file main.cpp
 * @brief Air Conditioner task 6 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 06
 *
 * Implement the abstraction of an air conditioning equipment, with the
 * following requirements:
 *
 * - The conditioner has 10 different power levels.
 * - Each power unit of the conditioner decreases the room temperature
 *   by 1.8°C.
 * - The variation that the conditioner can cause is in the range
 *   [0°C - 18°C], that is, zero degrees of variation when turned off
 *   and eighteen degrees of variation when turned on at maximum power.
 * - Through a sensor, the conditioner is informed of the external
 *   temperature. Given this temperature and the selected power, the
 *   conditioner calculates and returns the room temperature.
 *
 * In the main program, create two conditioners. Inform two different
 * external temperatures for each one (e.g., 25°C and 31°C), adjust the
 * second to maximum power (10) and the first to medium power (5).
 * Finally, display the resulting temperature of each room.
 *
 */

#include <iostream>
#include <iomanip>

#include "airconditioner.hpp"

/**
 * @brief Test the interface of the AirConditioner class
 * @return void
 */
void test_airconditioner()
{
    std::cout << "=== Testing the Air Conditioner Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating an air conditioner with default constructor:" << std::endl;
    AirConditioner ac1;
    ac1.printStatus();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating an air conditioner with constructor parameters:" << std::endl;
    AirConditioner ac2(5);  /** power=5 */
    ac2.printStatus();
    std::cout << std::endl;

    /** Test 3: Testing power control methods */
    std::cout << "3. Testing power control methods:" << std::endl;

    std::cout << "Increasing power 3 times:" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (ac2.increasePower()) {
            std::cout << "Power increased to " << static_cast<int>(ac2.power()) << std::endl;
        } else {
            std::cout << "Power cannot be increased further" << std::endl;
        }
    }
    ac2.printStatus();

    std::cout << "Decreasing power 2 times:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (ac2.decreasePower()) {
            std::cout << "Power decreased to " << static_cast<int>(ac2.power()) << std::endl;
        } else {
            std::cout << "Power cannot be decreased further" << std::endl;
        }
    }
    ac2.printStatus();

    std::cout << "Setting power to 8:" << std::endl;
    ac2.setPower(8);
    ac2.printStatus();
    std::cout << std::endl;

    /** Test 4: Testing temperature control */
    std::cout << "4. Testing temperature control:" << std::endl;

    std::cout << "Setting external temperature to 30°C:" << std::endl;
    ac2.setExternalTemperature(30.0);
    ac2.printStatus();

    std::cout << "Setting external temperature to 35°C:" << std::endl;
    ac2.setExternalTemperature(35.0);
    ac2.printStatus();

    std::cout << "Setting external temperature to 20°C:" << std::endl;
    ac2.setExternalTemperature(20.0);
    ac2.printStatus();
    std::cout << std::endl;

    /** Test 5: Testing edge cases */
    std::cout << "5. Testing edge cases:" << std::endl;

    std::cout << "Trying to increase power beyond maximum:" << std::endl;
    ac2.setPower(10);
    for (int i = 0; i < 5; i++) {
        if (!ac2.increasePower()) {
            std::cout << "Power stopped at " << static_cast<int>(ac2.power())
                      << " (cannot go higher)" << std::endl;
            break;
        }
    }

    std::cout << "Trying to decrease power below minimum:" << std::endl;
    ac2.setPower(0);
    for (int i = 0; i < 5; i++) {
        if (!ac2.decreasePower()) {
            std::cout << "Power stopped at " << static_cast<int>(ac2.power())
                      << " (cannot go lower)" << std::endl;
            break;
        }
    }

    std::cout << "Setting power to 15 (should normalize to 10):" << std::endl;
    ac2.setPower(15);
    ac2.printStatus();
    std::cout << std::endl;

    /** Test 6: Testing temperature calculations */
    std::cout << "6. Testing temperature calculations:" << std::endl;

    std::cout << "Testing different power levels with 30°C external temperature:" << std::endl;
    ac2.setExternalTemperature(30.0);

    for (uint8_t power = 0; power <= 10; power++) {
        ac2.setPower(power);
        double roomTemp = ac2.getRoomTemperature();
        double decrease = power * 1.8;
        std::cout << "Power " << static_cast<int>(power) << ": "
                  << std::fixed << std::setprecision(1)
                  << "External " << ac2.externalTemperature() << "°C, "
                  << "Decrease " << decrease << "°C, "
                  << "Room " << roomTemp << "°C" << std::endl;
    }
    std::cout << std::endl;

    /** Test 7: Testing turnOff method */
    std::cout << "7. Testing turnOff method:" << std::endl;

    std::cout << "Current status:" << std::endl;
    ac2.printStatus();

    std::cout << "Turning off:" << std::endl;
    ac2.turnOff();
    ac2.printStatus();

    std::cout << "Turning back on with power 7:" << std::endl;
    ac2.setPower(7);
    ac2.printStatus();
    std::cout << std::endl;

    /** Test 8: Main exercise requirement - Two conditioners */
    std::cout << "8. Main exercise requirement - Two conditioners:" << std::endl;

    std::cout << "Creating first conditioner (AC1) with medium power (5):" << std::endl;
    AirConditioner ac1_main(5);
    ac1_main.setExternalTemperature(25.0);
    ac1_main.printStatus();

    std::cout << "Creating second conditioner (AC2) with maximum power (10):" << std::endl;
    AirConditioner ac2_main(10);
    ac2_main.setExternalTemperature(31.0);
    ac2_main.printStatus();

    std::cout << "Summary of results:" << std::endl;
    std::cout << "AC1: External " << ac1_main.externalTemperature() << "°C, "
              << "Power " << static_cast<int>(ac1_main.power()) << ", "
              << "Room " << std::fixed << std::setprecision(1) << ac1_main.getRoomTemperature() << "°C" << std::endl;
    std::cout << "AC2: External " << ac2_main.externalTemperature() << "°C, "
              << "Power " << static_cast<int>(ac2_main.power()) << ", "
              << "Room " << std::fixed << std::setprecision(1) << ac2_main.getRoomTemperature() << "°C" << std::endl;
    std::cout << std::endl;

    /** Test 9: Testing multiple conditioners with different scenarios */
    std::cout << "9. Testing multiple conditioners with different scenarios:" << std::endl;

    std::cout << "Testing extreme temperatures:" << std::endl;
    AirConditioner ac_extreme(8);
    ac_extreme.setExternalTemperature(40.0);
    ac_extreme.printStatus();

    std::cout << "Testing very low temperatures:" << std::endl;
    AirConditioner ac_cold(3);
    ac_cold.setExternalTemperature(5.0);
    ac_cold.printStatus();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_airconditioner();
    return 0;
}
