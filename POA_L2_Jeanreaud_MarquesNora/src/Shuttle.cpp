#include "Headers/Shuttle.hpp"

unsigned int Shuttle::serialNumberCounter = 0;

unsigned int Shuttle::getNextSerialNumber() {
    return ++serialNumberCounter;
}

Shuttle::Shuttle(double currentCapacity) : CargoShip(getNextSerialNumber(), currentCapacity) {
    if(currentCapacity < 0 || currentCapacity > this->getMaxCapacity()) {
     throw std::invalid_argument("Capacity must be greater than 0 and less than or equal to max capacity");
    }
}

double Shuttle::getMaxCapacity() const {
    return 80.0;
}

double Shuttle::getModelWeight() const {
    return 360.0;
}

std::string Shuttle::getModel() const {
    return "Lambda-class shuttle";
}

unsigned int Shuttle::getModelSpeedMax() const {
    return 54;
}