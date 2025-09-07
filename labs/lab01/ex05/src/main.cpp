/**
 * @file main.cpp
 * @brief Television task 5 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 05
 *
 * Implement a class to abstract a television. The television has a volume
 * control and a channel selection control.
 *
 * The implemented class must meet the following minimum requirements:
 *
 * - The volume control allows increasing or decreasing the sound power
 *   one unit at a time.
 * - The sound power must have discrete values in the range [0, 100].
 * - The channel control also allows increasing and decreasing the channel
 *   number one unit at a time.
 * - The interface must also allow switching to an indicated channel.
 * - The channels must have discrete values in the range [0, 75].
 * - There must also be methods to query the sound volume value and the
 *   selected channel.
 *
 * If you deem it necessary, add other behaviors to this abstraction's
 * interface that you consider necessary.
 *
 * Develop a program to test your abstraction. Remember to perform a
 * complete test of your interface.
 *
 */

#include <iostream>

#include "television.hpp"

/**
 * @brief Test the interface of the Television class
 * @return void
 */
void test_television()
{
    std::cout << "=== Testing the Television Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating a television with default constructor:" << std::endl;
    Television tv1;
    tv1.printStatus();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating a television with constructor parameters:" << std::endl;
    Television tv2(25, 5);  /** volume=25, channel=5 */
    tv2.printStatus();
    std::cout << std::endl;

    /** Test 3: Testing volume control methods */
    std::cout << "3. Testing volume control methods:" << std::endl;

    std::cout << "Increasing volume 5 times:" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (tv2.increaseVolume()) {
            std::cout << "Volume increased to " << static_cast<int>(tv2.volume()) << std::endl;
        } else {
            std::cout << "Volume cannot be increased further" << std::endl;
        }
    }
    tv2.printStatus();

    std::cout << "Decreasing volume 3 times:" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (tv2.decreaseVolume()) {
            std::cout << "Volume decreased to " << static_cast<int>(tv2.volume()) << std::endl;
        } else {
            std::cout << "Volume cannot be decreased further" << std::endl;
        }
    }
    tv2.printStatus();

    std::cout << "Setting volume to 80:" << std::endl;
    tv2.volume(80);
    tv2.printStatus();
    std::cout << std::endl;

    /** Test 4: Testing channel control methods */
    std::cout << "4. Testing channel control methods:" << std::endl;

    std::cout << "Going to next channel 3 times:" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (tv2.nextChannel()) {
            std::cout << "Channel changed to " << static_cast<int>(tv2.channel()) << std::endl;
        } else {
            std::cout << "Channel cannot be increased further" << std::endl;
        }
    }

    std::cout << "Going to previous channel 2 times:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (tv2.previousChannel()) {
            std::cout << "Channel changed to " << static_cast<int>(tv2.channel()) << std::endl;
        } else {
            std::cout << "Channel cannot be decreased further" << std::endl;
        }
    }

    std::cout << "Setting channel to 50:" << std::endl;
    tv2.channel(50);
    tv2.printStatus();
    std::cout << std::endl;

    /** Test 5: Testing edge cases */
    std::cout << "5. Testing edge cases:" << std::endl;

    std::cout << "Trying to increase volume beyond maximum:" << std::endl;
    tv2.volume(100);
    for (int i = 0; i < 5; i++) {
        if (!tv2.increaseVolume()) {
            std::cout << "Volume stopped at " << static_cast<int>(tv2.volume())
                      << " (cannot go higher)" << std::endl;
            break;
        }
    }

    std::cout << "Trying to decrease volume below minimum:" << std::endl;
    tv2.volume(0);
    for (int i = 0; i < 5; i++) {
        if (!tv2.decreaseVolume()) {
            std::cout << "Volume stopped at " << static_cast<int>(tv2.volume())
                      << " (cannot go lower)" << std::endl;
            break;
        }
    }

    std::cout << "Trying to go to channels beyond range:" << std::endl;
    tv2.channel(0);
    for (int i = 0; i < 5; i++) {
        if (!tv2.previousChannel()) {
            std::cout << "Channel stopped at " << static_cast<int>(tv2.channel())
                      << " (cannot go lower)" << std::endl;
            break;
        }
    }

    tv2.channel(75);
    for (int i = 0; i < 5; i++) {
        if (!tv2.nextChannel()) {
            std::cout << "Channel stopped at " << static_cast<int>(tv2.channel())
                      << " (cannot go higher)" << std::endl;
            break;
        }
    }

    tv2.printStatus();
    std::cout << std::endl;

    /** Test 6: Testing power control */
    std::cout << "6. Testing power control:" << std::endl;

    std::cout << "Turning off television:" << std::endl;
    tv2.powerOff();
    tv2.printStatus();

    std::cout << "Trying to change volume when off:" << std::endl;
    if (!tv2.increaseVolume()) {
        std::cout << "Volume cannot be changed when TV is off" << std::endl;
    }

    std::cout << "Trying to change channel when off:" << std::endl;
    if (!tv2.nextChannel()) {
        std::cout << "Channel cannot be changed when TV is off" << std::endl;
    }

    std::cout << "Turning on television:" << std::endl;
    tv2.powerOn();
    tv2.printStatus();

    std::cout << "Now trying to change volume:" << std::endl;
    tv2.increaseVolume();
    tv2.printStatus();
    std::cout << std::endl;

    /** Test 7: Testing value normalization */
    std::cout << "7. Testing value normalization:" << std::endl;

    std::cout << "Setting volume to 150 (should normalize to 100):" << std::endl;
    tv2.volume(150);
    tv2.printStatus();

    std::cout << "Setting channel to 100 (should normalize to 75):" << std::endl;
    tv2.channel(100);
    tv2.printStatus();
    std::cout << std::endl;

    /** Test 8: Testing multiple televisions */
    std::cout << "8. Testing multiple televisions:" << std::endl;

    Television tv3(50, 10);
    std::cout << "Third television:" << std::endl;
    tv3.printStatus();

    std::cout << "Changing settings on third TV:" << std::endl;
    tv3.volume(75);
    tv3.channel(25);
    tv3.printStatus();

    std::cout << "First television (unchanged):" << std::endl;
    tv1.printStatus();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_television();
    return 0;
}
