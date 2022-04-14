#ifndef POA_L2_SHIP_H
#define POA_L2_SHIP_H

#include "iostream"

class Ship;

std::ostream& operator<<(std::ostream& out, const Ship& ship);


/**
 * Represent a Star Wars spaceship
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Ship {
    /// nickname given to this spaceship, can be null
    std::string nickname;
    /// serial number of this ship
    unsigned int serialNumber;
protected:
    /**
     * Construct a new Ship object
     * 
     * @param serialNumber serial number of this ship
     */
    explicit Ship(unsigned int serialNumber);

public:
    virtual ~Ship();
    friend std::ostream& operator<<(std::ostream& out, const Ship& ship);
    virtual std::ostream& toStream(std::ostream& out) const;
    /**
     * Give a new nickname to this ship
     * 
     * @param newNickname nickname given to this ship
     */
    void setNickname(const std::string &newNickname);
    /**
     * Get the nickname of the ship
     * @return the nickname of the ship, if the ship has no nickname, returns an empty string
     */
    std::string getNickname() const;
    /**
     * Get the consumption of the ship in tons
     * @param distance distance traveled in mio km
     * @param speed speed of the ship in MGLT
     * @return the consumption of the ship in tons
     */
    double getConsumption(unsigned distance, unsigned speed) const;
    /**
     * Get the Model object
     * 
     * @return the model of the ship    
     */
    virtual std::string getModel() const = 0;
    /**
     * Get the maximum speed of the ship model
     * 
     * @return the maximum speed of the ship model
     */
    virtual unsigned int getModelSpeedMax() const = 0;
    /**
     * Get the weight of the ship model
     * 
     * @return the weight of the ship model
     */
    virtual double getModelWeight() const = 0;
    /**
     *  Get the serial number of the next ship to be built
     * 
     * @return the serial number of the next ship to be built
     */
    virtual unsigned int getNextSerialNumber() = 0;
};


#endif //POA_L2_SHIP_H
