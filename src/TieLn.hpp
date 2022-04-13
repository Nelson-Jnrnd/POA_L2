//
// Created by NelsonWork on 31.03.2022.
//

#ifndef POA_L2_TIELN_HPP
#define POA_L2_TIELN_HPP


#include "Ship.hpp"
/**
 * @brief Represent a specific model of a Star Wars spaceship
 * @link Ship
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class TieLn : public Ship {
    /// Count of the number of ships created
    static unsigned int serialNumberCounter;
    /**
     * @brief Get the Next Serial Number object. Increments the counter
     * 
     * @return the next serial number
     */
    unsigned int getNextSerialNumber() override;
    public:
        /**
         * @brief Construct a new TieLn object
         */
        TieLn();
        std::string getModel() const override;
        unsigned int getModelSpeedMax() const override;
        double getModelWeight() const override;
};


#endif //POA_L2_TIELN_HPP
