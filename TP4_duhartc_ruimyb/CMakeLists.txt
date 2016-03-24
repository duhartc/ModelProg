cmake_minimum_required(VERSION 3.3)
project(TP4_duhartc_ruimyb)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

set(SOURCE_FILES
    src/main.cpp
    src/Point.tpp
    src/Point.h)

add_executable(TP4_duhartc_ruimyb ${SOURCE_FILES})