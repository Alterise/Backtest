#include "dataset.hxx" 

Dataset::Dataset(const std::filesystem::path& path) {

}

std::vector<Price> Dataset::Get() const {
    return data_;
}

void Dataset::ParseDataset(const std::filesystem::path& path) {

}