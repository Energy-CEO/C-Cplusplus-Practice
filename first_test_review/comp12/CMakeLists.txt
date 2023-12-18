cmake_minimum_required(VERSION 3.27)
project(comp12)

set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

add_executable(comp12 main.cpp
        utility/vector2d/Vector2d.h
        utility/vector2d/Vector2d.cpp
        utility/random/RandomGenerator.cpp
        utility/random/RandomGenerator.h
        velocity/entity/Velocity.cpp
        velocity/entity/Velocity.h
        mysql/DbProcess.cpp
        mysql/DbProcess.h
        acceleration/entity/Acceleration.cpp
        acceleration/entity/Acceleration.h)


target_include_directories(comp12 PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(comp12 PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})


