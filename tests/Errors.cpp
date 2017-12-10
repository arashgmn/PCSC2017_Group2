//
// Created by Arash on 12/10/2017.
//

#include "Errors.h"
#include <iostream>
#include <cmath>
#include <fstream>

#include "../MonteCarlo_UniformSampling.h"
#include "../MonteCarlo_MetropolisAlgorithm.h"

# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

double f(double x) { return 4/(1+pow(x,2)); }
double w(double x) { return (4-2*x)/3; }

void Errors(){
    double ExactValue = M_PI;
    double US, MP, US_error, MP_error;

    ofstream USfile;
    ofstream MPfile;
    USfile.open ("Error_file_US.txt");
    MPfile.open ("Error_file_US.txt");

    USfile<< "N    Integral    Error   True Error\n";
    MPfile<< "N    Integral    Error   True Error\n";


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

        MP=J.Integrator()[0];
        MP_error=J.Integrator()[1];

        US=I.Integrator()[0];
        US_error=I.Integrator()[1];

        USfile<<n<<"\t"<<US<<"\t"<<US_error<<"\t"<<US-ExactValue<<"\n";
        MPfile<<n<<"\t"<<MP<<"\t"<<MP_error<<"\t"<<MP-ExactValue<<"\n";

    }

    USfile.close();
    MPfile.close();
}