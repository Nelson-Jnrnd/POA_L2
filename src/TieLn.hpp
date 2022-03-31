//
// Created by NelsonWork on 31.03.2022.
//

#ifndef POA_L2_TIELN_HPP
#define POA_L2_TIELN_HPP


#include "Ship.h"

class TieLn : public Ship {
    static unsigned int serialNumberCounter;
    unsigned int getNextSerialNumber() override;
    public:
        TieLn();
        std::string getModel() const override;
        unsigned int getModelSpeedMax() const override;
        double getModelWeight() const override;
};


#endif //POA_L2_TIELN_HPP
