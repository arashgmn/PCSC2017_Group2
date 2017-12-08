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

// Set Methods

void MonteCarlo_MetropolisAlgorithm::SetWeight(double (*w)(double x)) {
    Weight = w;
}

// other Methods

double MonteCarlo_MetropolisAlgorithm::WeightValue(double x) const {
    return Weight(x);
}

// Integrator

double MonteCarlo_MetropolisAlgorithm::Integrator() {

    //random
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    //Getting integral arguments
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    //parameters of integration
    int r = 0;                          // number of rejection
    double sum = 0;                     //sum of samples
    double sum2 = 0;                    //sum^2 of samples
    double p_old, p_new, x_old, x_new;  //Marcov chain parameters
    double delta = (b - a) * 0.5;       //move in x

    //correlation length in Marcov chain
    int l = 10;                         // for every "l" points we sample once
    N = N * l;                          //Updated N

    //Start point
    x_new = a + (b - a) * distribution(generator);                          //a random variable in domain
    p_new = (FunctionValue(x_new) / WeightValue(x_new)) * pow(x_new, m);    //prob. of going to new x


    for (int i = 0; i < N; ++i) {

        x_old = x_new;
        p_old = p_new;

        x_new = x_old + 2 * (delta) * (distribution(generator) - 0.5);          //moving x
        if (x_new > b) { x_new = b - (x_new - b); }                             //right border correction
        if (x_new < a) { x_new = a + (a - x_new); }                             //left border correction
        p_new = (FunctionValue(x_new) / WeightValue(x_new)) * pow(x_new, m);    //prob. of going to new x

        //checking Metropolis condition
        if (distribution(generator) > WeightValue(x_new) / WeightValue(x_old)) {     //rejection happens
            x_new = x_old;
            p_new = p_old;
            r++;
        }

        //sampling
        if (i % l == 0) {
            sum = sum + p_new;
            sum2 += p_new*p_new;
        }
    }

    //Computing error
    sum = sum / (N/l) ;
    sum2 = sum2 / (N/l) ;
    double err = sqrt( (sum2-sum*sum) / (N/l) ) * (b-a);
    SetError(err);

    cout << "rejection: " << (double) r / N * 100 << " %" << endl;
    cout<<"error of MC is "<<GetError()*100<<"%"<<endl;
    return sum * (b - a);
}
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

        /*
        if (i%100==0){
            if ((double) r/N*100)<0.3){
                delta*=2;
            }
            else()
        }
         */