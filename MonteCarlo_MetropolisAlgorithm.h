#ifndef PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
#define PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H

#include "AbstractIntegrator.h"

class MonteCarlo_MetropolisAlgorithm: public AbstractIntegrator {
public:
    // Constructor and destructor
    MonteCarlo_MetropolisAlgorithm();
    ~MonteCarlo_MetropolisAlgorithm();

    // Set Methods
    void SetWeight(double (*w)(double x));

    // other Methods
    double WeightValue(double x) const;
    double Integrator();

private:
    double (*Weight)(double x);
};


#endif //PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
