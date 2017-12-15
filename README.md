# PCSC2017_Group2

Inside PCSC2017_Group2/tests/ there are four CPP files, each evaluating one of the features of Monte Carlo integration:

		Test: Evaluates three integral numerically with both methods (look at list of tests).

		StatisticalMomenst: Evaluates statistical moments of Gaussian distribution up to power 8 using uniform sampling.

		CentralLimitTheory: Integrates the same function many time to find the distribution of answers. 

		Errors: Evaluates the true and estimated error for a specific function.

Program flow

For running the program, one should first specify the followings outside of the main block:
1. The function that should be integrated. It must get a double and returns a double
2. The strictly positive weight function, if Metropolis method is chosen, otherwise not needed.

Next step is to specify the method of integration by creating objects of the following classes inside the main block:
1. MonteCarlo_UniformSampling
2. MonteCarlo_MetropolisAlgorithm

After that, user have to link the function and its weight to those defined outside the main by using the following methods:
1. SetFunction(double (*f)(double x)): The argument is the function defined outside of main
2. SetWeight(double (*w)(double x), bool flag ) : The first argument is the function defined outside of main. The second argument is a flag indicating that if weight function is normalized (true) or not (false). If user is not sure about normalization, he/she can omit the second argument. By default, it is set to false to normalize the weight. Yet it is better to feed this method with normalized weight to avoid normalization error.

Then user have to specify the upper and lower limit of integration, the moment (if it is desired), and the number of sampling by using the following methods:
1. SetLowerLimit(const double a): Specifies lower limit.
2. SetUpperLimit(const double b): Specifies upper limit.
3. SetMoment(const int m): Specifies the moment number.
4. SetSamplingNumber(const int N): Specifies number of samples.

Finally, the method below, will return an array which contains the value of the integral in the first element and the evaluated error in the second one:
1. Integrator(): computes integral with respective method
