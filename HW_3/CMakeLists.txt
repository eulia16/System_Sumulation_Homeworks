cmake_minimum_required(VERSION 3.26)
project(HW_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW_3 main.cpp
        XORModel.cpp
        XORModel.h
        MemoryModel.cpp
        MemoryModel.h
        NetworkModel.cpp
        NetworkModel.h)
