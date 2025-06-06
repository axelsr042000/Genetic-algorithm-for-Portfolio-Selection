#include "Portfolio.hpp"

Portfolio::Portfolio(Stock **stocks, int number_assets)
{
    this->number_assets = number_assets;
    this->weights = new double[number_assets];
    generateWeights();
    this->stocks_data = stocks;

    computeReturns();
    computeCovarianceMatrix();
    computeMean();
    computeSTD();
    computeSharpeRatio(0);
}

Portfolio::Portfolio(Stock **stocks, double *weights, int number_assets)
{
    this->number_assets = number_assets;
    this->weights = weights;
    this->stocks_data = stocks;

    computeReturns();
    computeCovarianceMatrix();
    computeMean();
    computeSTD();
    computeSharpeRatio(0);
}

void Portfolio::generateWeights()
{
    int max_bound = 100;
    int randomInteger;
    for (int i = 0; i < this->number_assets - 1; ++i)
    {
        randomInteger = rand() % max_bound; // draw random int

        max_bound -= randomInteger;                                      // update boundary
        double randomValue = static_cast<double>(randomInteger) / 100.0; // transform int to double
        // cout << randomValue << endl;
        this->weights[i] = randomValue; // assign weight
    }
    // cout << (double)max_bound / 100 << endl;
    this->weights[number_assets - 1] = (double)max_bound / 100; // set last weight
}

void Portfolio::computeReturns()
{
    int size = stocks_data[0]->getReturns().size();
    for (int i = 0; i < size; i++)
    { // row
        double cell = 0;
        for (int j = 0; j < number_assets; j++)
        {
            cell += this->weights[j] * stocks_data[j]->getReturns()[i]; // column
        }
        // cout<<cell<<endl;
        returns.push_back(cell);
    }
}

void Portfolio::computeCovarianceMatrix()
{
    covarianceMatrix.resize(this->number_assets, vector<double>(this->number_assets, 0.0));
    for (int i = 0; i < this->number_assets; ++i)
    {
        for (int j = 0; j < this->number_assets; ++j)
        {
            covarianceMatrix[i][j] = stocks_data[i]->computeCovariance(stocks_data[j]);
            // cout << covarianceMatrix[i][j] << " ";
        }
        // cout << endl;
    }
}

void Portfolio::computeSharpeRatio(double riskFreeRate = 0)
{
    if (returns.empty())
    {
        this->sharp_ratio = 0.0; // No returns available
    }
    double meanReturn = this->mean;

    double stdDev = this->std;

    // Calculate Sharpe Ratio
    this->sharp_ratio = (meanReturn - riskFreeRate) / stdDev;
}

double Portfolio::getSharpRatio()
{
    return this->sharp_ratio;
}

double *Portfolio::getWeights()
{
    return this->weights;
}

Portfolio::~Portfolio()
{
}

string Portfolio::displayPortfolio()
{
    string s = "[ ";
    for (int i = 0; i < number_assets; i++)
    {
        s += to_string(weights[i]) + " ";
    }
    s += "]";
    return s;
}

void Portfolio::mutate()
{
    int maxbound = 0;
    int randomInteger;
    while ((maxbound == 0))
    {
        randomInteger = rand() % this->number_assets; // draw an int to choose the weight to modify
        maxbound = (weights[randomInteger] * 100);
    }
    double randomDouble = (double)(rand() % maxbound) / 100; // draw a double
    if (randomInteger == this->number_assets - 1)            // if the selected weight is the last one
    {
        weights[randomInteger] -= randomDouble; // update selected weight
        weights[0] += randomDouble;             // updtae first weight
    }
    else
    {
        weights[randomInteger] -= randomDouble;     // update selected weight
        weights[randomInteger + 1] += randomDouble; // update next weight
    }
}

bool Portfolio::operator<(const Portfolio &other) const
{
    return sharp_ratio < other.sharp_ratio;
}