cmake_minimum_required(VERSION 3.8)
project(Final-Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final-Project main.cpp Pokemon.cpp FireType.cpp Pokeball.cpp Trainer.cpp WaterType.cpp GrassType.cpp)
add_executable(Testing-Final-Project testing.cpp Pokemon.cpp FireType.cpp Pokeball.cpp Trainer.cpp WaterType.cpp GrassType.cpp)