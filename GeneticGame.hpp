#ifndef GENETICGAME
#define GENETICGAME

#include "Portfolio.hpp"
#include <algorithm> // Required for std::sort
class GeneticGame
{
private:
    vector<Portfolio> portfolios;
    int size_pop;
    int number_assets;
    Stock **stocks;

public:
    /// @brief destructor, delete all stocks
    ~GeneticGame();

    /// @brief constructor
    /// @param number_portfolio
    /// @param number_assets
    /// @param symbols list of tickers
    GeneticGame(int number_portfolio, int number_assets, string *symbols);

    /// @brief print all portfolio
    /// @return string
    string displayPortfolios();

    /// @brief print one portfolio using indice
    /// @param indice
    /// @return string
    string displayPortfolios(int indice);

    /// @brief mutate one portfolio
    /// @param indice
    void mutation(int indice);

    /// @brief create a new portfolio based on two portfolio, using crossover mechanism
    /// @param portfolio1
    /// @param portfolio2
    /// @return new portfolio
    Portfolio *crossover(int stock1, int stock2);

    /// @brief getter for portfolio
    /// @param indice
    /// @return Portfolio
    Portfolio getPortfolio(int indice);

    /// @brief sort the list of portfolio
    void sort();

    /// @brief create a new generation of portfolio
    void newgen();
};

#endif