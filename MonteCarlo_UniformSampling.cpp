#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include "MonteCarlo_UniformSampling.h"

using namespace std;

// Constructor and destructor

MonteCarlo_UniformSampling::MonteCarlo_UniformSampling(){};
MonteCarlo_UniformSampling::~MonteCarlo_UniformSampling(){};

// Integrator

double* MonteCarlo_UniformSampling::Integrator() {

    // for generating random numbers
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // getting integral arguments
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    // parameters of integration
    double sum = 0;                     // sum of samples
    double sum2 = 0;                    // sum of squares
    double x,y;                         // Markov chain parameters

    // evaluating integral
    for (int i = 1; i <= N; ++i){
        x = a + (b-a) * distribution(generator);
        y = FunctionValue(x) * pow(x,m);
        sum = sum + y;
        sum2 = sum2 + y*y;
    }

    // evaluating error
    sum /= N;
    sum2 /= N;
    double err= sqrt( (sum2-sum*sum) / N) * (b-a);

    // returning the value of integral and its error
    double *ans = new double[2];
    ans[0] = sum * (b-a);
    ans[1] = err;
    return ans;
}