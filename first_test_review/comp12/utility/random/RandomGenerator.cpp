//
// Created by eddi on 23. 12. 18.
//

#include "RandomGenerator.h"

// static 붙어 있는 경우 new 없이 사용 가능 (memory 에 상주하기 때문임)
// 정적 멤버 변수에 접근하는 방법은 아래와 같이 초기화 후
// class 이름으로 접근하거나 인스턴스를 통해 접근
std::random_device RandomGenerator::randomDevice;

std::mt19937 RandomGenerator::intGenerator(randomDevice());
std::mt19937 RandomGenerator::doubleGenerator(randomDevice());

std::uniform_int_distribution<int> RandomGenerator::intDistribution;
std::uniform_real_distribution<double> RandomGenerator::doubleDistribution;

int RandomGenerator::getIntRandomNumber(int min, int max) {
    intDistribution.param(std::uniform_int_distribution<int>::param_type(min, max));
    return intDistribution(intGenerator);
}

double RandomGenerator::getDoubleRandomNumber(double min, double max) {
    doubleDistribution.param(std::uniform_real_distribution<double>::param_type(min, max));
    return doubleDistribution(doubleGenerator);
}