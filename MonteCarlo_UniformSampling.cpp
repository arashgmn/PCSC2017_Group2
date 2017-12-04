#include <cmath>
#include "MonteCarlo_UniformSampling.h"
#include "stdlib.h"
#include "iostream"

MonteCarlo_UniformSampling::MonteCarlo_UniformSampling(){};
MonteCarlo_UniformSampling::~MonteCarlo_UniformSampling(){};
double MonteCarlo_UniformSampling::Integrator() {
    srand(time(NULL));
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    double x;
    double sum = 0;

    for (int i = 1; i <= N; ++i){
        x=a+(b-a)*((double)rand()/RAND_MAX);    //here sth is wrong
        sum = sum + FunctionValue(x)*pow(x,m);
        //std::cout<<x<<"\n";
    }
    return sum/N;
}