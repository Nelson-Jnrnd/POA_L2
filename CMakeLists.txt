cmake_minimum_required(VERSION 3.17)
project(POA_L2)

set(CMAKE_CXX_STANDARD 14)

add_executable(POA_L2 src/main.cpp src/Ship.cpp src/Ship.hpp src/Squadron.cpp src/Squadron.hpp src/TieLn.cpp src/TieLn.hpp src/TieIn.cpp src/TieIn.hpp src/CargoShip.cpp src/CargoShip.hpp src/Shuttle.cpp src/Shuttle.hpp src/Destroyer.cpp src/Destroyer.hpp)
add_executable(Test src/Test.cpp src/Ship.cpp src/Ship.hpp src/Squadron.cpp src/Squadron.hpp src/TieLn.cpp src/TieLn.hpp src/TieIn.cpp src/TieIn.hpp src/CargoShip.cpp src/CargoShip.hpp src/Shuttle.cpp src/Shuttle.hpp src/Destroyer.cpp src/Destroyer.hpp)