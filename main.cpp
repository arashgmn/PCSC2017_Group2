#include <iostream>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"

double f(double x)
{
    return x*x;
}

int main() {
    //AbstractIntegrator* I;
    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(10000);
    I.SetFunction(f);

    std::cout << "Result: " <<I.Integrator()<< std::endl;
    return 0;
}