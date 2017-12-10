cmake_minimum_required(VERSION 3.8)
project(PCSC2017_Group2)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp AbstractIntegrator.cpp AbstractIntegrator.h MonteCarlo_UniformSampling.cpp MonteCarlo_UniformSampling.h MonteCarlo_MetropolisAlgorithm.cpp MonteCarlo_MetropolisAlgorithm.h tests/Errors.cpp tests/Errors.h tests/StatisticalMoments.cpp tests/StatisticalMoments.h tests/CentralLimitTheory.cpp tests/CentralLimitTheory.h)

add_executable(PCSC2017_Group2 ${SOURCE_FILES})
add_executable(PCSC2017_Group2/tests/ ${SOURCE_FILES})