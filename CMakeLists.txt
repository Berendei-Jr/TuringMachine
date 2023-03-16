cmake_minimum_required(VERSION 3.12)
project(turing_runner)

add_subdirectory(turing_lib)

add_executable(${PROJECT_NAME} example.cpp)
target_link_libraries(${PROJECT_NAME} turing)
