#include "compression.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>

auto compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) -> std::vector<std::pair<uint8_t, uint8_t>> {
    std::vector<std::pair<uint8_t, uint8_t>> compression;
    compression.reserve(height * width);
    for (const auto& row : bitmap) {
        compression.emplace_back(std::make_pair(row[0], 0));
        for (const auto& pixel : row) {
            if (pixel == compression.back().first) {
                ++compression.back().second;
            } else {
                compression.emplace_back(std::make_pair(pixel, 1));
            }
        }
    }

    return compression;
}

auto decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) -> std::array<std::array<uint8_t, width>, height> {
    if (std::accumulate(
            compressed_bitmap.begin(),
            compressed_bitmap.end(),
            0,
            [](size_t sum, const std::pair<uint8_t, uint8_t>& entry) { return sum + entry.second; }) != height * width) {
        throw std::invalid_argument("decompressGrayscale: invalid pixels count in 'compressed_bitmap'.");
    }
    std::array<std::array<uint8_t, width>, height>
        decompression{0};
    auto it = decompression[0].data();
    for (const auto& [value, count] : compressed_bitmap) {
        std::memset(it, value, count);
        it += count;
    }

    return decompression;
}
