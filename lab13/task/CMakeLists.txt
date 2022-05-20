cmake_minimum_required(VERSION 3.22)
project(task)

set(CMAKE_CXX_STANDARD 14)

add_executable(task main.cpp file.h index.h database.h database.cpp file.cpp index.cpp)
