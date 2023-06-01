#include <algorithm>
#include <fstream>
#include <ranges>
#include <iostream>
#include <optional>
#include <limits>

#include "dataset.hxx" 

Dataset::Dataset(const std::filesystem::path& path) {
    ParseDataset(path);
}

std::vector<Price> Dataset::Get() const {
    return data_;
}

std::span<const Price> Dataset::GetSlice(int first_id, int last_id) const {
    auto span = std::span<const Price>(data_);
    first_id = std::max(0, first_id);
    last_id = std::min(static_cast<int>(span.size()), last_id);
    return span.subspan(first_id, last_id - first_id);
}

std::span<const Price> Dataset::GetSlice(std::chrono::system_clock::time_point first_date, 
                                         std::chrono::system_clock::time_point last_date) const {
    auto span = std::span<const Price>(data_);
    int first_id = 0, last_id = std::numeric_limits<int>::max();
    for (int i = 0; i < span.size(); i++) {
        if (data_[i].time > first_date) {
            first_id = i;
            break;
        }
    }
    
    for(int i = first_id; i < span.size(); i++) {
        if (data_[i].time > last_date) {
            last_id = i;
            break;
        }
    }

    return GetSlice(first_id, last_id);
}

void Dataset::ParseDataset(const std::filesystem::path& path) {
    std::ifstream file(path);
    std::string line;
    std::getline(file, line);
    std::transform(line.begin(), line.end(), line.begin(), [](char c){ return std::tolower(c); });

    auto columns = ParseString(line, ",");
    int columns_count = columns.size();
    int date_pos, open_price_pos, close_price_pos; 
    int pos = 0;
    for(const auto& column : columns) {
        if (column.find("date") != column.npos) {
            date_pos = pos;
        } else if (column.find("open") != column.npos) {
            open_price_pos = pos;
        } else if (column.find("close") != column.npos) {
            close_price_pos = pos;
        }
        pos++;
    }

    while(std::getline(file, line)) {
        auto tokens = ParseString(line, ",", columns_count);
        auto date = ParseDate(tokens[date_pos]);
        if (date) {
            try{
                data_.emplace_back(std::stod(tokens[open_price_pos]), std::stod(tokens[close_price_pos]), *date);
            }
            catch(const std::exception& e) {
                std::cerr << "Incorrect value" << std::endl;
                continue;
            }
        }       
    }

    std::ranges::sort(data_, [](const Price& a, const Price& b) { return a.time < b.time; });
}

std::vector<std::string> Dataset::ParseString(const std::string& str, const std::string& delimiter, int token_count) {
    std::vector<std::string> tokens;
    if (token_count > 0) {
        tokens.reserve(token_count);
    }
    long long lb = 0, rb = 0;
    while ((rb = str.find(delimiter, lb)) != str.npos) {
        tokens.push_back(str.substr(lb, rb - lb));
        lb = rb + 1;
    }

    return std::move(tokens);
}

std::optional<std::chrono::system_clock::time_point> Dataset::ParseDate(const std::string& str) {
    std::optional<std::chrono::system_clock::time_point> result;
    struct tm tm;
    if (strptime(str.c_str(), "%Y-%m-%d %T", &tm)) {
        result = std::chrono::system_clock::from_time_t(std::mktime(&tm) - __timezone);
    }
    return result;
}