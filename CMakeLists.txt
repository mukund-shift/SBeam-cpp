cmake_minimum_required(VERSION 4.3)
project(SBeam_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(day_16)

add_executable(SBeam_cpp
        day_01/assign01_p1.cpp
        day_01/assign01_p2.cpp
        day_02/assign_02.cpp
        day_03/assign03.cpp
        day_04/assign04.cpp
        day_05/assign05.cpp
        day_06/assign06.cpp
        day_06/assign06_p2.cpp
        day_07/assign07.cpp
        day_08/assign_08.cpp
        day_08/live.cpp
        day_09/assign_09.cpp
        day_10/assign10.cpp
        day_11/assign11.cpp
        day_12/assign12_p1.cpp
        day_12/assign12_p2.cpp
        day_13_ciap_microproject/microproject_classes.cpp
        day_14/assign14_p1.cpp
        day_14/assign14_p2.cpp
        day_14/assign14_p3.cpp
        day_16/assign16_p1.cpp
        day_16/assign16_p1.h
        day_16/assign16_p2.cpp
        day_16/assign16_p2.h
        day_16/test.cpp
        day_23/assign23.cpp)

add_executable(assign23 day_23/assign23.cpp)