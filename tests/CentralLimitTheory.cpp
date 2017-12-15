#include <iostream>
#include <cmath>
#include <fstream>
#include "../MonteCarlo_UniformSampling.h"
using namespace std;

double f(double x) { return 4 / (1 + pow(x, 2)); }

int main(){

    int M=100000;

    MonteCarlo_UniformSampling I;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    I.SetSamplingNumber(10000);
    I.SetFunction(f);

    MonteCarlo_UniformSampling J;
    J.SetLowerLimit(0);
    J.SetUpperLimit(1);
    J.SetSamplingNumber(100);
    J.SetFunction(f);

    double mu1,sigma1,mu2,sigma2;
    double *US1,*US2;
    ofstream CL;

    CL.open ("Central_Limit.txt",std::ios::out);
    CL.precision(8);

    mu1=0;
    sigma1=0;
    mu2=0;
    sigma2=0;

    for (int n=0;n<M;n++){
        US1=I.Integrator();
        mu1 += US1[0];
        sigma1 += US1[0]*US1[0];

        US2=J.Integrator();
        mu2 += US2[0];
        sigma2 += US2[0]*US2[0];

        CL<< US1[0]<<"\t"<<US1[1]<<"\t"<<US2[0]<<"\t"<<US2[1]<<"\n";
    }

    mu1/=M;
    sigma1= sqrt(sigma1/M-mu1*mu1);
    mu2/=M;
    sigma2= sqrt(sigma2/M-mu2*mu2);

    CL<< "#1. sigma and mu are "<<sigma1<<"\t"<<mu1<<"\n";
    CL<< "#2. sigma and mu are "<<sigma2<<"\t"<<mu2<<"\n";

    CL.close();
    return 0;
}