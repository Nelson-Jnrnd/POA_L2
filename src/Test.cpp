#include <iostream>
#include "Squadron.hpp"
#include "TieLn.hpp"
#include "Shuttle.hpp"
#include "TieIn.hpp"
#include "Destroyer.hpp"

int main(){

   /*
    * Test class Ship
    */

   TieLn blackLeader;
   TieIn blackOne;
   Destroyer blackTwo(320.6);
   Shuttle blackThree(23.4);
   //Shuttle overWeight(90.4);

   blackLeader.setNickname("Black Star");

   std::cout << blackLeader << std::endl;
   std::cout << blackTwo << std::endl;

   std::cout << "Consumption of blackOne for a distance of 1000 and speed at 50 MGLT : "
      << blackOne.getConsumption(1000,50) << std::endl;

   //std::cout << "Consumption of blackTwo for a distance of 1000 and speed at 1000 MGLT : "
   //          << blackTwo.getConsumption(1000,1000) << std::endl;

   std::cout << "Consumption of blackThree for a distance of 1000 and speed at 50 MGLT : "
             << blackThree.getConsumption(1000,50) << std::endl;

   std::cout << std::endl;


   /*
    * Test class Squadron
    */

   // constructor, add ship to squad and set a leader
   Squadron blackSquad("Black Squadron");

   std::cout << blackSquad.getName() << std::endl;

   std::cout << blackSquad << std::endl;

   blackSquad += blackLeader;
   blackSquad += blackOne;
   blackSquad + blackTwo;
   blackSquad += blackThree;

   blackSquad.setLeader(&blackLeader);

   std::cout << blackSquad << std::endl;

   //constructor by copy, remove ship from squad and remove leader
   Squadron blackSquad2(blackSquad);

   std::cout << blackSquad2 << std::endl;

   blackSquad2.removeLeader();

   std::cout << "squad2" << blackSquad2 << std::endl;

   blackSquad2 -= blackLeader;
   blackSquad2 - blackThree;

   std::cout << blackSquad2 << std::endl;

   TieLn blackLeader2;
   blackLeader2.setNickname("Black Comet");

   //blackSquad2.setLeader(&blackLeader2);

   blackSquad2 += blackLeader2;
   blackSquad2.setLeader(&blackLeader2);

   std::cout << blackSquad2 << std::endl;

   //operator= and operator[]
   std::cout << "operator = & []" << std::endl;
   std::cout << std::endl;

   Destroyer blueLeader(60);
   Shuttle blueOne(10);

   Squadron blueSquad("Blue Squadron");

   blueSquad += blueLeader;
   blueSquad += blueOne;

   blueSquad.setLeader(&blueLeader);
   std::cout << blueSquad << std::endl;

   blueSquad = blackSquad;

   blueSquad.setName("Blue Monkey");

   std::cout << blueSquad << std::endl;

   std::cout << blueSquad[0] << std::endl;

   //std::cout << blueSquad[10] << std::endl;

   return 0;
}
