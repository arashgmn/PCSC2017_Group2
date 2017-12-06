#include "MonteCarlo_UniformSampling.h"
#include <cmath>
#include <cstdlib>
#include <ctime>


// Constructor and destructor

MonteCarlo_UniformSampling::MonteCarlo_UniformSampling(){};
MonteCarlo_UniformSampling::~MonteCarlo_UniformSampling(){};

// Integrator

double MonteCarlo_UniformSampling::Integrator() {
    srand(time(NULL));
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    double x;
    double sum = 0;

    for (int i = 1; i <= N; ++i){
        x=a+(b-a)*((double)rand()/RAND_MAX);
        sum = sum + FunctionValue(x)*pow(x,m);
    }

    return sum/N*(b-a);
}