#ifndef PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H
#define PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H

/*!	\class AbstractIntegrator
	\brief An abstract class for setting the general inputs of an integral

	This class doesn't include any numerical method for calculating the integral,
    rather, it has some methods used for setting the general inputs of an integral by the user
    and contains some members storing these inputs, which are used by numerical methods in the derived classes.
*/

class AbstractIntegrator {
public:
    // Constructor and destructor
    AbstractIntegrator(); //!< Constructor
    virtual ~AbstractIntegrator(); //!< Destructor

    // Set Methods
    void SetLowerLimit(const double a); //!< A method for setting the lower limit of integral by the user
    void SetUpperLimit(const double b); //!< A method for setting the upper limit of integral by the user
    void SetSamplingNumber(const int N); //!< A method for setting the number of sampling in Monte-Carlo integration by the user
    void SetFunction(double (*f)(double x)); //!< A method for setting the function by the user
    void SetMoment(const int m); //!< A method for setting the function by the user
    /*!< as the default value of Moment is 0, user may not call it */

    // Get Methods
    double GetLowerLimit() const;
    double GetUpperLimit() const;
    int GetSamplingNumber() const;
    int GetMoment() const;

    // other Methods
    double FunctionValue(double x) const; //!< This method returns the value of function at the given input value (x)
    virtual double* Integrator() = 0; //!< pure virtual method
    /*!< in the derived classes, this method is overridden for implementing numerical algorithms*/

private:
    double LowerLimit; //!< A private member, storing the lower limit of integral
    double UpperLimit; //!< A private member, storing the upper limit of integral
    int SamplingNumber; //!< A private member, storing the number of sampling in Monte-Carlo integration
    double (*Function)(double x);
    int Moment = 0; /*!< the default value of Moment is 0 */
};


#endif //PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H