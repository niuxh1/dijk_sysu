cmake_minimum_required(VERSION 3.29)
project(map_for_sysu)

set(CMAKE_CXX_STANDARD 20)

add_executable(map_for_sysu main.cpp
        point.cpp
        all_points.h
        all_points.cpp
        map_sysu.h
        map_sysu.cpp
        dijk.cpp
        dijk.h)
