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
    task2 VERSION 1.0
    LANGUAGES ASM C CXX
)

# Sources files of project
set(
    SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/elevator.cpp"
)

set(
    HEADERS_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/elevator.hpp"
)

# Executable settings
add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES} ${HEADERS_FILES}
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
