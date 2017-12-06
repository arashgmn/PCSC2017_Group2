#include "MonteCarlo_MetropolisAlgorithm.h"
#include <cmath>
#include <cstdlib>
#include <ctime>


// Constructor and destructor

MonteCarlo_MetropolisAlgorithm::MonteCarlo_MetropolisAlgorithm(){};
MonteCarlo_MetropolisAlgorithm::~MonteCarlo_MetropolisAlgorithm(){};

// Integrator

double MonteCarlo_MetropolisAlgorithm::Integrator() {
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