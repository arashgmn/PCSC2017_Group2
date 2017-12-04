#ifndef PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H
#define PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H

#include "AbstractIntegrator.h"

class MonteCarlo_UniformSampling: public AbstractIntegrator {
public:
    // Constructor and destructor
    MonteCarlo_UniformSampling();
    ~MonteCarlo_UniformSampling();
    // other Methods
    double Integrator();
};


#endif //PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H
