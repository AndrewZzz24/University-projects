cmake_minimum_required(VERSION 3.17)
project(IS_2020_prog_2_sem)

set(CMAKE_CXX_STANDARD 20)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

#
#add_executable(IS_2020_prog_2_sem
#        homework1/geometry.h
#        homework1/main.cpp homework1/geometry.cpp)

#add_executable(IS_2020_prog_2_sem
#        homework5/main.cpp homework5/CircularBuffer.cpp homework5/CircularBuffer.hpp)
add_executable(IS_2020_prog_2_sem
        homework6/main.cpp homework6/cube.cpp homework6/cube.hpp)

#add_executable(IS_2020_prog_2_sem
#        homework3/main.cpp homework3/node.cpp homework3/node.h homework3/pugixml.hpp homework3/pugiconfig.hpp
#        homework3/pugixml.cpp)