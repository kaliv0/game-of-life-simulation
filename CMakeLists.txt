cmake_minimum_required(VERSION 3.27)
project(game_of_life_simulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(game_of_life_simulation
        src/cell.cpp
        src/cell.h
        src/constants.h
        src/generation.cpp
        src/generation.h
        src/main.cpp)
