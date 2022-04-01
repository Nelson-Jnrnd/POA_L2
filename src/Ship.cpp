//
// Created by NelsonWork on 18.03.2022.
//

#include "Ship.h"
#include <cmath>

Ship::Ship(unsigned int serialNumber) : speed(0), distance(0), nickname(""), serialNumber(serialNumber) {}

void Ship::setNickname(const std::string &newNickname) {
    if (newNickname.empty()) {
        nickname = "";
    } else {
        nickname = newNickname;
    }
}

double Ship::getConsumption() const {
    return std::cbrt(getModelWeight()) / 2 * log10(getModelWeight() * speed) * log10(distance + 1);   
}

std::string Ship::toString() const {
    std::string info = nickname.empty() ? "" : nickname + " ";
    info += "[" + getModel() + " #" + std::to_string(serialNumber) + "]\n"
    + "weight : " + std::to_string(getModelWeight()) + " tons\n"
    + "max speed : " + std::to_string(getModelSpeedMax()) + " MGLT\n";
    return info;
}