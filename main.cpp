#include "StockLoader.cpp"
#include "Stock.cpp"
#include "Portfolio.cpp"
#include "DataUtils.cpp"
#include "GeneticGame.cpp"
#include <random>
#include <time.h>
int main()
{
    srand(time(NULL));
    // random seed
    int NB_PORTFOLIO = 100;
    int NB_ASSESTS = 12;
    int NB_GENERATION = 100;
    string SYMBOLS[12] = {
        "MARA",
        "TSLA",
        "NIO",
        "AMD",
        "SOFI",
        "RIOT",
        "INTC",
        "AAPL",
        "F",
        "PFE",
        "PLTR",
        "T"};
    GeneticGame g = GeneticGame(NB_PORTFOLIO, NB_ASSESTS, SYMBOLS);

    for (int i = 0; i < NB_GENERATION; i++)
    {
        g.sort();
        cout << "generation " << i << endl;
        cout << "best portfolio : " << g.getPortfolio(0).displayPortfolio() << endl;
        cout << "best sharp ratio : " << g.getPortfolio(0).getSharpRatio() << endl;
        cout << "worst portfolio : " << g.getPortfolio(NB_PORTFOLIO - 1).displayPortfolio() << endl;
        cout << "worst sharp ratio : " << g.getPortfolio(NB_PORTFOLIO - 1).getSharpRatio() << endl;
        g.newgen();
    }
    return 0;
}