#include "StockLoader.hpp"

Stock *StockLoader::loadStock(const std::string &filename, const std::string &symbol)
{
    Stock *stock = new Stock(symbol);

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return stock; // Return an empty stock object
    }

    // Read the header line to get column names
    string header;
    getline(file, header);

    // Read data lines and add "Close" values to the stock object
    string line;
    while (getline(file, line))
    {
        istringstream lineStream(line);
        string ignoreColumn1, ignoreColumn2, ignoreColumn3, ignoreColumnAfterClose1;

        double close;
        string date;

        if (getline(lineStream, ignoreColumn1, ',') &&
            getline(lineStream, ignoreColumn2, ',') &&
            getline(lineStream, ignoreColumn3, ',') &&
            getline(lineStream, date, ',') &&
            lineStream >> close >> ignoreColumnAfterClose1)
        {
            // Code for handling extracted date and close values goes here
            stock->addData(date, close);
        }
    }

    file.close();
    stock->computeReturns();
    return stock;
}

Stock **StockLoader::loadStocks(const string *stocks, int size)
{
    Stock **stocks_data = new Stock *[size];
    for (int i = 0; i < size; i++)
    {
        stocks_data[i] = loadStock(stocks[i] + ".csv", stocks[i]);
        // cout << stocks_data[i]->getSymbol() << endl;
    }
    return stocks_data;
}
