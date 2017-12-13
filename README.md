# PCSC2017_Group2
Monte Carlo 

Compiling test suit

Inside "PCSC2017_Group2/tests/", there are four cpp files, each evaluating one of the features of Monte Carlo integration.
1. Test: Evaluates three integral numerically
2. StatisticalMomenst: Evaluates statistical moments of guassian distribution up to power 10
3. CentralLimitTheory: Integrates the same function many time to find the distribution of answers
4. Errors: Evaluates the true and estimated error for an specific function.


Program flow

For running the program, one should first specify the followings out side of the main block:
1. function that should be integrated
2. the non-negative weight function (if Metropolis method is chosen)

Next step is to specify the method of integration by creating objects of the following classes inside the main block:
1. MonteCarlo_UniformSampling
2. MonteCarlo_MetropolisAlgorithm

After that, user have to link the function and its weight to those defined outside the main by using the following methods:
1. SetFunction
2. SetWeight

Next step is specifying the upper and lower limit of integration. the moment (if it is desired), and the number of sampling by using the following methods:
1. SetLowerLimit
2. SetUpperLimit
3. SetMoment
4. SetSamplingNumber

Finally, the method below, will return an array which contains the value of the integral in the first element and the evaluated error in the second one:
1. Integrator


List of fuatures

1. Integrating R to R functions inside a bounded domain using Uniform Sampling and Importance Sampling (using Metropolis procedure)
2. Computing different statistical moments of a function (integer or non-integer)
3. Normalizing weight function if needed only by taking a flag
4. Estimating error of integration
5. Integration in unbounded domain (should by used with caution, not recommended for all functions)
6. Being able to increase the accuracy by taking more samples as user's wish


List of tests

We have tested program under the following benchmarks:
1. Computing Pi=3.14159...
2. Computing normal distribution integral
3. Computing gamma-function for z=4
4. Evaluating error and comparing them with true error for all integrals above
5. Computing even-moments of normal distribution up to 10


To-dos and prespective

The program can be extended to cover the following:

1. being able to compute integrals from R^n to R


