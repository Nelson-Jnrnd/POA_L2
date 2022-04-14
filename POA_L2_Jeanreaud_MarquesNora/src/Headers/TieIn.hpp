#ifndef POA_L2_TIEIN_HPP
#define POA_L2_TIEIN_HPP

#include "Ship.hpp"
/**
 * @brief Represent a specific model of a Star Wars spaceship
 * @link Ship
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class TieIn : public Ship {
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
     * @brief Construct a new TieIn object
     */
    TieIn();
    std::string getModel() const override;
    unsigned int getModelSpeedMax() const override;
    double getModelWeight() const override;
};


#endif //POA_L2_TIEIN_HPP
