#ifndef PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
#define PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H


#include "AbstractIntegrator.h"

class MonteCarlo_MetropolisAlgorithm : public AbstractIntegrator{
    // Constructor and destructor
    MonteCarlo_MetropolisAlgorithm();
    ~MonteCarlo_MetropolisAlgorithm();
    // other Methods
    double Integrator();
};


#endif //PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
