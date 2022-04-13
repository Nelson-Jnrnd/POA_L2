//
// Created by NelsonWork on 18.03.2022.
//

#ifndef POA_L2_SQUADRON_HPP
#define POA_L2_SQUADRON_HPP

#include <vector>
#include "Ship.hpp"

class Squadron {
    class Member {
        Ship* ship;
        Member* next;
    public:
        explicit Member(Ship* ship);
        ~Member();
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

    Member* getMember(const Ship* ship);
    Member* getMember(unsigned index) const;
    bool isEmpty() const;
    void emptyAndCopy(Squadron squadron);

public:
    explicit Squadron(const std::string &name);
    Squadron(const Squadron& squadron);
    Squadron& operator=(const Squadron& squadron);
    ~Squadron();

    /// Writes the details of the squadron into the output stream
    /// @param out output stream
    /// @param squadron squadron to be written
    /// @return output stream
    friend std::ostream& operator<<(std::ostream& out, const Squadron& squadron);

    void addShipToSelf(Ship* ship);
    Squadron addShip(const Ship* ship);
    void removeShipToSelf(const Ship* ship);
    Squadron removeShip(const Ship* ship);
    bool containsShip(const Ship* ship);
    /// Set leader of the squadron
    void setLeader(const Ship* ship);
    /// Remove leader of the squadron
    void removeLeader();
    /// Get leader of the squadron
    const Ship* getLeader() const;
    void setName(std::string name);
    std::string getName();

    std::ostream& toStream(std::ostream &out) const;
    Squadron& operator+=(const Ship& ship);
    Squadron& operator-=(const Ship& ship);

    Squadron& operator+(const Ship& ship);
    Squadron& operator-(const Ship& ship);
    const Ship& operator[](int index);

    ///
    /// @return the size of the squadron
    size_t getSize() const;

    /// Maximum speed this squadron can go at
    unsigned int getMaximumSpeed() const;

    /// Get the consumption of the squadron in tons
    /// @param distance distance in mio kilometers
    /// @param speed speed in MGHT
    /// @return the consumption of the squadron in tons
    double getConsumption(unsigned distance, unsigned speed) const;


};


#endif //POA_L2_SQUADRON_HPP
