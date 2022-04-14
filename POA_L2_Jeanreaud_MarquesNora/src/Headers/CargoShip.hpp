#ifndef POA_L2_CARGOSHIP_HPP
#define POA_L2_CARGOSHIP_HPP

#include "Ship.hpp"

/**
 * Represent a spaceship with a cargo
 * @link Ship
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class CargoShip : public Ship {
    protected:
    double currentCapacity;
    /**
     * @brief Construct a new Cargo Ship object
     * 
     * @param serialNumber the serial number of the ship
     * @param currentCapacity the current capacity of the ship
     */
    CargoShip(unsigned int serialNumber, double currentCapacity);
    public:
    /** 
     * Get max capacity of the ship in tons
     * @return max capacity of the ship in tons
     */
    virtual double getMaxCapacity() const = 0;
    /**
     * Get the current capacity of the ship in tons
     * @return the current capacity of the ship in tons
     */
    double getCurrentCapacity() const;

    /**
     * Writes the details of the squadron into the output stream.
     * @param out output stream
     * @return output stream
     */
    std::ostream& toStream(std::ostream &out) const;
};


#endif //POA_L2_CARGOSHIP_HPP
