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
    bool isEmpty() const;
    void write(std::ostream& out) const;
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

    void addShip(Ship* ship);
    void removeShip(Ship* ship);
    bool containsShip(Ship* ship);
    /// Set leader of the squadron
    void setLeader(Ship* ship);
    /// Remove leader of the squadron
    /// Get leader of the squadron
    Ship* getLeader() const;

};


#endif //POA_L2_SQUADRON_H
