﻿cmake_minimum_required(VERSION 3.31)
project(code C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/ds/inc)

add_executable(code ds/src/main.c
        ds/inc/sl_list.h
        ds/src/sl_list.c
        ds/inc/dl_list.h
        ds/src/dl_list.c
        ds/inc/cl_list.h
        ds/src/cl_list.c
        ds/inc/array.h
        ds/src/array.c
        ds/inc/queue.h
        ds/inc/buffer.h
        ds/src/buffer.c
        ds/inc/stack.h
        ds/inc/deque.h
        ds/src/ex/max_sliding_window.c
        ds/inc/ex.h
        ds/src/sort/bubble.c)
