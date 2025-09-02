/**
 * @file main.cpp
 * @brief Circle task 4 implementation
 * @version 0.1
 * @date 2025-09-01
 *
 * ## Exercise 04
 *
 * Define a class that abstracts a circle.
 *
 * This class must have **Private** methods for:
 * - Calculate the area of the circle
 * - Calculate the distance between the centers of 2 circles
 * - Calculate the circumference of the circle
 *
 * And **Public** methods for:
 * - Define the radius of the circle, given a real number
 * - Increase the radius of the circle, given a percentage increase
 * - Define the center of the circle, given a position (X,Y)
 * - Print the radius value
 * - Print the center of the circle
 * - Print the area of the circle
 *
 * Create a main program to test the class.
 *
 */

#include <iostream>
#include <cmath>

#include "circle.hpp"

/**
 * @brief Test the interface of the Circle class
 * @return void
 */
void test_circle()
{
    std::cout << "=== Testing the Circle Class ===" << std::endl << std::endl;

    /** Test 1: Default constructor */
    std::cout << "1. Creating a circle with default constructor:" << std::endl;
    Circle circle1;
    circle1.printRadius();
    circle1.printCenter();
    circle1.printArea();
    std::cout << std::endl;

    /** Test 2: Constructor with parameters */
    std::cout << "2. Creating a circle with constructor parameters:" << std::endl;
    Circle circle2(5.0, 2.0, 3.0);  /** radius=5, center at (2,3) */
    circle2.printRadius();
    circle2.printCenter();
    circle2.printArea();
    std::cout << std::endl;

    /** Test 3: Testing setRadius method */
    std::cout << "3. Testing the setRadius method:" << std::endl;
    std::cout << "Setting radius to 7.5..." << std::endl;
    circle2.setRadius(7.5);
    circle2.printRadius();
    circle2.printArea();
    std::cout << std::endl;

    /** Test 4: Testing increaseRadius method */
    std::cout << "4. Testing the increaseRadius method:" << std::endl;
    std::cout << "Increasing radius by 20%..." << std::endl;
    circle2.increaseRadius(20.0);
    circle2.printRadius();
    circle2.printArea();

    std::cout << "Increasing radius by 50%..." << std::endl;
    circle2.increaseRadius(50.0);
    circle2.printRadius();
    circle2.printArea();
    std::cout << std::endl;

    /** Test 5: Testing setCenter method */
    std::cout << "5. Testing the setCenter method:" << std::endl;
    std::cout << "Setting center to (10, 15)..." << std::endl;
    circle2.setCenter(10.0, 15.0);
    circle2.printCenter();
    std::cout << std::endl;

    /** Test 6: Testing multiple circles */
    std::cout << "6. Testing multiple circles:" << std::endl;
    Circle circle3(3.0, 0.0, 0.0);  /** radius=3, center at origin */
    Circle circle4(2.0, 8.0, 12.0); /** radius=2, center at (8,12) */

    std::cout << "Circle 3:" << std::endl;
    circle3.printRadius();
    circle3.printCenter();
    circle3.printArea();

    std::cout << "Circle 4:" << std::endl;
    circle4.printRadius();
    circle4.printCenter();
    circle4.printArea();
    std::cout << std::endl;

    /** Test 7: Testing edge cases */
    std::cout << "7. Testing edge cases:" << std::endl;

    std::cout << "Setting radius to 0 (should not change):" << std::endl;
    circle3.setRadius(0);
    circle3.printRadius();

    std::cout << "Setting radius to negative value (should not change):" << std::endl;
    circle3.setRadius(-5);
    circle3.printRadius();

    std::cout << "Increasing radius by 0% (should not change):" << std::endl;
    circle3.increaseRadius(0);
    circle3.printRadius();

    std::cout << "Increasing radius by negative percentage (should not change):" << std::endl;
    circle3.increaseRadius(-10);
    circle3.printRadius();
    std::cout << std::endl;

    /** Test 8: Testing calculations */
    std::cout << "8. Testing calculations:" << std::endl;

    std::cout << "Circle with radius 1:" << std::endl;
    Circle unitCircle(1.0);
    unitCircle.printRadius();
    unitCircle.printArea();

    std::cout << "Circle with radius 2:" << std::endl;
    Circle doubleCircle(2.0);
    doubleCircle.printRadius();
    doubleCircle.printArea();

    std::cout << "Circle with radius 10:" << std::endl;
    Circle largeCircle(10.0);
    largeCircle.printRadius();
    largeCircle.printArea();
    std::cout << std::endl;

    /** Test 9: Testing center positioning */
    std::cout << "9. Testing center positioning:" << std::endl;

    std::cout << "Moving circle to different positions:" << std::endl;
    Circle movingCircle(4.0, 0.0, 0.0);
    movingCircle.printCenter();

    movingCircle.setCenter(100.0, 200.0);
    movingCircle.printCenter();

    movingCircle.setCenter(-50.0, -75.0);
    movingCircle.printCenter();
    std::cout << std::endl;
}

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    test_circle();
    return 0;
}
