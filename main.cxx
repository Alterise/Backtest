#include <iostream>
#include <string>
#include <format>

#include "utils.hxx"
#include "strategies.hxx"

int main() {
    Candle candle{500.0, 600.0, std::chrono::system_clock::now()};
    std::cout << std::format("Open price: {}, close price: {}, time: {}", candle.open_price_, candle.close_price_, candle.time_) << std::endl;
    std::vector<Candle> candles{candle};
    auto strategy = Strategy();
    std::cout << strategy.Apply(candles) << std::endl;
}