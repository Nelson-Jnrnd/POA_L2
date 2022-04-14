//
// Created by NelsonWork on 18.03.2022.
//

#include "Squadron.hpp"

#include <utility>

Squadron::Squadron(const std::string &name) : name(name), firstMember(nullptr), leader(nullptr) {
}

Squadron::Squadron(const Squadron &squadron) : Squadron::Squadron(squadron.name) {
    /* Copying the squadron. */
    this->copySquad(squadron);
}

Squadron::~Squadron() {
    /* Deleting the members of the squadron. */
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        Member *nextMember = currentMember->getNext();
        delete currentMember;
        currentMember = nextMember;
    }
}

Squadron &Squadron::operator=(const Squadron &squadron) {
   this->emptySquad();

   this->copySquad(squadron);

   return *this;
}

void Squadron::setLeader(const Ship& ship) {
    Member *member = getMember(ship);
    if (member == nullptr) {
        throw std::invalid_argument("Ship is not in the squadron");
    }
    leader = member;
}

bool Squadron::isEmpty() const {
    return firstMember == nullptr;
}

Squadron::Member* Squadron::getMember(const Ship &ship) const{
    if(isEmpty()) {
        return nullptr;
    }
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        if (&currentMember->getShip() == &ship) {
            return currentMember;
        }
        currentMember = currentMember->getNext();
    }
    return nullptr;
}

Squadron::Member* Squadron::getMember(unsigned index) const{
    size_t size = this->getSize() - 1;
   if(index < 0 || index > size)
      throw std::invalid_argument("Index out of bound");

   Member* m = this->firstMember;
   for (int i = 0; i < size - index; ++i) {
      if (m->hasNext())
         m = m->getNext();
   }
   return m;
}

void Squadron::addShipToSelf(const Ship &ship) {
    if(isEmpty()) {
        firstMember = new Member(&ship);
    } else if(getMember(ship) != nullptr){
        throw std::invalid_argument("Ship is already in squadron");
    }
    else {
        Member* oldFirstMember = firstMember;
        firstMember = new Member(&ship);
        firstMember->setNext(oldFirstMember);
    }
}

Squadron Squadron::addShip(const Ship& ship) const{
    Squadron newSquadron(*this);
    newSquadron.addShipToSelf(ship);
    return newSquadron;
}

void Squadron::removeShipToSelf(const Ship &ship) {
    if(isEmpty()) {
        throw std::invalid_argument("Squadron is empty");
    }
    Member *currentMember = firstMember;
    Member *previousMember = nullptr;
    while (currentMember != nullptr) {
        if (&currentMember->getShip() == &ship) {
            if (previousMember == nullptr) {
                firstMember = currentMember->getNext();
            } else {
                previousMember->setNext(currentMember->getNext());
            }
            if(currentMember == leader)
                leader = nullptr;

            delete currentMember;
            return;
        }
        previousMember = currentMember;
        currentMember = currentMember->getNext();
    }
    throw std::invalid_argument("Ship is not in the squadron");
}

Squadron Squadron::removeShip(const Ship &ship) const{
    Squadron newSquadron(*this);
    newSquadron.removeShipToSelf(ship);
    return newSquadron;
}

unsigned int Squadron::getMaximumSpeed() const {
   if(isEmpty())
      return 0;

    unsigned int maxSpeed = firstMember->getShip().getModelSpeedMax();
    Member *currentMember = firstMember->getNext();
    while (currentMember != nullptr) {
        if (currentMember->getShip().getModelSpeedMax() < maxSpeed) {
            maxSpeed = currentMember->getShip().getModelSpeedMax();
        }
        currentMember = currentMember->getNext();
    }
    return maxSpeed;
}

double Squadron::getTotalWeight() const {
    if(isEmpty()) {
        return 0;
    }
    double totalWeight = 0;
    Member *currentMember = firstMember;
    while (currentMember != nullptr) {
        totalWeight += currentMember->getShip().getModelWeight();
        currentMember = currentMember->getNext();
    }
    return totalWeight;
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
        consumption += currentMember->getShip().getConsumption(distance, speed);
        currentMember = currentMember->getNext();
    }
    return consumption;
}

std::ostream& Squadron::toStream(std::ostream &out) const {
    out << "Squadron: " << name << " :\n";
    out << " max speed: " << getMaximumSpeed() << " MGLT\n";
    out << " total weight: " << getTotalWeight() << " tons\n";
    out << "-- Leader:\n";
    if(leader != nullptr) {
        out << this->getLeader();
    } else {
        out << "None\n";
    }
    out << "\n-- Members:\n";
   if(firstMember != nullptr) {
      Squadron::Member *currentMember = firstMember;
      while (currentMember != nullptr) {
         if (currentMember != leader) {
            out << "\n" << currentMember->getShip() << "\n";
         }
         currentMember = currentMember->getNext();
      }
   } else {
      out << "None\n";
   }

   return out;
}

Squadron& Squadron::operator+= (const Ship& ship) {
    addShipToSelf(ship);
    return *this;
}

Squadron& Squadron::operator-= (const Ship &ship) {
    removeShipToSelf(ship);
    return *this;
}

/// Member

Squadron::Member::Member(const Ship *ship) : ship(ship), next(nullptr) {}

Squadron::Member* Squadron::Member::getNext() const{
    return next;
}

const Ship& Squadron::Member::getShip() const{
    return *ship;
}

void Squadron::Member::setNext(Squadron::Member *next) {
    this->next = next;
}

bool Squadron::Member::hasNext() const{
    return next != nullptr;
}

/// Friend
std::ostream& operator<<(std::ostream& out, const Squadron& squadron) {
    return squadron.toStream(out);
}

Squadron Squadron::operator+(Ship &ship) const{
   return addShip(ship);
}

Squadron Squadron::operator-(const Ship &ship) const{
   return removeShip(ship);
}

const Ship &Squadron::operator[](unsigned index) const{
    return getMember(index)->getShip();
}

const Ship *Squadron::getLeader() const {
   if(this->leader == nullptr)
      return nullptr;

   return &this->leader->getShip();
}

void Squadron::removeLeader() {
   this->leader = nullptr;
}

size_t Squadron::getSize() const{
   if(this->isEmpty())
      return 0;

   Member* m = this->firstMember;
   unsigned int counter = 1;
   while (m->hasNext()){
      counter++;
      m = m->getNext();
   }
   return counter;
}

void Squadron::emptySquad() {
   for (int i = 0; i < this->getSize(); ++i) {
      this->removeShip(this->getMember(i)->getShip()) ;
   }
   this->removeLeader();
}

void Squadron::setName(std::string name) {
   this->name = std::move(name);
}

std::string Squadron::getName() const{
   return this->name;
}

void Squadron::copySquad(const Squadron &squadron) {
   Member *currentMember = squadron.firstMember;
   while (currentMember != nullptr) {
      addShipToSelf(currentMember->getShip());
      currentMember = currentMember->getNext();
   }
   if(squadron.leader != nullptr)
      setLeader(squadron.leader->getShip());
}
