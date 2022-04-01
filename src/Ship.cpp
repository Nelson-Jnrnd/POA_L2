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