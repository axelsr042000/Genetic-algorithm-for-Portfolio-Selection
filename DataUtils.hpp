#ifndef DATAUTILS
#define DATAUTILS
#include <vector>
using namespace std;

class DataUtils
{
protected:
    vector<double> returns;
    double std;
    double mean;

    /// @brief Compute the standard deviation of the returns
    void computeSTD();

    /// @brief Compute the standard mean of the returns
    void computeMean();

public:
    /// @brief create an instance using a vector of returns, then compute the mean and the std
    /// @param d
    DataUtils(vector<double> d);

    /// @brief destructor
    ~DataUtils();
    /// @brief Default constructor
    DataUtils();

    /// @brief Compute the covariance matrix of two DataUtils objects
    /// @param DataUtils
    double computeCovariance(DataUtils *otherdata);

    /// @brief getter for retruns
    /// @return returns
    vector<double> getReturns();

    /// @brief getter for Std
    /// @return std
    double getSTD();

    /// @brief getter for mean
    /// @return mean
    double getMean();
};

#endif
