cmake_minimum_required(VERSION 3.17)
project(Algorithms_and_Data_Structures)

set(CMAKE_CXX_STANDARD 20)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Algorithms_and_Data_Structures
        "Lab 1/Task 5/main.cpp")
