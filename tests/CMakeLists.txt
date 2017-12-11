set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR})

set(TEST_Source ../AbstractIntegrator.cpp ../AbstractIntegrator.h ../MonteCarlo_UniformSampling.cpp ../MonteCarlo_UniformSampling.h ../MonteCarlo_MetropolisAlgorithm.cpp ../MonteCarlo_MetropolisAlgorithm.h )

add_executable(CentralLimitTheory CentralLimitTheory.cpp ${TEST_Source})
add_executable(Errors Errors.cpp ${TEST_Source})
add_executable(StatisticalMoments StatisticalMoments.cpp ${TEST_Source})