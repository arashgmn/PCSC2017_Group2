#ifndef PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H
#define PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H


class AbstractIntegrator {
public:
    // Constructor and destructor
    //AbstractIntegrator();
    //virtual ~AbstractIntegrator();  //chera virtual?

    // Set Methods
    void SetLowerLimit(const double a);
    void SetUpperLimit(const double b);
    void SetSamplingNumber(const int N);
    void SetFunction(double (*f)(double x));


    // Get Methods
    double GetLowerLimit();
    double GetUpperLimit();
    int GetSamplingNumber();

    // other Methods
    double FunctionValue(double x);
    virtual double Integrator() = 0;

private:
    double LowerLimit;
    double UpperLimit;
    double SamplingNumber;
    double (*Function)(double x);
};


#endif //PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H
