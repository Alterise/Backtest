#include <iostream>
#include <string>
#include <filesystem>

#include "utils.hxx"
#include "strategies.hxx"
#include "dataset.hxx"

int main() {
    std::filesystem::path path("stocks/BTC-Hourly.csv");
    Dataset dataset(path);
    auto data = dataset.GetSlice(*Dataset::ParseDate("2019-01-01 00:00:00"), *Dataset::ParseDate("2021-12-31 00:00:00"));
    Strategy strategy;
    std::cout << "Strategy profit (per 1 stock): " << strategy.Apply(data) << std::endl;
}