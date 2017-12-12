#include <limits>
#include "AbstractIntegrator.h"


// Constructor and destructor
AbstractIntegrator::AbstractIntegrator(){}
AbstractIntegrator::~AbstractIntegrator(){};


// Set Methods
void AbstractIntegrator::SetLowerLimit(const double a) {
    LowerLimit = a;
}

void AbstractIntegrator::SetLowerLimit(const std::string& a){
    if (a!="-Inf"){
        std::cout<<"Bad input!"<<std::endl;
        //c error
    }
    else{
        LowerLimit = std::numeric_limits<int>::min();
    }
}

void AbstractIntegrator::SetUpperLimit(const double b) {
    UpperLimit = b;
}

void AbstractIntegrator::SetUpperLimit(const std::string& b){
    if (b!="Inf"){
        std::cout<<"Bad input!"<<std::endl;
        //c error
    }
    else{
        LowerLimit = std::numeric_limits<int>::max();
    }
}

void AbstractIntegrator::SetSamplingNumber(const int N) {
    SamplingNumber = N;
}

void AbstractIntegrator::SetFunction(double (*f)(double x)) {
    Function = f;
}

void AbstractIntegrator::SetMoment(const int m) {
    Moment = m;
}



// Get Methods
double AbstractIntegrator::GetLowerLimit() const{
    return LowerLimit;
}

double AbstractIntegrator::GetUpperLimit() const{
    return UpperLimit;
}

int AbstractIntegrator::GetSamplingNumber() const{
    return SamplingNumber;
}

int AbstractIntegrator::GetMoment() const{
    return Moment;
}



// other Methods
double AbstractIntegrator::FunctionValue(double x) const{
    return Function(x);
}