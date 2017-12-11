//
// Created by Arash on 12/10/2017.
//

#include <iostream>
#include <cmath>
#include <fstream>

#include "../MonteCarlo_UniformSampling.h"
#include "../MonteCarlo_MetropolisAlgorithm.h"

# define M_PI  3.14159265358979323846  /* pi */
using namespace std;

double f(double x) { return 4/(1+pow(x,2)); }
double w(double x) { return (4-2*x)/3; }

int main(){
    double ExactValue = M_PI;
    double *MP,*US;
    ofstream USfile;
    ofstream MPfile;
    USfile.open ("Error_file_US.txt",std::ios::app);
    MPfile.open ("Error_file_MP.txt",std::ios::app);

    USfile<<"#N    Integral    Error   True Error\n";
    MPfile<<"#N    Integral    Error   True Error\n";


    MonteCarlo_UniformSampling I;
    MonteCarlo_MetropolisAlgorithm J;
    I.SetLowerLimit(0);
    I.SetUpperLimit(1);
    J.SetLowerLimit(0);
    J.SetUpperLimit(1);


    for (int n=10;n<10000;n*=2){
        I.SetSamplingNumber(n);
        I.SetFunction(f);
        J.SetSamplingNumber(n);
        J.SetFunction(f);
        J.SetWeight(w,1);

        MP =J.Integrator();
        US=I.Integrator();

        USfile<<n<<"\t"<<US[0]<<"\t"<<US[1]<<"\t"<<US[0]-ExactValue<<"\n";
        MPfile<<n<<"\t"<<MP[0]<<"\t"<<MP[1]<<"\t"<<MP[0]-ExactValue<<"\n";

    }

    USfile.close();
    MPfile.close();
}