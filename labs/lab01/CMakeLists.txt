# Version settings
cmake_minimum_required(VERSION 3.7...3.20)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project settings
project(
    lab01 VERSION 1.0
    DESCRIPTION "Laboratório 01: Implementando classes (abstrações)"
    LANGUAGES ASM C CXX
)

# Add all subdirectories
add_subdirectory(task1)
add_subdirectory(task2)
add_subdirectory(task3)
add_subdirectory(task4)
add_subdirectory(task5)
add_subdirectory(task6)
add_subdirectory(task7)

# Print summary
message(STATUS "Lab01 configured successfully!")
message(STATUS "Available targets:")
message(STATUS "  - task1: Person class implementation")
message(STATUS "  - task2: Elevator class implementation")
message(STATUS "  - task3: Clock class implementation")
message(STATUS "  - task4: Circle class implementation")
message(STATUS "  - task5: Television class implementation")
message(STATUS "  - task6: Air Conditioner class implementation")
message(STATUS "  - task7: Car class implementation")
message(STATUS "")
