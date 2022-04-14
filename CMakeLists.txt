cmake_minimum_required(VERSION 3.17)
project(POA_L2)

set(CMAKE_CXX_STANDARD 14)

add_executable(POA_L2 src/main.cpp src/Ship.cpp src/Headers/Ship.hpp src/Squadron.cpp src/Headers/Squadron.hpp src/TieLn.cpp src/Headers/TieLn.hpp src/TieIn.cpp src/Headers/TieIn.hpp src/CargoShip.cpp src/Headers/CargoShip.hpp src/Shuttle.cpp src/Headers/Shuttle.hpp src/Destroyer.cpp src/Headers/Destroyer.hpp)
add_executable(Test src/Test.cpp src/Ship.cpp src/Headers/Ship.hpp src/Squadron.cpp src/Headers/Squadron.hpp src/TieLn.cpp src/Headers/TieLn.hpp src/TieIn.cpp src/Headers/TieIn.hpp src/CargoShip.cpp src/Headers/CargoShip.hpp src/Shuttle.cpp src/Headers/Shuttle.hpp src/Destroyer.cpp src/Headers/Destroyer.hpp)