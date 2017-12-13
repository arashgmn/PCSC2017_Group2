#include "MonteCarlo_MetropolisAlgorithm.h"
#include "MonteCarlo_UniformSampling.h"
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
void MonteCarlo_MetropolisAlgorithm::SetWeight(double (*w)(double x),bool flag=0) {
    Weight = w;
    Flag = flag;
}


// other Methods
double MonteCarlo_MetropolisAlgorithm::WeightValue(double x) const {
    return Weight(x);
}


// Integrator
double* MonteCarlo_MetropolisAlgorithm::Integrator() {

    // for generating random numbers
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    //rng(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // getting integral arguments
    double a = GetLowerLimit();
    double b = GetUpperLimit();
    int N = GetSamplingNumber();
    int m = GetMoment();

    // parameters of integration
    int r = 0;                          // number of rejection
    double sum = 0;                     // sum of samples
    double sum2 = 0;                    // sum of squares
    double p_old, p_new, x_old, x_new;  // Markov chain parameters
    double delta =0.1;// (b - a) * 0.5;       // move in x
    double Integral_W, Err_W, *ans_W;                 //Integral of weight function on domain (Flag==0)


    // correlation length in Markov chain
    int l = 10;                         // for every "l" points we sample once
    N = N * l;                          // update N

    //Computing integral of W via UniformSampling
    if (Flag==0){
        MonteCarlo_UniformSampling W;
        W.SetLowerLimit(a);
        W.SetUpperLimit(b);
        W.SetSamplingNumber(10*N);          //Note that it is not the original N, but it's 10*l*N. (10 is arbitrary chosen.)
        W.SetFunction(Weight);
        W.SetMoment(0);                     //We compute zero-th moment of weight function
        ans_W=W.Integrator();
        Integral_W = ans_W[0];     //Integral of W
        Err_W = ans_W[1];          //Error in normalizing
        cout<< "Integral_W  "<<Integral_W<<"    Err_W "<<Err_W<<"\n";
    }


    // start point
    x_new=a+0.1;
    //x_new = a + (b - a) * distribution(generator);                          // a random variable in domain
    p_new = (FunctionValue(x_new) / WeightValue(x_new)) * pow(x_new, m);    // prob. of going to new x

    for (int i = 0; i < N; ++i) {

        x_old = x_new;
        p_old = p_new;

        x_new = x_old + 2 * (delta) * (distribution(generator) - 0.5);          // moving x
        if (x_new > b) { x_new = b - (x_new - b); }                             // right border correction
        if (x_new < a) { x_new = a + (a - x_new); }                             // left border correction
        p_new = (FunctionValue(x_new) / WeightValue(x_new)) * pow(x_new, m);    // prob. of going to new x

        //checking Metropolis condition
        if (distribution(generator) > WeightValue(x_new) / WeightValue(x_old)) {     // rejection happens
            x_new = x_old;
            p_new = p_old;
            r++;
        }
        //cout<<x_new<<"\t"<<p_new<<endl;

        // sampling
        if (i % l == 0) {
        //    cout<<x_new<<"\t"<<p_new<<endl;
          //  system("pause");
            sum = sum + p_new;
            sum2 += p_new*p_new;
        }
    }

    // evaluating error
    sum = sum / (N/l) ;
    sum2 = sum2 / (N/l) ;
    double err = sqrt( (sum2-sum*sum) / (N/l) ) ;   //err= std_var / sqrt(N)


    cout<<"error without compensating "<< err * (b-a) <<"\n";   //Should be removed...

    //relative errors will add up
    if (Flag==0){
        err =  (err/sum + Err_W/Integral_W)  * sum;
        sum *= Integral_W;
    }

    cout << "rejection: " << (double) r / N * 100 << " %" << endl;      //likely to be removed

    // returning the value of integral and its error
    double *ans = new double[2];
    ans[0] = sum ;
    ans[1] = err ;
    return ans;
}