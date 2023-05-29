#include <iostream>
#include <string>
#include <format>
#include <filesystem>
#include <ranges>
#include <cctype>
#include <algorithm>

#include "utils.hxx"
#include "strategies.hxx"
#include "dataset.hxx"

char tol(const char x)
{
    return std::tolower(x);
}

int main() {
    // Price price{500.0, 600.0, std::chrono::system_clock::now()};
    // std::cout << std::format("Open price: {}, close price: {}, time: {}", candle.open_price, candle.close_price, candle.time) << std::endl;
    // std::span<Price> candles{candle};
    // auto strategy = Strategy();
    // std::cout << strategy.Apply(candles) << std::endl;

    std::filesystem::path path("bitcoin.csv");

    // Dataset dataset(path);
    
    std::string words = "ADASDS,dasdaAS,afsSADAadfasfas,fafaafasfda";
    for (const auto word : words | std::views::split(',')) {
        std::cout << std::string_view(word) << ' ';
    }
}