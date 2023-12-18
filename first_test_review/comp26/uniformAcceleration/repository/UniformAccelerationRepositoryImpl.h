//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP26_UNIFORMACCELERATIONREPOSITORYIMPL_H
#define COMP26_UNIFORMACCELERATIONREPOSITORYIMPL_H


#include <iostream>
#include <math.h>
#include "UniformAccelerationRepository.h"

class UniformAccelerationRepositoryImpl : public UniformAccelerationRepository {
private:
    static UniformAccelerationRepositoryImpl instance;

public:
    static UniformAccelerationRepositoryImpl& getInstance();
    double calculateTime(double distance, double acceleration) override;
    double calculateTerminalVelocity(double acceleration, double time) override;
};


#endif //COMP26_UNIFORMACCELERATIONREPOSITORYIMPL_H
