//
// Created by NelsonWork on 18.03.2022.
//

#ifndef POA_L2_SQUADRON_H
#define POA_L2_SQUADRON_H

#include <vector>
#include "Ship.h"

class Squadron {
    class Member {
        const Ship* ship;
        Member* next;
    public:
        Member(const Ship* ship);
        const Ship* getShip();
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

    Member* getMember(const Ship* ship);
    bool isEmpty() const;
public:
    Squadron(const std::string &name);
    Squadron(const Squadron& squadron);
    Squadron& operator=(const Squadron& squadron);
    ~Squadron();

    /// Writes the details of the squadron into the output stream
    /// @param out output stream
    /// @param squadron squadron to be written
    /// @return output stream
    friend std::ostream& operator<<(std::ostream& out, const Squadron& squadron);

    void addShip(const Ship* ship);
    void removeShip(const Ship* ship);
    bool containsShip(const Ship* ship);
    /// Set leader of the squadron
    void setLeader(const Ship* ship);
    /// Remove leader of the squadron
    /// Get leader of the squadron
    Ship* getLeader() const;

    std::ostream& toStream(std::ostream &out) const;
    Squadron& operator+=(const Ship& ship);
    Squadron& operator-=(const Ship& ship);

    /// Maximum speed this squadron can go at
    unsigned int getMaximumSpeed() const;
    /// Get the consumption of the squadron in tons
    /// @param distance distance in mio kilometers
    /// @param speed speed in MGHT
    /// @return the consumption of the squadron in tons
    double getConsumption(unsigned distance, unsigned speed) const;
};


#endif //POA_L2_SQUADRON_H
