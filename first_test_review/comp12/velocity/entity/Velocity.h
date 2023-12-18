//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP12_VELOCITY_H
#define COMP12_VELOCITY_H


#include <ostream>
#include "../../utility/vector2d/Vector2d.h"

class Velocity {

private:
    Vector2d velocity;
    std::string timestamp;

public:
    Velocity();
    Velocity(int, int);
    Velocity(int, int, std::string);

    Vector2d getVelocity() const;

    const std::string &getTimestamp() const;

    friend std::ostream &operator<<(std::ostream &os, const Velocity &d);

};


#endif //COMP12_VELOCITY_H
