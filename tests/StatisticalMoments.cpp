#include <iostream>
#include <cmath>
#include <fstream>
#include "../MonteCarlo_UniformSampling.h"
#include "../MonteCarlo_MetropolisAlgorithm.h"
using namespace std;

double f(double x) { return 1/sqrt(2*M_PI)*exp(-x*x/2); }
double w(double x) { return (-fabs(x)+10)/100; }

int main(){
    double ExactValue = M_PI;
    double *US, *MP;

    ofstream USfile;
    ofstream MPfile;
    USfile.open ("StatMoment_file_US.txt",std::ios::app);
    MPfile.open ("StatMoment_file_US.txt",std::ios::app);

    USfile<< "m    Integral    Error\n";
    MPfile<< "m    Integral    Error\n";

    MonteCarlo_UniformSampling I;
    MonteCarlo_MetropolisAlgorithm J;
    I.SetLowerLimit(-10);
    I.SetUpperLimit(10);
    I.SetSamplingNumber(10000);
    I.SetFunction(f);

    J.SetLowerLimit(-10);
    J.SetUpperLimit(10);
    J.SetSamplingNumber(10000);
    J.SetFunction(f);
    J.SetWeight(w,true);

    for (int m=0;m<=10;m+=2){

        I.SetMoment(m);
        J.SetMoment(m);

        MP =J.Integrator();
        US=I.Integrator();

        USfile<<m<<"\t"<<US[0]<<"\t"<<US[1]<<"\t"<<US[0]-ExactValue<<"\n";
        MPfile<<m<<"\t"<<MP[0]<<"\t"<<MP[1]<<"\t"<<MP[0]-ExactValue<<"\n";
    }

    USfile.close();
    MPfile.close();
    return 0;
}