cmake_minimum_required(VERSION 3.27)
project(comp26)

set(CMAKE_CXX_STANDARD 17)

add_executable(comp26 main.cpp
        railgun/controller/RailGunController.cpp
        railgun/controller/RailGunController.h
        railgun/service/RailGunService.h
        railgun/service/RailGunServiceImpl.cpp
        railgun/service/RailGunServiceImpl.h
        railgun/repository/RailGunRepositoryImpl.cpp
        railgun/repository/RailGunRepositoryImpl.h
        railgun/repository/RailGunRepository.h
        uniformAcceleration/service/UniformAccelerationService.h
        uniformAcceleration/service/UniformAccelerationServiceImpl.cpp
        uniformAcceleration/service/UniformAccelerationServiceImpl.h
        uniformAcceleration/repository/UniformAccelerationRepositoryImpl.cpp
        uniformAcceleration/repository/UniformAccelerationRepositoryImpl.h
        uniformAcceleration/repository/UniformAccelerationRepository.h)
