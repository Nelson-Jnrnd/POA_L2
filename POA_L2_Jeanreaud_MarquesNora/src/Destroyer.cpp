#include "Headers/Destroyer.hpp"
#include <cmath>

unsigned int Destroyer::serialNumberCounter = 0;

unsigned int Destroyer::getNextSerialNumber() {
    return ++serialNumberCounter;
}

Destroyer::Destroyer(double currentCapacity) : CargoShip(getNextSerialNumber(), currentCapacity) {
    if(currentCapacity < 0 || currentCapacity > this->getMaxCapacity()) {
     throw std::invalid_argument("Capacity must be greater than 0 and less than or equal to max capacity");
    }
}

double Destroyer::getMaxCapacity() const {
    return 250 * pow(10, 3);
}

double Destroyer::getModelWeight() const {
    return 9 * pow(10, 9);
}

std::string Destroyer::getModel() const {
    return "Super-class Star Destroyer";
}

unsigned int Destroyer::getModelSpeedMax() const {
    return 40;
}
