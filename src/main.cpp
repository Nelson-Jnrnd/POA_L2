#include <iostream>
#include "TieLn.hpp"
#include "Shuttle.hpp"
#include "Squadron.h"

int main() {
    TieLn blackLeader;
    blackLeader.setNickname("Black leader");
    TieLn blackTwo;
    Shuttle shuttle(23.4);

    Squadron squad("Black Squadron");
    squad.addShip(&blackLeader);
    squad.addShip(&blackTwo);
    squad.addShip(&shuttle);

    squad.setLeader(&blackLeader);

    std::cout << squad.toString();
    return 0;
}
