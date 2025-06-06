#ifndef PORTFOLIO
#define PORTFOLIO
#include "Stock.hpp"
#include "DataUtils.hpp"
#include <random>
#include <vector>
class Portfolio : public DataUtils
{
private:
    int number_assets;
    double sharp_ratio;

    double *weights;
    Stock **stocks_data;
    vector<vector<double>> covarianceMatrix;

    /// @brief compute returns based on stock data
    void computeCovarianceMatrix();

    /// @brief compute sharp ratio
    /// @param riskFreeRate
    void computeSharpeRatio(double riskFreeRate);

    void computeReturns();

public:
    /// @brief create an instance, generate random weights
    /// @param stocks list of stocks pointers
    /// @param number_assets
    Portfolio(Stock **stocks, int number_assets);

    /// @brief create an instance
    /// @param stocks list of stocks pointers
    /// @param weights list of stocks weights
    /// @param number_assets
    Portfolio(Stock **stocks, double *weights, int number_assets);

    /// @brief generate random weights
    void generateWeights();

    /// @brief destructor
    ~Portfolio();

    /// @brief get string to print portfolio content
    /// @return
    string displayPortfolio();

    /// @brief getter for sharp ratio
    /// @return
    double getSharpRatio();

    /// @brief getter for weights list
    /// @return
    double *getWeights();

    /// @brief randomly change a weight while respecting constraints
    void mutate();

    /// @brief Definition of a comparator operator; specifically used to establish a preference order for sorting a list. The Sharp ratio (fitness operator) is the criterion used.
    /// @param other
    /// @return boolean
    bool operator<(const Portfolio &other) const;
};
#endif