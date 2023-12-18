//
// Created by eddi on 23. 12. 18.
//

#include "Velocity.h"

Velocity::Velocity() : velocity() {}

Velocity::Velocity(int x, int y) : velocity(x, y) {}

// std::move 는 lvalue 를 rvalue 로 변환
Velocity::Velocity(int x, int y, std::string timestamp) : velocity(x, y), timestamp(std::move(timestamp)) {}

Vector2d Velocity::getVelocity() const {
    return velocity;
}

std::ostream &operator<<(std::ostream &os, const Velocity &d) {
    os << "velocity: " << d.velocity;
    if (!d.timestamp.empty()) {
        os << " - " << d.timestamp;
    }
    return os;
}

const std::string &Velocity::getTimestamp() const {
    return timestamp;
}