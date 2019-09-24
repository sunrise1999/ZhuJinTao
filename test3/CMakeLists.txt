cmake_minimum_required(VERSION 3.14)
project(test3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(test3
        fun.c
        head.h
        test.c)
