#include "GeneticGame.hpp"
#include "StockLoader.hpp"

GeneticGame::~GeneticGame()
{
    for (int i = 0; i < number_assets; i++)
    {
        delete stocks[i];
    }
    delete[] stocks;
}

GeneticGame::GeneticGame(int number_portfolio, int number_assets, string *symbols)
{
    this->size_pop = number_portfolio;
    this->number_assets = number_assets;
    this->portfolios.clear();
    this->stocks = StockLoader::loadStocks(symbols, number_assets);
    // first generation
    for (int i = 0; i < this->size_pop; i++)
    {
        portfolios.push_back(Portfolio(stocks, number_assets));
    }
}

string GeneticGame::displayPortfolios()
{
    string s = "";
    for (int i = 0; i < this->size_pop; i++)
    {
        s += this->portfolios[i].displayPortfolio() + " ";
    }
    s += "]";
    return s;
}

string GeneticGame::displayPortfolios(int indice)
{

    return this->portfolios[indice].displayPortfolio() + " ";
}

void GeneticGame::mutation(int indice)
{
    portfolios[indice].mutate();
}

Portfolio *GeneticGame::crossover(int portfolio1, int portfolio2)
{
    double *w1 = portfolios[portfolio1].getWeights();
    double *w2 = portfolios[portfolio2].getWeights();

    int randomInteger = rand() % this->number_assets; 
    double *w3 = new double[this->number_assets];
    double sum = 0;
    for (int i = 0; i < this->number_assets; i++)
    {
        if (i < randomInteger) // take weights from first portfolio up to randomInteger
        {
            w3[i] = w1[i];
        }
        else  // take weights from second portfolio above randomInteger
        {
            w3[i] = w2[i];
        }
        sum += w3[i];
    }
    
    // normalization
    for (int i = 0; i < this->number_assets; i++)
    {
        w3[i] /= sum;
    }
    return new Portfolio(this->stocks, w3, this->number_assets);
}

Portfolio GeneticGame::getPortfolio(int indice)
{
    return portfolios[indice];
}

void GeneticGame::sort()
{
    std::sort(portfolios.rbegin(), portfolios.rend());
}

void GeneticGame::newgen()
{
    // cout<<portfolios.size()<<endl;
    sort();
    // cout<<displayPortfolios()<<endl;
    int elite_pop = this->size_pop * 0.5;
    for (int i = 0; i < elite_pop; i++)
    {
        portfolios.pop_back();
    }
    // cout<<portfolios.size()<<endl;
    // crossover
    for (int i = 1; i < elite_pop + 1; i++)
    {
        portfolios.push_back(*crossover(i, i - 1));
    }
    // cout<<portfolios.size()<<endl;
    for (int i = 0; i < size_pop; i++)
    {
        mutation(i);
    }
}
