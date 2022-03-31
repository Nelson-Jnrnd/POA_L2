//
// Created by NelsonWork on 31.03.2022.
//

#include "Shuttle.hpp"

unsigned int Shuttle::serialNumberCounter = 0;

unsigned int Shuttle::getNextSerialNumber() {
    return ++serialNumberCounter;
}

// TODO demander pk y a un warning alors que ça compile
Shuttle::Shuttle(double currentCapacity) : CargoShip(getNextSerialNumber(), currentCapacity) {
    if(currentCapacity < 0 || currentCapacity > getMaxCapacity()) {
     throw std::invalid_argument("Capacity must be greater than 0 and less than or equal to max capacity");
    }
}

double Shuttle::getMaxCapacity() const {
    return 80;
}

double Shuttle::getModelWeight() const {
    return 360;
}

std::string Shuttle::getModel() const {
    return "Lambda-class shuttle";
}

unsigned int Shuttle::getModelSpeedMax() const {
    return 54;
}