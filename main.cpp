#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function to calculate the moving average
double movingAverage(const std::vector<double>& prices, int period) {
    double sum = 0.0;
    for (int i = prices.size() - period; i < prices.size(); ++i) {
        sum += prices[i];
    }
    return sum / period;
}

// Fetching market data from a public API (Binance example)
std::vector<double> getMarketData(const std::string& symbol) {
    std::vector<double> prices;
    std::string url = " " + symbol + "&interval=1m&limit=100";
    auto response = cpr::Get(cpr::Url{url});

    if (response.status_code == 200) {
        auto jsonData = json::parse(response.text);
        for (const auto& candle : jsonData) {
            prices.push_back(std::stod(candle[4].get<std::string>())); // Closing price
        }
    }
    return prices;
}

void tradeStrategy(const std::string& symbol) {
    const int shortMA = 5;
    const int longMA = 20;
    std::vector<double> prices = getMarketData(symbol);

    if (prices.size() < longMA) {
        std::cout << "Not enough data for analysis!" << std::endl;
        return;
    }

    double shortMovingAvg = movingAverage(prices, shortMA);
    double longMovingAvg = movingAverage(prices, longMA);

    std::cout << "Short MA: " << shortMovingAvg << " | Long MA: " << longMovingAvg << std::endl;

    // Trading logic: Buy or Sell
    if (shortMovingAvg > longMovingAvg) {
        std::cout << "Buy Signal!" << std::endl;
    } else if (shortMovingAvg < longMovingAvg) {
        std::cout << "Sell Signal!" << std::endl;
    } else {
        std::cout << "Hold Position." << std::endl;
    }
}

int main() {
    std::string symbol = " "; //  symbol
    tradeStrategy(symbol);
    return 0;
}
