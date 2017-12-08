#include "MonteCarlo_UniformSampling.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

// Constructor and destructor

MonteCarlo_UniformSampling::MonteCarlo_UniformSampling(){};
MonteCarlo_UniformSampling::~MonteCarlo_UniformSampling(){};

// Integrator

double MonteCarlo_UniformSampling::Integrator() {

    //random
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    //Getting integral arguments
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    //parameters of integration
    double sum = 0;                     //sum of samples
    double sum2 = 0;                    //sum^2 of samples
    double x,y;                         //Marcov chain parameters

    //evaluating integral
    for (int i = 1; i <= N; ++i){
        x = a + (b-a) * distribution(generator);
        y = FunctionValue(x) * pow(x,m);
        sum = sum + y;
        sum2 = sum2 + y*y;
    }

    //evaluating error
    sum /= N;
    sum2 /= N;
    double err= sqrt( (sum2-sum*sum) / N) *(b-a);
    SetError(err);

    cout<<"error of Uniform is "<<GetError()*100<<"%"<<endl;
    return sum/(b-a);
}