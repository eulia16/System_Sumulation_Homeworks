cmake_minimum_required(VERSION 3.26)
project(HW2_Atomic_Model_Coffee_Machine_c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW2_Atomic_Model_Coffee_Machine_c__ main.cpp
        AtomicModelCoffeeMachine.cpp
        AtomicModelCoffeeMachine.h
        InsufficientFundsException.cpp
        InsufficientFundsException.h)
