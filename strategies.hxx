#pragma once

#include<span>

#include "utils.hxx"

class Strategy {
public:
    double Apply(const std::vector<Price>& prices) const;
    double Apply(const std::vector<Price>& prices, 
                 const std::chrono::time_point<std::chrono::system_clock>& begin, 
                 const std::chrono::time_point<std::chrono::system_clock>& end) const;
};
