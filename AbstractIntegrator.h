#ifndef PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H
#define PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H


/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */

class AbstractIntegrator {
public:
    // Constructor and destructor
    AbstractIntegrator();
    virtual ~AbstractIntegrator();

    // Set Methods
    void SetLowerLimit(const double a);
    void SetUpperLimit(const double b);
    void SetSamplingNumber(const int N);
    void SetFunction(double (*f)(double x));
    void SetMoment(const int m);
    void SetError (double err);

    // Get Methods
    double GetLowerLimit() const;
    double GetUpperLimit() const;
    int GetSamplingNumber() const;
    int GetMoment() const;
    double GetError() const;

    // other Methods
    double FunctionValue(double x) const;
    virtual double Integrator() = 0;

private:
    double LowerLimit;
    double UpperLimit;
    double SamplingNumber;
    double (*Function)(double x);
    double error;
    int Moment=0;
};


#endif //PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H
