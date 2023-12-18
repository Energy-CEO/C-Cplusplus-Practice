//
// Created by eddi on 23. 12. 18.
//

#include "UniformAccelerationRepositoryImpl.h"

UniformAccelerationRepositoryImpl UniformAccelerationRepositoryImpl::instance;

UniformAccelerationRepositoryImpl &UniformAccelerationRepositoryImpl::getInstance() {
    return instance;
}

// 초기 속도가 0이라 가능한 형태
double UniformAccelerationRepositoryImpl::calculateTime(double distance, double acceleration) {
    std::cout << "Uniform Acceleration Repository: calculate time" << std::endl;
    return sqrt(2 * distance / acceleration);
}

// 초기 속도가 0이라 가능한 형태
double UniformAccelerationRepositoryImpl::calculateTerminalVelocity(double acceleration, double time) {
    return acceleration * time;
}