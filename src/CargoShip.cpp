//
// Created by NelsonWork on 31.03.2022.
//

#include "CargoShip.hpp"

CargoShip::CargoShip(unsigned int serialNumber, double currentCapacity) : currentCapacity(currentCapacity), Ship(serialNumber) {}

double CargoShip::getCurrentCapacity() const {
    return currentCapacity;
}

std::string CargoShip::toString() const {
    std::string info = Ship::toString();
    info += "cargo : " + std::to_string(currentCapacity) + " tons (max : "
     + std::to_string(getMaxCapacity()) + ")\n";
    return info;
}