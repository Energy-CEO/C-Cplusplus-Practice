//
// Created by eddi on 23. 12. 18.
//

#include "RailGunRepositoryImpl.h"

RailGunRepositoryImpl RailGunRepositoryImpl::instance;

RailGunRepositoryImpl &RailGunRepositoryImpl::getInstance() {
    return instance;
}

void RailGunRepositoryImpl::fire(double expectedTime) {
    std::cout << "RailGun Repository: Fire!" << std::endl;
    std::cout << "Hit after " << expectedTime << "second as an expectation" << std::endl;
}