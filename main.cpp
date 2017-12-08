#include <iostream>
#include <cmath>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"
#include "MonteCarlo_MetropolisAlgorithm.h"
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

double f(double x)
{
    return 4/(1+pow(x,2));
}

double w(double x)
{
    return (4-2*x)/3;
}

int main() {
    double ExactValue = M_PI;

    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(10000);
    I.SetFunction(f);
    //I.SetMoment(1);

    MonteCarlo_MetropolisAlgorithm J;
    J.SetLowerLimit(0);
    J.SetUpperLimit(1);
    J.SetSamplingNumber(10000);
    J.SetFunction(f);
    J.SetWeight(w);
    //J.SetMoment(1);
    double Ians=I.Integrator();
    double Jans=J.Integrator();


    std::cout << "Result of US: " <<Ians<< std::endl;
    std::cout << "Result of MC: " <<Jans<< std::endl;

    std::cout << "True Error of US: " <<(Ians - ExactValue)*100 <<"%"<< std::endl;
    std::cout << "True Error of MC: " <<(Jans - ExactValue)*100 <<"%"<< std::endl;
    return 0;
}