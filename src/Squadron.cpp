//
// Created by NelsonWork on 18.03.2022.
//

#include "Squadron.h"

Squadron::Squadron(const std::string &name) : name(name) {}

Squadron::Squadron(const Squadron &squadron) : name(squadron.name), ships(squadron.ships) {}

Squadron::~Squadron() {
    for (auto ship : ships) {
        delete ship;
    }
}

Squadron& Squadron::Squadron::operator=(const Squadron &squadron) {
    if (this != &squadron) {
        name = squadron.name;
        ships = squadron.ships;
    }
    return *this;
}

void Squadron::addShip(Ship *ship) {
    if(ship == nullptr) {
        throw std::invalid_argument("Ship cannot be nullptr");
    }
    if(containsShip(ship)) {
        throw std::invalid_argument("Ship already in squadron");
    }
    ships.push_back(ship);
}

void Squadron::setLeader(Ship *ship) {
    if(ship == nullptr) {
        throw std::invalid_argument("Ship cannot be nullptr");
    }
    if(!containsShip(ship)) {
        throw std::invalid_argument("Ship not in squadron");
    }
    leader = ship;
}

void Squadron::removeLeader() {
    if(leader == nullptr) {
        throw std::invalid_argument("Squadron has no leader");
    }
    leader = nullptr;
}

