//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP26_UNIFORMACCELERATIONREPOSITORY_H
#define COMP26_UNIFORMACCELERATIONREPOSITORY_H

class UniformAccelerationRepository {
public:
    virtual double calculateTime(double distance, double acceleration) = 0;
    virtual double calculateTerminalVelocity(double acceleration, double time) = 0;
};

#endif //COMP26_UNIFORMACCELERATIONREPOSITORY_H
