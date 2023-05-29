#include <algorithm>
#include <fstream>
#include <ranges>
#include <iostream>

#include "dataset.hxx" 

Dataset::Dataset(const std::filesystem::path& path) {
    std::ifstream file(path);
    std::string line;
    std::getline(file, line);
    std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){ return std::tolower(c); });
    for (const auto column : line | std::views::split(',') | std::views::filter(
        [](std::string_view str) {
            return str.find("date") != str.npos | str.find("open") != str.npos || str.find("close") != str.npos; 
        }
    )) {
        std::cout << std::string_view(column) << " ";
    }
    while(std::getline(file, line)) {
        
    }
}

// std::span<const Price> Dataset::Get() const {
//     return data_;
// }

// std::span<const Price> Dataset::GetSlice() const {
//     std::ranges::find(data_, );
//     return data_;
// }

// void Dataset::ParseDataset(const std::filesystem::path& path) {

// }