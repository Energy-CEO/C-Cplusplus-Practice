cmake_minimum_required(VERSION 3.16)
project(comp24)

set(CMAKE_CXX_STANDARD 17)

add_executable(comp24 main.cpp
        product/entity/product.h
        product/entity/product.c)
