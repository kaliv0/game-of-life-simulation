cmake_minimum_required(VERSION 3.27)
project(conways_game_of_life_practical)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(conways_game_of_life_practical
        src/Cell.cpp
        src/Cell.h
        src/Generation.cpp
        src/Generation.h
        src/constants.h
        src/main.cpp)
