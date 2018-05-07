cmake_minimum_required(VERSION 3.9)
project(calculateArraySum C)

set(CMAKE_C_STANDARD 99)

add_executable(calculateArraySum main.c)

target_link_libraries(calculateArraySum m)