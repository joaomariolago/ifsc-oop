# Version settings
cmake_minimum_required(VERSION 3.7...3.20)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project settings
project(
    lab01 VERSION 1.0
    DESCRIPTION "Laboratório 01: Implementando classes (abstrações)"
    LANGUAGES ASM C CXX
)

# Add all subdirectories
add_subdirectory(ex01)
add_subdirectory(ex02)
add_subdirectory(ex03)
add_subdirectory(ex04)
add_subdirectory(ex05)
add_subdirectory(ex06)
add_subdirectory(ex07)

# Print summary
message(STATUS "Lab01 configured successfully!")
message(STATUS "Available targets:")
message(STATUS "  - ex01: Person class implementation")
message(STATUS "  - ex02: Elevator class implementation")
message(STATUS "  - ex03: Clock class implementation")
message(STATUS "  - ex04: Circle class implementation")
message(STATUS "  - ex05: Television class implementation")
message(STATUS "  - ex06: Air Conditioner class implementation")
message(STATUS "  - ex07: Car class implementation")
message(STATUS "")
