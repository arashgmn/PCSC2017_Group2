cmake_minimum_required(VERSION 3.8)
project(PCSC2017_Group2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp constants.h)
add_executable(PCSC2017_Group2 ${SOURCE_FILES})
add_executable(fx fx.cpp fx.h)