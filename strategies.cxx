#include "strategies.hxx"

double Strategy::Apply(const std::vector<Candle>& candles) {
    return 1.5;
}

double Strategy::Apply(const std::vector<Candle>& candles, 
                       const std::chrono::time_point<std::chrono::system_clock>& start, 
                       const std::chrono::time_point<std::chrono::system_clock>& end) {
    return 1.5;
}