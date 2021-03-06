#ifndef POA_L2_SQUADRON_HPP
#define POA_L2_SQUADRON_HPP

#include <vector>
#include "Ship.hpp"

/**
* Representation of a squadron of ships
* @link Ship
* @version 1.0
* @author Nelson Jeanrenaud
* @author André Marques Nora
*
*/
class Squadron {
   /**
   * Member of the squadron, node of the linked list
   */
   class Member {
     /**
      * Pointer to the ship of the member
      */
     const Ship* ship;
     /**
      * Pointer to the next member of the squadron
      */
     Member* next;
   public:
     /**
      * Construct a new Member object
      * @param ship the ship of the member
      */
     explicit Member(const Ship* ship);
     /**
      * Get the ship of the member
      * @return the ship of the member
      */
     const Ship& getShip() const;
     /**
      * Get the next member of the squadron
      * @return the next member of the squadron
      */
     Member* getNext() const;
     /**
      * Set the next member of the squadron
      * @param next the next member of the squadron
      */
     void setNext(Member* next);

     /**
      * Checks if the member has a next member
      * @return true if the member has a next member, false otherwise
      */
     bool hasNext() const;
   };

   /// Ships contained in the squadron
   Member *firstMember;

   /// Leader of the squadron
   Member *leader;

   /// Name of the squadron
   std::string name;

   /**
   * Get the member of the squadron that has the ship passed as parameter.
   * @param parameter-ship the ship to search
   * @return the member of the squadron that has the ship passed as parameter.
   */
   Member* getMember(const Ship& ship) const;
   /**
   * Get the member of the squadron at the given index
   *
   * @param index the index of the member to get
   * @return Member* the member of the squadron at the given index
   * @throw invalid_argument exception
   */
   Member* getMember(unsigned index) const;
   /**
   * Checks if the squadron is empty.
   * @return true if the squadron is empty, false otherwise
   */
   bool isEmpty() const;
   /**
   * Empty the squadron
   * @param squadron the squadron to copy
   */
   void emptySquad();
   /**
    * Copy a squadron
    * @param squadron squadron to copy
    */
   void copySquad(const Squadron& squadron);
public:

   /**
   * Construct a new Squadron object
   * @param name the name of the squadron
   */
   explicit Squadron(const std::string &name);
   /**
   * Construct a new Squadron object by copying the given squadron
   *
   * @param squadron the squadron to copy
   */
   Squadron(const Squadron& squadron);
   /**
    * operator of affectation
    * @param squadron
    * @return Squadron
    */
   Squadron& operator=(const Squadron& squadron);
   /**
   * Destroys the Squadron object
   */
   ~Squadron();

   /** Writes the details of the squadron into the output stream
   * @param out output stream
   * @param squadron squadron to be written
   * @return output stream
   */
   friend std::ostream& operator<<(std::ostream& out, const Squadron& squadron);

   /**
   * Set leader of the squadron
   * @param ship the ship to set as leader
   * @throw invalid_argument exception
   */
   void setLeader(const Ship& ship);
   /**
   * Remove leader of the squadron
   */
   void removeLeader();
   /**
   * Get leader of the squadron
   * @return the leader of the squadron
   */
   const Ship* getLeader() const;
   /**
    * Set name of squadron
    * @param name squadron's name
    */
   void setName(std::string name);
   /**
    * Get name of squadron
    * @return string squadron's name
    */
   std::string getName() const;
   /**
   * Writes the details of the squadron into the output stream.
   * @param out output stream
   * @return output stream
   */
   std::ostream& toStream(std::ostream &out) const;
   /**
   * Adds a ship to the squadron
   * @param ship the ship to add
   * @throw invalid_argument exception
   */
   void addShipToSelf(const Ship& ship);
   /**
   * Adds a ship to a copy of the squadron
   * @param ship the ship to add
   * @return the copy of the squadron with the ship added
   */
   Squadron addShip(const Ship& ship) const;
   /**
   * Removes a ship from the squadron
   * @param ship the ship to remove
   * @throw invalid_argument exception
   */
   void removeShipToSelf(const Ship& ship);
   /**
   * Removes a ship from a copy of the squadron
   * @param ship the ship to remove
   * @return the copy of the squadron with the ship removed
   */
   Squadron removeShip(const Ship& ship) const;
   /**
   * Adds a ship to the squadron
   * @param ship the ship to add
   */
   Squadron& operator+=(const Ship& ship);
   /**
   * Removes a ship from the squadron
   * @param ship the ship to remove
   */
   Squadron& operator-=(const Ship& ship);

   /**
   * Adds a ship to a copy of the squadron
   * @param ship the ship to add
   * @return the copy of the squadron with the ship added
   */
   Squadron operator+(Ship& ship) const;
   /**
   * Removes a ship from a copy of the squadron
   * @param ship the ship to remove
   * @return the copy of the squadron with the ship removed
   */
   Squadron operator-(const Ship& ship) const;
   /**
   * Get the member of the squadron at the given index
   *
   * @param index the index of the member to get
   * @return Member* the member of the squadron at the given index
   */
   const Ship& operator[](unsigned index) const;

   /**
   * Get the size of the squadron
   * @return the size of the squadron
   */
   size_t getSize() const;

   /**
   * Get the maximum speed this squadron can go at
   *
   * @return the maximum speed this squadron can go at
   */
   unsigned int getMaximumSpeed() const;
   /**
   * Get the total weight of this squadron
   *
   * @return the total weight of this squadron
   */
   double getTotalWeight() const;
   /**
   * Get the consumption of the squadron in tons
   * @param distance distance in mio kilometers
   * @param speed speed in MGHT
   * @return the consumption of the squadron in tons
   * @throw invalid_argument exception
   */
   double getConsumption(unsigned distance, unsigned speed) const;
};

#endif //POA_L2_SQUADRON_HPP
