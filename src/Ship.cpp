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
   if(speed > this->getModelSpeedMax() || speed <= 0)
      throw std::invalid_argument("Speed must be greater than 0 and less than or equal to max speed");
   return std::cbrt(getModelWeight()) / 2 * log10(getModelWeight() * speed) * log10(distance + 1);
}
std::ostream& Ship::toStream(std::ostream &out) const {
    out << std::fixed << std::setprecision(2) << (nickname.empty() ? "" : nickname + " ");
    out << "[" << getModel() << " #" << serialNumber << "]\n"
    << " weight : " << getModelWeight() << " tons\n"
    << " max speed : " << getModelSpeedMax() << " MGLT\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Ship& ship) {
    return ship.toStream(out);
}

std::string Ship::getNickname() const {
   return this->nickname;
}
