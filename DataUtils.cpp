#include "DataUtils.hpp"

void DataUtils::computeSTD()
{
    if (this->returns.empty())
    {
        this->std = 0.0; // No returns available
    }
    else
    {
        // Calculate standard deviation
        double std = 0.0;
        for (double ret : returns)
        {
            std += pow(ret - this->mean, 2);
        }

        this->std = sqrt(std / returns.size());
    }
}

void DataUtils::computeMean()
{
    // Calculate mean
    double mean = 0.0;
    for (double ret : this->returns)
    {
        mean += ret;
    }
    mean /= this->returns.size();
    this->mean = mean;
}

double DataUtils::computeCovariance(DataUtils *otherdata)
{
    double mean1 = getMean();
    double mean2 = otherdata->getMean();
    double covariance = 0.0;

    for (size_t i = 0; i < returns.size(); ++i)
    {
        covariance += (returns[i] - mean1) * (otherdata->getReturns()[i] - mean2);
    }

    return covariance / returns.size();
}

DataUtils::~DataUtils()
{
    this->returns.clear();
}

DataUtils::DataUtils()
{
}

DataUtils::DataUtils(vector<double> d)
{
    this->returns = d;
    computeMean();
    computeSTD();
}

vector<double> DataUtils::getReturns()
{
    return this->returns;
}

double DataUtils::getSTD()
{
    return this->std;
}

double DataUtils::getMean()
{
    return this->mean;
}
