//
// Created by Arash on 12/10/2017.
//

#include "StatisticalMoments.h"
#include <iostream>
#include <cmath>
#include <fstream>

#include "../MonteCarlo_UniformSampling.h"
#include "../MonteCarlo_MetropolisAlgorithm.h"

# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

double f(double x) { return 1/sqrt(2*M_PI)*exp(-x*x/2); }
double w(double x) { return (-fabs(x)+10)/100; }

void StatMoment(){
    double ExactValue = M_PI;
    double US, MP, US_error, MP_error;

    ofstream USfile;
    ofstream MPfile;
    USfile.open ("StatMoment_file_US.txt");
    MPfile.open ("StatMoment_file_US.txt");

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
    J.SetWeight(w,1);


    for (int m=0;m<=10;m+=2){

        I.SetMoment(m);
        J.SetMoment(m);

        MP=J.Integrator()[0];
        MP_error=J.Integrator()[1];

        US=I.Integrator()[0];
        US_error=I.Integrator()[1];

        USfile<<m<<"\t"<<US<<"\t"<<US_error<<"\t"<<US-ExactValue<<"\n";
        MPfile<<m<<"\t"<<MP<<"\t"<<MP_error<<"\t"<<MP-ExactValue<<"\n";

    }

    USfile.close();
    MPfile.close();
}