#pragma once

#include <chrono>

struct Candle {
    double open_price_;
    double close_price_;
    std::chrono::system_clock::time_point time_;
};
