#include <iostream>
#include <cmath>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"


double f(double x)
{
    return exp(x);
}
using namespace std;

int main() {
    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(3);
    I.SetSamplingNumber(1000000);
    I.SetFunction(f);
    //I.SetMoment(2);

    std::cout << "Result: " <<I.Integrator()<< std::endl;
    return 0;
}
