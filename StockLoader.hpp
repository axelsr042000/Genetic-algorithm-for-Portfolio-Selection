#ifndef STOCKLOADER
#define STOCKLOADER
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Stock.hpp"
using namespace std;

class StockLoader
{
private:
    /// @brief create one stock from one CSV file
    /// @param filename
    /// @param symbol
    /// @return
    static Stock *loadStock(const string &filename, const string &symbol);

public:
    StockLoader();

    /// @brief create a list of stocks stock from multiple CSV file
    /// @param stocks
    /// @param size
    /// @return
    static Stock **loadStocks(const string *stocks, int size);
};
#endif
