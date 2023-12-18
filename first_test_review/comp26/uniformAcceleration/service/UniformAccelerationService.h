//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP26_UNIFORMACCELERATIONSERVICE_H
#define COMP26_UNIFORMACCELERATIONSERVICE_H

class UniformAccelerationService {
public:
    virtual double calculateTime(double distance, double acceleration) = 0;
};

#endif //COMP26_UNIFORMACCELERATIONSERVICE_H
