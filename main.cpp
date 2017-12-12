#include <iostream>
#include <cmath>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"
#include "MonteCarlo_MetropolisAlgorithm.h"
#define M_PI           3.14159265358979323846  /* pi */
using namespace std;

double f(double x)
{
    return exp(-x*x);
}

double w(double x)
{
    //return cos (x);
    //return (4-2*x)/3;
    return exp(-x*x);
}

int main() {
    double ExactValue = M_PI;
/*
    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(10000);
    I.SetFunction(f);
    //I.SetMoment(1);
*/
    MonteCarlo_MetropolisAlgorithm J;
    J.SetLowerLimit(0);
    J.SetUpperLimit(1);
    J.SetSamplingNumber(10000);
    J.SetFunction(f);
    J.SetWeight(w,0);
    //J.SetMoment(1);
    double* Ians;
    double* Jans;
    //Ians = I.Integrator();
    Jans = J.Integrator();


    std::cout << "Result of US: " <<Ians[0]<< std::endl;
    std::cout << "Result of MC: " <<Jans[0]<< std::endl;

    std::cout << "Error of US: " <<Ians[1]<< std::endl;
    std::cout << "Error of MC: " <<Jans[1]<< std::endl;

    std::cout << "True Error of US: " <<(Ians[0] - ExactValue)<<std::endl;
    std::cout << "True Error of MC: " <<(Jans[0] - ExactValue)<< std::endl;
    return 0;
}
