#include "MonteCarlo_UniformSampling.h"
#include "stdlib.h"
#include "iostream"
double MonteCarlo_UniformSampling::Integrator() {
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();

    double x;
    double sum = 0;

    for (int i = 1; i <= N; ++i){
        x=a+(b-a)*((double)rand()/RAND_MAX);
        sum = sum + FunctionValue(x);
        //std::cout<<a+(b-a)*((double)rand()/RAND_MAX)<<"\n";
    }
    return sum/N;
}