//
// Created by NelsonWork on 18.03.2022.
//

#ifndef POA_L2_SQUADRON_H
#define POA_L2_SQUADRON_H

#include <vector>
#include "Ship.h"

class Squadron {
    class Member {
        Ship* ship;
        Member* next;
    public:
        Member(Ship* ship);
        Ship* getShip();
        Member* getNext();
        void setNext(Member* next);
        bool hasNext();
    };

    /// Ships contained in the squadron
    Member *firstMember;

    /// Leader of the squadron
    Member *leader;

    /// Name of the squadron
    std::string name;

    Member* getMember(Ship* ship);
    bool isEmpty();
public:
    Squadron(const std::string &name);
    Squadron(const Squadron& squadron);
    Squadron& operator=(const Squadron& squadron);
    ~Squadron();
    void addShip(Ship* ship);
    void removeShip(Ship* ship);
    bool containsShip(Ship* ship);
    
    void print() const; 

    /// Set leader of the squadron
    void setLeader(Ship* ship);
    /// Remove leader of the squadron
    /// Get leader of the squadron
    Ship* getLeader() const;

};


#endif //POA_L2_SQUADRON_H
