cmake_minimum_required(VERSION 3.15)
project(console)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(console
        Console.cpp
        Console.h
        main.cpp
        main.h)
