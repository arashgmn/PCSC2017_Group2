#ifndef PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
#define PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H

#include "AbstractIntegrator.h"

/*!	\class MonteCarlo_MetropolisAlgorithm
	\brief This class integrates a function using Metropolis sampling
	Brief description continued.

	In this method user must provide a strictly positive weight function on domain of integration. If the weight
    function is normalized, this method will perform integration and evaluates the error. If it is not the case, weight
    function will be normalized by integrating weight function on domain using Uniform Sampling class. The evaluation of
    error will consider the probable error in normalizing the weight function.
    The output is an array "ans" such that ans[0] is the integral answer and ans[1] is the estimated error.


*/

class MonteCarlo_MetropolisAlgorithm: public AbstractIntegrator {
public:
    // Constructor and destructor
    MonteCarlo_MetropolisAlgorithm(); //!< Constructor
    ~MonteCarlo_MetropolisAlgorithm(); //!< Destructor

    // Set Methods
    void SetWeight(double (*w)(double x), bool flag ); //!< A method for setting the weight function by the user, flag=1 if the function is normalized.

    // other Methods
    double WeightValue(double x) const; //!< This method returns the value of weight function at the given input value (x)
    double* Integrator();

private:
    double (* Weight)(double x);
    bool Flag=0;  //to indicate if weight is normal (1) or not (0)
};


#endif //PCSC2017_GROUP2_MONTECARLO_METROPOLISALGORITHM_H
