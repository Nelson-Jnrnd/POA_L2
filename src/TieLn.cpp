//
// Created by NelsonWork on 31.03.2022.
//

#include "TieLn.hpp"

unsigned int serialNumberCounter = 0;

unsigned int TieLn::getNextSerialNumber() {
    return ++serialNumberCounter;
}

float TieLn::getModelWeight() const {
    return 6;
}

unsigned int TieLn::getModelSpeedMax() const {
    return 100;
}

std::string TieLn::getModel() const {
    return "TIE/LN";
}

TieLn::TieLn() : Ship() {}

