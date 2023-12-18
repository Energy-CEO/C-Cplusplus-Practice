cmake_minimum_required(VERSION 3.10)
project(Product_entity)

set(CMAKE_CXX_STANDARD 17)

file(GLOB C_SOURCES
    "../../product/entity/product.c"
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} gtest_main.cpp ${C_SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

