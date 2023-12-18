//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP26_RAILGUNCONTROLLER_H
#define COMP26_RAILGUNCONTROLLER_H


#include <iostream>
#include <memory>

class RailGunController {
private:
    std::unique_ptr<RailGunService> railGunService;
    static RailGunController instance;

public:
    RailGunController(std::unique_ptr<RailGunService> railGunService);

    static RailGunController& getInstance(std::unique_ptr<RailGunService> railGunService);
    static RailGunController& getInstance();

    void fire();
};


#endif //COMP26_RAILGUNCONTROLLER_H
