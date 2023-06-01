#pragma once

#include<span>

#include "utils.hxx"

class Strategy {
public:
    double Apply(const std::span<const Price>& prices) const;
    double Apply(const std::vector<Price>& prices) const;
};
