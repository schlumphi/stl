#include "compression.hpp"

auto compressGrayscale(std::array<std::array<uint8_t, 32>, 32>& data) -> std::vector<std::pair<uint8_t, uint8_t>> {
    std::vector<std::pair<uint8_t, uint8_t>> compression;
    for (auto& row : data) {
        uint8_t pixel = row[0];
        size_t count = 1;
        for (auto it = row.begin() + 1; it < row.end(); ++it) {
            if (*it == pixel) {
                ++count;
            } else {
                compression.emplace_back(std::make_pair(pixel, count));
                pixel = *it;
                count = 1;
            }
        }
    }
    return compression;
}
