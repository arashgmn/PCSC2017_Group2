#ifndef PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H
#define PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H

#include "AbstractIntegrator.h"

/*!	\class MonteCarlo_UniformSampling
	\brief Brief description about the class.
	Brief description continued.

	Detailed description starts here. (after one empty line)
*/

class MonteCarlo_UniformSampling: public AbstractIntegrator {
public:
    // Constructor and destructor
    MonteCarlo_UniformSampling(); //!< Constructor
    ~MonteCarlo_UniformSampling(); //!< Destructor

    // other Methods
    double* Integrator();
};


#endif //PCSC2017_GROUP2_MONTECARLO_UNIFORMSAMPLING_H
