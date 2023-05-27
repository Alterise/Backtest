#pragma once

#include "utils.hxx"

class Strategy {
public:
    double Apply(const std::vector<Candle>&);
    double Apply(const std::vector<Candle>&, const std::chrono::time_point<std::chrono::system_clock>&, const std::chrono::time_point<std::chrono::system_clock>&);
};
