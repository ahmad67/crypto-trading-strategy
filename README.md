Crypto Trading Strategy Tool

This tool implements a basic moving average crossover strategy for crypto trading. It fetches market data from a public API , calculates moving averages, and generates trading signals (Buy/Sell/Hold).

 Features
- Fetches real-time market data from source.
- Implements a simple moving average crossover strategy.
- Generates Buy/Sell signals based on the strategy.

 Requirements
- C++ 17 or above
- cpr library for HTTP requests
- nlohmann/json library for JSON parsing

 Setup Instructions

 1. Install Dependencies

 2. Compile the Code
Compile the code using a compiler that supports C++  and link it with the installed libraries


 Usage
The tool fetches real-time data for currency pair and prints trading signals based on the moving average crossover strategy.

 Customization
- Change the trading pair by modifying the `symbol` variable in the `main` function.
- Adjust the short and long moving average periods to tweak the strategy.

