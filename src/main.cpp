#include <iostream>
#include "Headers/TieLn.hpp"
#include "Headers/Shuttle.hpp"
#include "Headers/Squadron.hpp"

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
