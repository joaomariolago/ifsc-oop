# Version settings
cmake_minimum_required(VERSION 3.7...3.20)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project settings
project(
    labs VERSION 1.0
    LANGUAGES ASM C CXX
)

# Add all subdirectories
add_subdirectory(lab01)

# Print summary
message(STATUS "Labs configured successfully!")
message(STATUS "Available targets:")
message(STATUS "  - lab01: Lab 01: Implementando classes (abstrações)")
message(STATUS "")
