cmake_minimum_required(VERSION 3.31)
project(code C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/ds/inc)

add_executable(sl_list ds/src/sl_list.c ds/src/sl_list_main.c)

add_executable(array ds/src/array.c ds/src/array_main.c)