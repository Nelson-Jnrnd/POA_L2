//
// Created by NelsonWork on 18.03.2022.
//

#ifndef POA_L2_SHIP_H
#define POA_L2_SHIP_H

#include "iostream"

/// Represent a Star Wars spaceship
class Ship {
    /// current speed of this spaceship in MGLT
    unsigned speed;
    /// distance travelled by this ship in mio. Km
    double distance;
    /// nickname given to this spaceship, can be null
    std::string nickname;
    /// serial number of this ship
    unsigned int serialNumber;

protected:
/// Constructor
/// @serialNumber serial number of this ship
Ship(unsigned int serialNumber);
void write(std::ostream& out) const;
public:
    friend std::ostream& operator<<(std::ostream& out, const Ship& ship);

    /// Give a new nickname to this ship
    /// \param newNickname nickname given to this ship
    void setNickname(const std::string &newNickname);
    /// Get the nickname given to the ship
    /// \return the nickname of the ship, if the ship has no nickname, returns an empty string
    std::string getNickname() const;
    /// Get the current consumption of the ship in tons
    /// \return the consumption of the ship in tons
    double getConsumption() const;
    /// Get the model of the ship
    /// \return the model of the ship
    virtual std::string getModel() const = 0;
    /// Get the maximum speed of the ship model
    /// \return the maximum speed of the ship model
    virtual unsigned int getModelSpeedMax() const = 0;
    /// Get the weight of the ship model
    /// \return the weight of the ship model
    virtual double getModelWeight() const = 0;
    /// Get the serial number of the next ship to be built
    /// \return the serial number of the next ship to be built
    virtual unsigned int getNextSerialNumber() = 0;
};


#endif //POA_L2_SHIP_H
