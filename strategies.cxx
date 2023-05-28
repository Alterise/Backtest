#include "strategies.hxx"

double Strategy::Apply(const std::vector<Price>& prices) const {
    return 1.5;
}

double Strategy::Apply(const std::vector<Price>& prices, 
                       const std::chrono::time_point<std::chrono::system_clock>& start, 
                       const std::chrono::time_point<std::chrono::system_clock>& end) const {
    return 1.5;
}