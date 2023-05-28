#pragma once

#include <chrono>

struct Price {
    double open_price;
    double close_price;
    std::chrono::system_clock::time_point time;
};