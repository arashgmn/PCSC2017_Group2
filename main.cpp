#include <iostream>
#include <cmath>
#include <iomanip>
#include "AbstractIntegrator.h"
#include "MonteCarlo_UniformSampling.h"
#include "MonteCarlo_MetropolisAlgorithm.h"
using namespace std;

double f(double x)
{
    return 4/(1+pow(x,2));
}

double w(double x)
{
    return (4-2*x)/3;;
}

int main() {

    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(80000);
    I.SetFunction(f);
    //I.SetMoment(1);

    MonteCarlo_MetropolisAlgorithm J;
    J.SetLowerLimit(0);
    J.SetUpperLimit(1);
    J.SetSamplingNumber(80000);
    J.SetFunction(f);
    J.SetWeight(w,true);
    //J.SetMoment(1);

    double* Ians;
    double* Jans;
    Ians = I.Integrator();
    Jans = J.Integrator();

    std::cout << "**************** Integral of f(x) on ["<<I.GetLowerLimit()<<","<<I.GetUpperLimit()<<"] ******************"<<std::endl;
    std::cout << setw(22) << "Uniform Sampling: "<<Ians[0]<<"\t Estimated Error: "<<Ians[1]<<std::endl;
    std::cout << "**************** Integral of f(x) on ["<<J.GetLowerLimit()<<","<<J.GetUpperLimit()<<"] ******************"<<std::endl;
    std::cout << setw(22) << "Metropolis Algorithm: "<<Jans[0]<<"\t Estimated Error: "<<Jans[1]<<std::endl;
    return 0;
}