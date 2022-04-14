#include <iostream>
#include "TieLn.hpp"
#include "Shuttle.hpp"
#include "Squadron.hpp"

int main() {
    TieLn blackLeader;
    blackLeader.setNickname("Black leader");
    TieLn blackTwo;
    Shuttle shuttle(23.4);

    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;

    squad.setLeader(blackLeader);

    std::cout << squad;

    return 0;
}
