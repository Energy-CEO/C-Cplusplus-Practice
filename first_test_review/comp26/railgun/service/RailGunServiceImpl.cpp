//
// Created by eddi on 23. 12. 18.
//

#include "RailGunServiceImpl.h"

RailGunServiceImpl RailGunServiceImpl::instance(nullptr);

// unique_ptr : 하나의 스마트 포인터만이 객체를 소유, 복사 불가능
// 어떤 객체를 unique_ptr 로 만들기 위해 필요한 함수는 make_unique<type>
// move() : 소유권 이전
// 이전에 사용하였던 shared_ptr 의 경우 하나의 특정 개체를 참조하는 스마트 포인터가 몇 개인지를 참조
// 어떤 객체를 shared_ptr 로 만들기 위해 필요한 함수는 make_shared<type>
// auto ptr2(ptr1) 과 같은 형식으로 복사 생성자를 만들수도 있음
RailGunServiceImpl::RailGunServiceImpl(std::unique_ptr<RailGunRepository> repository)
        : railGunRepository(std::move(repository)) {}

RailGunServiceImpl &RailGunServiceImpl::getInstance(std::unique_ptr<RailGunRepository> repository) {
    if (!instance.railGunRepository) {
        instance.railGunRepository = std::move(repository);
    }
    return instance;
}

RailGunServiceImpl &RailGunServiceImpl::getInstance() {
    return instance;
}

void RailGunServiceImpl::fire() {
    std::cout << "RailGun Service: Fire!" << std::endl;


}