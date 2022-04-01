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

void Squadron::setLeader(Ship *ship) {
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

Squadron::Member* Squadron::getMember(Ship *ship) {
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

void Squadron::addShip(Ship *ship) {
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

/// Member

Squadron::Member::Member(Ship *ship) : ship(ship), next(nullptr) {}

Squadron::Member* Squadron::Member::getNext() {
    return next;
}

Ship* Squadron::Member::getShip() {
    return ship;
}

void Squadron::Member::setNext(Squadron::Member *next) {
    this->next = next;
}

bool Squadron::Member::hasNext() {
    return next != nullptr;
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
/// Friend

std::ostream& operator<<(std::ostream& out, const Squadron& squadron) {
    return squadron.toStream(out);
}