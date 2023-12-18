//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP12_ACCELERATION_H
#define COMP12_ACCELERATION_H


#include <ostream>

#include "../../utility/vector2d/Vector2d.h"

class Acceleration {

private:
    Vector2d acceleration;

public:
    Acceleration();
    Acceleration(float , float );

    const Vector2d &getAcceleration() const;

    friend std::ostream &operator<<(std::ostream &os, const Acceleration &d);

};


#endif //COMP12_ACCELERATION_H
