cmake_minimum_required(VERSION 3.12)
project(TuringMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(turing example.cpp Turing.cpp Turing.h)
