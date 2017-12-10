cmake_minimum_required(VERSION 3.8)
project(PCSC2017_Group2)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES Errors.cpp Errors.h StatisticalMoments.cpp StatisticalMoments.h)

add_executable(PCSC2017_Group2/tests ${SOURCE_FILES})
