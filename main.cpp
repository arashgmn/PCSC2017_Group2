#include <iostream>
#include <cmath>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"
#include "MonteCarlo_MetropolisAlgorithm.h"


double f(double x)
{
    return x;
}
using namespace std;

int main() {
    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(1000000);
    I.SetFunction(f);
    //I.SetMoment(1);
    std::cout << "Result of SS: " <<I.Integrator()<< std::endl;

    MonteCarlo_MetropolisAlgorithm J;
    J.SetLowerLimit(0);
    J.SetUpperLimit(1);
    J.SetSamplingNumber(1000000000);
    J.SetFunction(f);
    //J.SetMoment(1);
    std::cout << "Result o MC: " <<J.Integrator()<< std::endl;

    return 0;
}
