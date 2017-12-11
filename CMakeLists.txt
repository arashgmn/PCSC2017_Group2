cmake_minimum_required(VERSION 3.8)
project(PCSC2017_Group2)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp AbstractIntegrator.cpp AbstractIntegrator.h MonteCarlo_UniformSampling.cpp MonteCarlo_UniformSampling.h MonteCarlo_MetropolisAlgorithm.cpp MonteCarlo_MetropolisAlgorithm.h )

add_executable(PCSC2017_Group2 ${SOURCE_FILES})
ADD_SUBDIRECTORY(tests)