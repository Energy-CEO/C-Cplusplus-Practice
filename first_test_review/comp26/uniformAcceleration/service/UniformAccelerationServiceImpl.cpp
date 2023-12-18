//
// Created by eddi on 23. 12. 18.
//

#include "UniformAccelerationServiceImpl.h"

UniformAccelerationServiceImpl UniformAccelerationServiceImpl::instance(nullptr);

UniformAccelerationServiceImpl::UniformAccelerationServiceImpl(
        std::unique_ptr<UniformAccelerationRepository> repository) : uniformAccelerationRepository(std::move(repository)) {}

// 이게 맞나...?
// uniformAccelerationRepository 에 대한 유일한 접근권을 serviceImpl 의 정적 멤버 변수인 instance 에 위임
UniformAccelerationServiceImpl &UniformAccelerationServiceImpl::getInstance(
        std::unique_ptr<UniformAccelerationRepository> repository)  {
    if (!instance.uniformAccelerationRepository) {
        instance.uniformAccelerationRepository = std::move(repository);
    }

    return instance;
}

UniformAccelerationServiceImpl &UniformAccelerationServiceImpl::getInstance() {
    return instance;
}

double UniformAccelerationServiceImpl::calculateTime(double distance, double acceleration) {
    return uniformAccelerationRepository->calculateTime(distance, acceleration);
}

