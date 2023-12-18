//
// Created by eddi on 23. 12. 18.
//
#include <iostream>
#include <thread>
#include <iomanip>

#include "velocity/entity/Velocity.h"
#include "utility/random/RandomGenerator.h"
#include "mysql/DbProcess.h"
#include "acceleration/entity/Acceleration.h"

void initMysqlObject()
{
    const char* host = "localhost";
    const char* user = "eddi";
    const char* pass = "eddi@123";
    const char* dbName = "test_db";

    DbProcess& dbInstance = DbProcess::getInstance(host, user, pass, dbName);
    dbInstance.connect();
}

void random_velocity_record_with_random_time()
{
    DbProcess& dbInstance = DbProcess::getInstance();

    for (int i = 0; i < 10; ++i) {
        double randomDelay = RandomGenerator::getDoubleRandomNumber(0.3, 1.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(randomDelay * 1000)));

        dbInstance.insertData(Velocity(
                RandomGenerator::getIntRandomNumber(5, 10),
                RandomGenerator::getIntRandomNumber(5, 10)
                ));
    }
}

void delete_velocity_info()
{
    DbProcess& dbInstance = DbProcess::getInstance();

    dbInstance.deleteAll("velocity");
}

// timestamp 문자열을 시간 형태로 표현하는 함수
std::chrono::time_point<std::chrono::system_clock> praseTimestamp(const std::string& timestamp)
{
    std::tm tm = {};
    long long milliseconds = 0;

    // 문자열 파싱 함수
    // string 을 입력 받아 다른 형식으로 바꿔주는 함수
    std::istringstream ss(timestamp);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S.");
    ss >> milliseconds;

    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    tp += std::chrono::milliseconds(milliseconds);

    return tp;
}

std::list<Acceleration> calculateAccelerationFromVelocityDerivative ()
{
    // Db 에 접속
    DbProcess& dbInstance = DbProcess::getInstance();
    // DB 에서 속도 리스트 호출
    std::list<Velocity> velocityList = dbInstance.findAll();

    // 리스트 출력
    for (const auto& velocity : velocityList) {
        std::cout << velocity << std::endl;
    }

    // 가속도 리스트 생성
    std::list<Acceleration> accelerationList;

    // velocityList 를 순회하며 끝에 도달했을 때
    auto velocity = velocityList.begin();
    if (velocity == velocityList.end()) {
        std::cerr << "Not enough data for acceleration calculation." << std::endl;
        return accelerationList;
    }

    // 이전 속도를 나타내는 prevVelocity 객체 생성
    Velocity prevVelocity = *velocity;
    ++velocity;

    // 무조건 for 문
    for (; velocity != velocityList.end(); ++velocity)
    {
        // 두 개의 시간 시점을 가져옴
        // 이미 praseTimestamp 함수를 통해 timestamp 를 parameter 로 입력 받아서 시간으로 해석하는 과정을 거침
        auto timestamp1 = praseTimestamp(prevVelocity.getTimestamp());
        auto timestamp2 = praseTimestamp(velocity->getTimestamp());

        // duration.count()를 통해 함수의 실행 시간 간격을 알 수 있음
        auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(timestamp2-timestamp1).count();
        std::cout << "deltaTime: " << deltaTime << ", ";

        // 바로 이전 속도와 다음으로 생성된 속도 벡터 성분 간의 차이를 구함
        double deltaVx = velocity->getVelocity().getX() - prevVelocity.getVelocity().getX();
        double deltaVy = velocity->getVelocity().getY() - prevVelocity.getVelocity().getY();

        // 각 성분 별로 가속도를 구함
        double accelerationX = deltaVx / deltaTime;
        double accelerationY = deltaVy / deltaTime;
        std::cout << "acceleration: (" << accelerationX << ", " << accelerationY << ")" << std::endl;

        // 두 가속도 성분을 실수 타입으로 accelerationList 에 추가
        // push_back : 임시로 객체를 생성하여 list, vector 에 값을 넣고 객체를 없애줌
        accelerationList.push_back({static_cast<float>(accelerationX), static_cast<float>(accelerationY)});

        prevVelocity = *velocity;
    }

    return accelerationList;
}

void calculateDisplacementFromVelocity ()
{
    // 초기 위치 생성
    Vector2d displacement(0, 0);

    // DB 에서 속도 리스트 호출
    DbProcess& dbInstance = DbProcess::getInstance();
    std::list<Velocity> velocityList = dbInstance.findAll();

    // velocityList
    // 아래의 velocity 는 결국 velocity iterator element 와 같음
    auto velocity = velocityList.begin();
    if (velocity == velocityList.end()) {
        std::cerr << "Not enough data for acceleration calculation." << std::endl;
    }

    // 이전 속도를 나타내는 prevVelocity 객체 생성
    Velocity prevVelocity = *velocity;
    ++velocity;

    // 무조건 for 문
    for (; velocity != velocityList.end(); ++velocity) {
        auto timestamp1 = praseTimestamp(prevVelocity.getTimestamp());
        auto timestamp2 = praseTimestamp(velocity->getTimestamp());

        auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(timestamp2 - timestamp1).count();
        double displacementX = (prevVelocity.getVelocity().getX() + velocity->getVelocity().getX()) / 2 * deltaTime;
        double displacementY = (prevVelocity.getVelocity().getY() + velocity->getVelocity().getY()) / 2 * deltaTime;

        displacement += Vector2d(displacementX, displacementY);
        std::cout << "displacement: " << displacement << std::endl;

        prevVelocity = *velocity;
    }
}

int main () {
    initMysqlObject();
    random_velocity_record_with_random_time();
    calculateAccelerationFromVelocityDerivative();
    calculateDisplacementFromVelocity();

    delete_velocity_info();

    return 0;
}