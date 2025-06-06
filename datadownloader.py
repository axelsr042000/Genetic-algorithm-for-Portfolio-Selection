import yfinance as yf
import pandas as pd

def download_stock_data(ticker, start_date, end_date):
    stock_data = yf.download(ticker, start=start_date, end=end_date)
    return stock_data

def save_to_csv(stock_data, ticker):
    filename = f"{ticker}.csv"
    stock_data.to_csv(filename)
    print(f"Data for {ticker} saved to {filename}")

def main():
    # List of stock tickers
    stock_tickers = {"MARA",
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
        "T"}

    # Define date range
    start_date = "2023-01-01"
    end_date = "2023-12-31"

    for ticker in stock_tickers:
        # Download stock data
        stock_data = download_stock_data(ticker, start_date, end_date)

        # Save data to CSV
        save_to_csv(stock_data, ticker)

if __name__ == "__main__":
    main()
