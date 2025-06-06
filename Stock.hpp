#ifndef STOCK
#define STOCK

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include "DataUtils.hpp"

using namespace std;

/// @brief Class that encapsulate all information regarding a stock
class Stock : public DataUtils
{
private:
    string symbol;
    vector<string> dates;
    vector<double> closes;

public:
    /// @brief constructor
    /// @param symbol
    Stock(const string &symbol) : DataUtils(), symbol(symbol) {}

    /// @brief add data to the class
    /// @param date one date
    /// @param close one close value
    void addData(const string &date, double close);

    /// @brief compute returns based on close values
    void computeReturns();

    /// @brief getter for Symbol
    /// @return
    string getSymbol();
    
    const vector<double> &getCloses() const
    {
        return closes;
    }
};
#endif