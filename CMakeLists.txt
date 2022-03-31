cmake_minimum_required(VERSION 3.17)
project(POA_L2)

set(CMAKE_CXX_STANDARD 14)

add_executable(POA_L2 src/main.cpp src/Ship.cpp src/Ship.h src/Squadron.cpp src/Squadron.h src/TieLn.cpp src/TieLn.hpp src/TieIn.cpp src/TieIn.hpp)