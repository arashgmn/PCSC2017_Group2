#include <iostream>
#include <cmath>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"

double f(double x)
{
    return x;
}
using namespace std;

int main() {
    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(2);
    I.SetSamplingNumber(100000);
    I.SetFunction(f);
    cout<<pow(3,0);
    I.SetMoment(1);

    std::cout << "Result: " <<I.Integrator()<< std::endl;
    //here the result is not always corrects
    return 0;
}