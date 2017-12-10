#ifndef PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H
#define PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H

#include "AbstractIntegrator.h"

/*!	\class MonteCarlo_UniformSampling
	\brief This class integrates a function using uniform sampling.

	In this method there is no need for weight function. Integral and the error would be evaluated directly.
    The output is an array "ans" such that ans[0] is the integral answer and ans[1] is the estimated error.
*/

class MonteCarlo_UniformSampling: public AbstractIntegrator {
public:
    // Constructor and destructor
    MonteCarlo_UniformSampling(); //!< Constructor
    ~MonteCarlo_UniformSampling(); //!< Destructor

    // other Methods
    double* Integrator(); //!< Integrating using Uniform Sampling method
};


#endif //PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H
