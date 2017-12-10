#ifndef PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
#define PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H

#include "AbstractIntegrator.h"

/*!	\class MonteCarlo_MetropolisAlgorithm
	\brief Brief description about the class.
	Brief description continued.

	Detailed description starts here. (after one empty line)
*/

class MonteCarlo_MetropolisAlgorithm: public AbstractIntegrator {
public:
    // Constructor and destructor
    MonteCarlo_MetropolisAlgorithm(); //!< Constructor
    ~MonteCarlo_MetropolisAlgorithm(); //!< Destructor

    // Set Methods
    void SetWeight(double (*w)(double x)); //!< A method for setting the weight function by the user

    // other Methods
    double WeightValue(double x) const; //!< This method returns the value of weight function at the given input value (x)
    double* Integrator();

private:
    double (* Weight)(double x);
    //double (* NormalizedWeight)(double x);
    //double (* NonNormalizedWeight)(double x);
};


#endif //PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
