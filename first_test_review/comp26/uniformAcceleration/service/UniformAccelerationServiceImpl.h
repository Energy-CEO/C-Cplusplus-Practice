//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP26_UNIFORMACCELERATIONSERVICEIMPL_H
#define COMP26_UNIFORMACCELERATIONSERVICEIMPL_H


#include <iostream>
#include <memory>
#include "UniformAccelerationService.h"
#include "../repository/UniformAccelerationRepository.h"

class UniformAccelerationServiceImpl : public UniformAccelerationService {
private:
    static UniformAccelerationServiceImpl instance;
    std::unique_ptr<UniformAccelerationRepository> uniformAccelerationRepository;
public:
    UniformAccelerationServiceImpl(std::unique_ptr<UniformAccelerationRepository> uniformAccelerationRepository);

    static UniformAccelerationServiceImpl& getInstance(std::unique_ptr<UniformAccelerationRepository> uniformAccelerationRepository);
    static UniformAccelerationServiceImpl& getInstance();

    double calculateTime(double distance, double acceleration) override;

};


#endif //COMP26_UNIFORMACCELERATIONSERVICEIMPL_H
