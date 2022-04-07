//
// Created by NelsonWork on 18.03.2022.
//

#include "Squadron.h"

Squadron::Squadron(const std::string &name) : name(name), firstMember(nullptr), leader(nullptr) {}

Squadron::Squadron(const Squadron &squadron) : name(squadron.name) {}

Squadron::~Squadron() {
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        Member *nextMember = currentMember->getNext();
        delete currentMember;
        currentMember = nextMember;
    }
}

void Squadron::setLeader(const Ship *ship) {
    if (ship == nullptr) {
        throw std::invalid_argument("Ship cannot be nullptr");
    }
    Member *member = getMember(ship);
    if (member == nullptr) {
        throw std::invalid_argument("Ship is not in the squadron");
    }
    leader = member;
}

bool Squadron::isEmpty() const {
    return firstMember == nullptr;
}

Squadron::Member* Squadron::getMember(const Ship *ship) {
    if(ship == nullptr) {
        throw std::invalid_argument("Ship cannot be nullptr");
    }
    if(isEmpty()) {
        return nullptr;
    }
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        if (currentMember->getShip() == ship) {
            return currentMember;
        }
        currentMember = currentMember->getNext();
    }
    return nullptr;
}

void Squadron::addShip(const Ship *ship) {
    if(ship == nullptr) {
        throw std::invalid_argument("Ship cannot be nullptr");
    }
    if(isEmpty()) {
        firstMember = new Member(ship);
    } else {
        Member* oldFirstMember = firstMember;
        firstMember = new Member(ship);
        firstMember->setNext(oldFirstMember);
    }
}

void Squadron::removeShip(const Ship *ship) {
    if(ship == nullptr) {
        throw std::invalid_argument("Ship cannot be nullptr");
    }
    if(isEmpty()) {
        throw std::invalid_argument("Squadron is empty");
    }
    Member *currentMember = firstMember;
    Member *previousMember = nullptr;
    while (currentMember != nullptr) {
        if (currentMember->getShip() == ship) {
            if (previousMember == nullptr) {
                firstMember = currentMember->getNext();
            } else {
                previousMember->setNext(currentMember->getNext());
            }
            delete currentMember;
            return;
        }
        previousMember = currentMember;
        currentMember = currentMember->getNext();
    }
    throw std::invalid_argument("Ship is not in the squadron");
}

/// Member

Squadron::Member::Member(const Ship *ship) : ship(ship), next(nullptr) {}

Squadron::Member* Squadron::Member::getNext() {
    return next;
}

const Ship* Squadron::Member::getShip() {
    return ship;
}

void Squadron::Member::setNext(Squadron::Member *next) {
    this->next = next;
}

bool Squadron::Member::hasNext() {
    return next != nullptr;
}

unsigned int Squadron::getMaximumSpeed() const {
    if(isEmpty()) {
        return 0;
    }
    unsigned int maxSpeed = 0;
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        if (currentMember->getShip()->getModelSpeedMax() < maxSpeed) {
            maxSpeed = currentMember->getShip()->getModelSpeedMax();
        }
        currentMember = currentMember->getNext();
    }
    return maxSpeed;
}

double Squadron::getConsumption(unsigned distance, unsigned speed) const {
    if(isEmpty()) {
        return 0;
    }
    if(speed > getMaximumSpeed()) {
        throw std::invalid_argument("Speed is greater than this squadron's maximum speed");
    }
    double consumption = 0;
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        consumption += currentMember->getShip()->getConsumption(distance, speed);
        currentMember = currentMember->getNext();
    }
    return consumption;
}

std::ostream& Squadron::toStream(std::ostream &out) const {
    out << "Squadron: " + name + " :\n";
    out << "-- Leader:\n";
    if(leader != nullptr) {
        out << *leader->getShip();
    } else {
        out << "None\n";
    }
    out << "\n-- Members:\n";
    Squadron::Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        if(currentMember != leader) {
            out << "\n" << *currentMember->getShip() << "\n";
        }
        currentMember = currentMember->getNext();
    }
    return out;
}

Squadron& Squadron::operator+= (const Ship& ship) {
    addShip(&ship);
    return *this;
}

Squadron& Squadron::operator-= (const Ship &ship) {
    removeShip(&ship);
    return *this;
}

/// Friend

std::ostream& operator<<(std::ostream& out, const Squadron& squadron) {
    return squadron.toStream(out);
}