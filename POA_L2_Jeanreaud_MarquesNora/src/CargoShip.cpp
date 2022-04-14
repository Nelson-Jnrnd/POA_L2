#include "Headers/CargoShip.hpp"
#include <iomanip>

CargoShip::CargoShip(unsigned int serialNumber, double currentCapacity) : currentCapacity(currentCapacity), Ship(serialNumber) {}

double CargoShip::getCurrentCapacity() const {
    return currentCapacity;
}

std::ostream& CargoShip::toStream(std::ostream &out) const {
    Ship::toStream(out);
    out << std::fixed << std::setprecision(1) << "cargo : " << currentCapacity << " tons (max : "
    << getMaxCapacity() << ")\n";
    return out;
}
