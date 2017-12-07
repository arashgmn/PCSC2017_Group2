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


    double sum = 0;
    double p_old, p_new,x_old,x_new;
    double delta=0.1;

    x_new=(a+b)/2;
    p_new = FunctionValue(x_new)*pow(x_new,m);

    for (int i = 1; i <= N; ++i){

        x_old=x_new;
        p_old = p_new;

        x_new = x_old + 2*(delta)*((double)rand()/RAND_MAX - 0.5);
        p_new = FunctionValue(x_new)*pow(x_new,m);

        if ((double)rand()/RAND_MAX < p_new/p_old){     //rejection happens
            x_new=x_old;
            sum = sum + p_old;
        }
        else{                                           //acceptance
            sum = sum + p_new;
        }

    }

    return sum/N*(b-a);
}