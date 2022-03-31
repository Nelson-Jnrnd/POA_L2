//
// Created by NelsonWork on 31.03.2022.
//

#include "TieIn.hpp"

unsigned int serialNumberCounter = 0;

unsigned int TieIn::getNextSerialNumber() {
    return ++serialNumberCounter;
}

float TieIn::getModelWeight() const {
    return 5;
}

unsigned int TieIn::getModelSpeedMax() const {
    return 110;
}

std::string TieIn::getModel() const {
    return "TIE/IN";
}

TieIn::TieIn() : Ship() {}
