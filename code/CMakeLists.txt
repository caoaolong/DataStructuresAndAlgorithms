cmake_minimum_required(VERSION 3.31)
project(code C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/ds/inc)

add_executable(code ds/src/main.c
        ds/inc/ds_list.h
        ds/src/ds_list.c)
