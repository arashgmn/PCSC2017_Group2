#include <iostream>
#include <cmath>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"
#include "MonteCarlo_MetropolisAlgorithm.h"


double f(double x)
{
    return tan(x);
}
using namespace std;

int main() {

    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(10000);
    I.SetFunction(f);
    //I.SetMoment(1);



    MonteCarlo_MetropolisAlgorithm J;
    J.SetLowerLimit(-0);
    J.SetUpperLimit(1);
    J.SetSamplingNumber(10000);
    J.SetFunction(f);
    //J.SetMoment(1);
    double Jans=J.Integrator();
    double Ians=I.Integrator();
    std::cout << "Result of SS: " <<Ians<< std::endl;
    std::cout << "Result o MC: " <<Jans<< std::endl;
    std::cout << "J-I: " <<Jans-Ians<< std::endl;
    return 0;
}
