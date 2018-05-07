cmake_minimum_required(VERSION 3.9)
project(Tutorial)

set(CMAKE_C_STANDARD 99)

add_executable(Tutorial main.c)

target_link_libraries(Tutorial m)