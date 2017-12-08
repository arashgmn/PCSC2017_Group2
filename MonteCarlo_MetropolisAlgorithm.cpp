#include "MonteCarlo_MetropolisAlgorithm.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <chrono>


using namespace std;

// Constructor and destructor

MonteCarlo_MetropolisAlgorithm::MonteCarlo_MetropolisAlgorithm(){};
MonteCarlo_MetropolisAlgorithm::~MonteCarlo_MetropolisAlgorithm(){};

// Integrator

double MonteCarlo_MetropolisAlgorithm::Integrator() {
    //srand(time(NULL));
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    int r=0;
    double sum = 0;
    double p_old, p_new,x_old,x_new;
    double delta = (b-a)*.5;

    int l=10;
    N= N*l;

    x_new = a+(b-a)*distribution(generator);//((double)rand()/RAND_MAX);
    cout<<x_new;
    p_new = FunctionValue(x_new)*pow(x_new,m)/(x_new+1)*1.5;

/*
    int N_c=N/100;
    double *x = new double[N_c];
    for (int i = 0; i <= N_c; ++i) {

        x_old = x_new;
        p_old = p_new;

        x_new = x_old + 2 * (delta) * (distribution(generator) - 0.5);
        if (x_new > b) { x_new = b - (x_new - b); }
        if (x_new < a) { x_new = a + (a - x_new); }
        p_new = FunctionValue(x_new) * pow(x_new, m);
        if (distribution(generator) > fabs(p_new / p_old)) {     //rejection happens
            //حواستمون باشه که p_old ممکنه صفر بشه. باید یه cerr بذاریم
            x_new = x_old;
            p_new = p_old;
        }
        x[i]=x_new;
    }

    double ratio=1;
    for (int j = 0; j <= N_c/10; ++j){
        double x_bar=0;
        double x2_bar=0;
        double xx=0;
        for (int i = 0; i <= N_c/10; ++i) {
            x_bar += x[i];
            x2_bar += x[i] * x[i];
        }
    }

    for (int l=0; l<N_c/10;l++){
        for (int j = 0; j <= N_c/10; ++j){
            double x_bar=0;
            double x2_bar=0;
            double xx=0;
            for (int i = 0; i <= N_c/10; ++i) {
                x_bar += x[i];
                x2_bar += x[i]*x[i];
                xx += x[i];
            }

        }
    }




*/


    for (int i = 0; i < N; ++i){

        x_old = x_new;
        p_old = p_new;

        x_new = x_old + 2*(delta)*(distribution(generator) - 0.5);
        if (x_new>b){ x_new = b -(x_new-b);}
        if (x_new<a){ x_new = a +(a-x_new);}
        p_new = FunctionValue(x_new)*pow(x_new,m)/(x_new+1)*1.5;

        if (distribution(generator) > fabs((1+x_new)/(1+x_old))) {     //rejection happens
            //حواستمون باشه که p_old ممکنه صفر بشه. باید یه cerr بذاریم
            x_new = x_old;
            p_new = p_old;
            r++;
        }

        if (i%l==0){
            sum = sum +p_new;
        }
        /*
        if (i%100==0){
            if ((double) r/N*100)<0.3){
                delta*=2;
            }
            else()
        }
         */
    }

    cout<<"\n"<<(double) r/N*100<<endl;
    return sum/N*(b-a)*l;
}