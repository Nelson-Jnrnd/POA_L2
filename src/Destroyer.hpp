//
// Created by NelsonWork on 31.03.2022.
//

#ifndef POA_L2_DESTROYER_HPP
#define POA_L2_DESTROYER_HPP

#include "CargoShip.hpp"

/**
 * Represent a specific model of a Star Wars spaceship cargo
 * @link CargoShip
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Destroyer : public CargoShip {
    /// Count of the number of ships created
    static unsigned int serialNumberCounter;
    unsigned int getNextSerialNumber() override;
public:
    /**
     * Construct a new Destroyer ship object
     * @param currentCapacity - current capacity of the ship in tons
     */
    Destroyer(double currentCapacity);

    ~Destroyer();
    /**
     * Get max capacity of the ship in tons
     * @return max capacity of the ship in tons
     */
    double getMaxCapacity() const override;

    /**
     * Get the weight of the ship in tons
     * @return the weight of the ship in tons
     */
    double getModelWeight() const override;

    /**
     * Get the model of the ship
     * @return the model of the ship
     */
    std::string getModel() const override;

    /**
     * Get the maximum speed of the ship model
     * @return the maximum speed of the ship model
     */
    unsigned int getModelSpeedMax() const override;
};


#endif //POA_L2_DESTROYER_HPP
