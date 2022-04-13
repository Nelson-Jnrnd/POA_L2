//
// Created by NelsonWork on 18.03.2022.
//

#include "Ship.hpp"
#include <cmath>
#include <iomanip>

Ship::Ship(unsigned int serialNumber) : nickname(""), serialNumber(serialNumber) {}

void Ship::setNickname(const std::string &newNickname) {
    if (newNickname.empty()) {
        nickname = "";
    } else {
        nickname = newNickname;
    }
}

double Ship::getConsumption(unsigned distance, unsigned speed) const {
    return std::cbrt(getModelWeight()) / 2 * log10(getModelWeight() * speed) * log10(distance + 1);   
}
std::ostream& Ship::toStream(std::ostream &out) const {
    out << std::fixed << std::setprecision(2) << (nickname.empty() ? "" : nickname + " ");
    out << "[" << getModel() << " #" << serialNumber << "]\n"
    << "weight : " << getModelWeight() << " tons\n"
    << "max speed : " << getModelSpeedMax() << " MGLT\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Ship& ship) {
    return ship.toStream(out);
}