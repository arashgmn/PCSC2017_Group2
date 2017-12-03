#include "AbstractIntegrator.h"

// Constructor and destructor


// Set Methods

void AbstractIntegrator::SetLowerLimit(const double a) {
    LowerLimit = a;
}

void AbstractIntegrator::SetUpperLimit(const double b) {
    UpperLimit = b;
}

void AbstractIntegrator::SetSamplingNumber(const int N) {
    SamplingNumber = N;
}

void AbstractIntegrator::SetFunction(double (*f)(double x)) {
    Function = f;
}

// Get Methods

double AbstractIntegrator::GetLowerLimit() {
    return LowerLimit;
}

double AbstractIntegrator::GetUpperLimit() {
    return UpperLimit;
}

int AbstractIntegrator::GetSamplingNumber() {
    return SamplingNumber;
}

// other Methods

double AbstractIntegrator::FunctionValue(double x) {
    return Function(x);
}