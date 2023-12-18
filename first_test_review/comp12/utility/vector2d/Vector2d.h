//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP12_VECTOR2D_H
#define COMP12_VECTOR2D_H


#include <ostream>

class Vector2d {
private:
    float x;
    float y;
public:
    Vector2d();
    Vector2d(float, float);

    float getX() const;
    float getY() const;

    Vector2d& operator+=(const Vector2d& other);

    // << 연산자 오버로딩은 다음과 같이 class 내 개인 데이터에 엑세스 가능하도록 friend로 선언해야 함
    friend std::ostream &operator<<(std::ostream &os, const Vector2d &d);
};


#endif //COMP12_VECTOR2D_H
