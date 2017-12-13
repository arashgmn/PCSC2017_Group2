#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "../MonteCarlo_UniformSampling.h"
#include "../MonteCarlo_MetropolisAlgorithm.h"
using namespace std;

double Pi (double x) { return 4/(1+pow(x,2)); }
double Gaussian (double x) { return exp(-x*x/2)/sqrt(2*M_PI); }
double Gamma4 (double x) { return pow(x,-1)*exp(-x); }

double w_Pi (double x) { return (4-2*x)/3;} // a normalized weight in [0,1]
double w_Gaussian (double x) { return exp(-1*x);} // a normalized weight in [0,Inf)

int main() {
    MonteCarlo_UniformSampling I_Pi;
    MonteCarlo_UniformSampling I_Gaussian;
    MonteCarlo_UniformSampling I_Gamma4;

    MonteCarlo_MetropolisAlgorithm J_Pi;
    MonteCarlo_MetropolisAlgorithm J_Gaussian;

    //Pi setting
    I_Pi.SetLowerLimit(0);
    J_Pi.SetLowerLimit(0);
    I_Pi.SetUpperLimit(1);
    J_Pi.SetUpperLimit(1);
    I_Pi.SetSamplingNumber(10000);
    J_Pi.SetSamplingNumber(10000);
    I_Pi.SetFunction(Pi);
    J_Pi.SetFunction(Pi);
    J_Pi.SetWeight(w_Pi,true);

    //Gaussian setting
    I_Gaussian.SetLowerLimit(0);
    J_Gaussian.SetLowerLimit(0);
    I_Gaussian.SetUpperLimit("Inf");           //IT'S NOT INF
    J_Gaussian.SetUpperLimit("Inf");           //IT'S NOT INF
    I_Gaussian.SetSamplingNumber(10000);  //IT'S LARGE
    J_Gaussian.SetSamplingNumber(10000);  //IT'S LARGE
    I_Gaussian.SetFunction(Gaussian);
    J_Gaussian.SetFunction(Gaussian);
    J_Gaussian.SetWeight(w_Gaussian, false);

    //Gamma setting
    I_Gamma4.SetLowerLimit(0);
    I_Gamma4.SetUpperLimit(1);
    I_Gamma4.SetSamplingNumber(10000);
    I_Gamma4.SetFunction(Gamma4);
    I_Gamma4.SetMoment(4);

    double *I_Pi_ans, *J_Pi_ans;
    double *I_Gaussian_ans, *J_Gaussian_ans;
    double *I_Gamma4_ans;

    I_Pi_ans = I_Pi.Integrator();
    J_Pi_ans = J_Pi.Integrator();
    I_Gaussian_ans = I_Gaussian.Integrator();
    J_Gaussian_ans = J_Gaussian.Integrator();
    I_Gamma4_ans = I_Gamma4.Integrator();

    double ExactValue_Pi = M_PI;
    double ExactValue_Gaussian = 0.5;
    double ExactValue_Gamma4 = 6;

    std::cout << "************* Integral of Pi on [0,1] ******************"<<std::endl;
    std::cout << setw(22) << "Uniform Sampling: "<<I_Pi_ans[0]<<"\t True Error: "<<I_Pi_ans[0]-ExactValue_Pi<<std::endl;
    std::cout << setw(22) << "Metropolis Algorithm: "<<J_Pi_ans[0]<<"\t True Error: "<<J_Pi_ans[0]-ExactValue_Pi<<std::endl;
    std::cout << "\n";
    std::cout << "************* Integral of Gaussian on [0,Inf) **********"<<std::endl;
    std::cout << setw(22) << "Uniform Sampling: "<<I_Gaussian_ans[0]<<"\t True Error: "<<I_Gaussian_ans[0]-ExactValue_Gaussian<<std::endl;
    std::cout << setw(22) << "Metropolis Algorithm: "<<J_Gaussian_ans[0]<<"\t True Error: "<<J_Gaussian_ans[0]-ExactValue_Gaussian<<std::endl;
    std::cout << "\n";
    std::cout << "************* Integral of Gamma4 on [0,Inf) ************"<<std::endl;
    std::cout << setw(22) << "Uniform Sampling: "<<I_Gamma4_ans[0]<<"\t True Error: "<<I_Gamma4_ans[0]-ExactValue_Gamma4<<std::endl;
    std::cout << "\n";
    return 0;
}


