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

    /* For calculating integrals with infinite limits, we created two methods with string inputs so that the user could use "Inf" or "-Inf" as infinite limits indicators.
     * However, we do NOT RECOMMENDED these methods. --- for more information, please refer to README.md*/
    //void SetLowerLimit(const std::string& a);   //!< A method for setting the lower limit of integral to -Inf
    //void SetUpperLimit(const std::string& b);   //!< A method for setting the upper limit of integral to +Inf

    // Get Methods
    double GetLowerLimit() const; //!< A method for getting the lower limit of integral
    /*!< This method is mainly used in some methods of derived classes, but it can also be called by the user.*/
    double GetUpperLimit() const; //!< A method for getting the upper limit of integral
    /*!< This method is mainly used in some methods of derived classes, but it can also be called by the user.*/
    int GetSamplingNumber() const; //!< A method for getting the number of sampling
    /*!< This method is mainly used in some methods of derived classes, but it can also be called by the user.*/
    int GetMoment() const; //!< A method for getting the moment
    /*!< This method is mainly used in some methods of derived classes, but it can also be called by the user.*/

    // other Methods
    double FunctionValue(double x) const; //!< This method returns the value of function at the given input value (x)
    virtual double* Integrator() = 0; //!< pure virtual method
    /*!< in the derived classes, this method is overridden for implementing numerical algorithms*/

private:
    double LowerLimit; //!< A private member, storing the lower limit of integral
    double UpperLimit; //!< A private member, storing the upper limit of integral
    int SamplingNumber; //!< A private member, storing the number of sampling in Monte-Carlo integration
    double (*Function)(double x); //!< A private member, storing the function
    int Moment = 0; /*!< the default value of Moment is 0 */
};
#endif //PCSC2017_GROUP2_ABSTRACTINTEGRATOR_H