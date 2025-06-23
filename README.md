# 📈 Genetic Algorithm for Portfolio Selection (C++)

This project applies a **Genetic Algorithm (GA)** to solve the financial portfolio optimization problem — maximizing the **Sharpe Ratio**, a measure of risk-adjusted returns. It is implemented in **C++**, with **Python** support for data retrieval from Yahoo Finance. The algorithm evolves portfolios over multiple generations using **selection, crossover, mutation, and elitism**, aiming to find the most efficient allocation of weights across a basket of risky assets and a risk-free asset.

---

## 🧠 Objective

Construct a portfolio composed of:
- A **risk-free asset** (fixed return, zero volatility)
- **12 risky assets** (listed below)

The goal is to **maximize the Sharpe ratio**, aligning with Modern Portfolio Theory (MPT) and the Capital Market Line (CML) framework.

---

## 💼 Assets Used

- MARA – Marathon Digital Holdings  
- TSLA – Tesla  
- NIO – NIO Inc.  
- AMD – Advanced Micro Devices  
- SOFI – SoFi Technologies  
- RIOT – Riot Blockchain  
- INTC – Intel Corporation  
- AAPL – Apple Inc.  
- F – Ford Motor Company  
- PFE – Pfizer Inc.  
- PLTR – Palantir Technologies  
- T – AT&T Inc.

---

## ⚙️ How It Works

### 🧬 Genetic Algorithm Components

- **Chromosome** = a portfolio (asset weight vector)
- **Gene** = individual weight of an asset
- **Fitness Function** = Sharpe Ratio of the portfolio

The algorithm proceeds in generations:
1. **Initialize** a population of random portfolios
2. **Evaluate** their Sharpe ratios
3. **Select** the top-performing half (elitism)
4. **Crossover** pairs of parents to create new portfolios
5. **Mutate** selected individuals randomly
6. **Repeat** until convergence or max generations reached

---

## 📐 UML Diagram

![UML Diagram](UML%20Class%20Diagram.png)

---

## 🧱 Code Structure
```bash
├── main.cpp # Entry point — runs the algorithm
├── GeneticGame.cpp/hpp # Evolution logic (population, mutation, crossover, elitism)
├── Portfolio.cpp/hpp # Represents a portfolio and computes Sharpe Ratio
├── Stock.cpp/hpp # Represents individual stocks
├── StockLoader.cpp/hpp # Loads stock data from CSVs into Stock objects
├── DataUtils.cpp/hpp # Shared statistical utilities (mean, stddev, covariance)
├── datadownloader.py # Python script to download historical stock data
├── UML Class Diagram.png # Visual structure of the system
```