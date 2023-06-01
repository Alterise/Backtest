#pragma once

#include <filesystem>
#include <chrono>
#include <span>

#include "utils.hxx"

class Dataset {
public:
    explicit Dataset(const std::filesystem::path& begin);
    std::vector<Price> Get() const;
    std::span<const Price> GetSlice(int first_id, int last_id) const;
    std::span<const Price> GetSlice(std::chrono::system_clock::time_point first_date, 
                                    std::chrono::system_clock::time_point last_date) const;
    static std::vector<std::string> ParseString(const std::string& str, const std::string& delimiter, int token_count = 0);
    static std::optional<std::chrono::system_clock::time_point> ParseDate(const std::string& str);
private:
    void ParseDataset(const std::filesystem::path& path);
    std::vector<Price> data_;
};