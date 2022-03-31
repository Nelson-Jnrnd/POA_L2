//
// Created by NelsonWork on 31.03.2022.
//

#ifndef POA_L2_DESTROYER_HPP
#define POA_L2_DESTROYER_HPP

#include "CargoShip.hpp"

class Destroyer : public CargoShip {
    static unsigned int serialNumberCounter;
    unsigned int getNextSerialNumber() override;
public:
    /**
     * @brief Construct a new Destroyer ship object
     * @param currentCapacity - current capacity of the ship in tons
     */
    Destroyer(double currentCapacity);

    /**
     * @brief Get max capacity of the ship in tons
     * @return max capacity of the ship in tons
     */
    double getMaxCapacity() const override;

    /**
     * @brief Get the weight of the ship in tons
     * @return the weight of the ship in tons
     */
    double getModelWeight() const override;

    /**
     * @brief Get the model of the ship
     * @return the model of the ship
     */
    std::string getModel() const override;

    /**
     * @brief Get the maximum speed of the ship model
     * @return the maximum speed of the ship model
     */
    unsigned int getModelSpeedMax() const override;
};


#endif //POA_L2_DESTROYER_HPP
