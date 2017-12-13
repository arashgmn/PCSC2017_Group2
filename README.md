# PCSC2017_Group2
Monte Carlo 

Compiling test suit

Inside "PCSC2017_Group2/tests/", there are four cpp files, each evaluating one of the features of Monte Carlo integration.
1. Test: Evaluates three integral numerically
2. StatisticalMomenst: Evaluates statistical moments of guassian distribution up to power 10
3. CentralLimitTheory: Integrates the same function many time to find the distribution of answers
4. Errors: Evaluates the true and estimated error for an specific function.

Program flow
For running the program, one should specify the followings out side of the main block:
1. function that should be integrated
2. the non-negative weight function (if Metropolis method is chosen)

In the main block, one can specify the method of integration by creating objects of the following classes:
1. MonteCarlo_UniformSampling
2. MonteCarlo_MetropolisAlgorithm



