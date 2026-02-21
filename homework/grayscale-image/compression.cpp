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

auto printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) -> void {
    for (const auto& row : bitmap) {
        for (const auto pixel : row) {
            std::cout << pixel;
        }
        std::cout << "\n";
    }
}

auto gen_bitmap(const size_t fraction) -> std::array<std::array<uint8_t, width>, height> {
    if (fraction == 0) {
        throw std::invalid_argument("gen_bitmap: expected positive 'fraction' num.");
    }
    std::array<std::array<uint8_t, width>, height> bitmap{0};

    std::vector<int> values(fraction);
    int curr_val = 0;
    for (auto& value : values) {
        value = curr_val++;
    }

    for (auto& row : bitmap) {
        auto it = row.begin();
        for (const auto val : values) {
            it = std::fill_n(it, width / values.size() + (width % values.size() != 0), val);
        }
    }
    return bitmap;
}
