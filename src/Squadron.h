//
// Created by NelsonWork on 18.03.2022.
//

#ifndef POA_L2_SQUADRON_H
#define POA_L2_SQUADRON_H

#include <vector>
#include "Ship.h"

class Squadron {
    /// Ships contained in the squadron
    std::vector<Ship*> ships;

    /// Leader of the squadron
    Ship *leader;

    /// Name of the squadron
    std::string name;
public:
    Squadron(const std::string &name);
    Squadron(const Squadron& squadron);
    Squadron& operator=(const Squadron& squadron);
    ~Squadron();
    void addShip(Ship* ship);
    void removeShip(Ship* ship);
    bool containsShip(Ship* ship);
    unsigned int getSize() const;
    void print() const; 

    /// Set leader of the squadron
    void setLeader(Ship* ship);
    /// Remove leader of the squadron
    void removeLeader();
    /// Get leader of the squadron
    Ship* getLeader() const;

};


#endif //POA_L2_SQUADRON_H
