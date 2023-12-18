//
// Created by eddi on 23. 12. 18.
//

#include "Acceleration.h"

Acceleration::Acceleration() : acceleration() {}

Acceleration::Acceleration(float x, float y) : acceleration(x, y) {}

const Vector2d &Acceleration::getAcceleration() const {
    return acceleration;
}

std::ostream &operator<<(std::ostream &os, const Acceleration &d) {
    os << "acceleration: " << d.acceleration;
    return os;
}