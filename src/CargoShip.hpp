//
// Created by NelsonWork on 31.03.2022.
//

#ifndef POA_L2_CARGOSHIP_HPP
#define POA_L2_CARGOSHIP_HPP


#include "Ship.h"

class CargoShip : public Ship {
    protected:
    double currentCapacity;
    CargoShip(unsigned int serialNumber, double currentCapacity);
    public:
    /// Get max capacity of the ship in tons
    /// \return max capacity of the ship in tons
    virtual double getMaxCapacity() const = 0;
    /// Get the current capacity of the ship in tons
    /// \return the current capacity of the ship in tons
    double getCurrentCapacity() const;
    std::ostream& toStream(std::ostream &out) const;
};


#endif //POA_L2_CARGOSHIP_HPP
