#include "Stock.hpp"

void Stock::addData(const string &date, double close)
{
	dates.push_back(date);
	closes.push_back(close);
}

void Stock::computeReturns()
{
	this->returns.clear();
	for (size_t i = 1; i < closes.size(); ++i)
	{
		double returnVal = (closes[i] - closes[i - 1]) / closes[i - 1];
		this->returns.push_back(returnVal);
	}
}

string Stock::getSymbol()
{
	return this->symbol;
}