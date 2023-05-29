#pragma once

#include <filesystem>
#include <chrono>
#include <span>

#include "utils.hxx"

class Dataset {
public:
    explicit Dataset(const std::filesystem::path& begin);
    // std::vector<Price> Get() const;
private:
    // void ParseDataset(const std::filesystem::path& path);
    std::vector<Price> data_;
};