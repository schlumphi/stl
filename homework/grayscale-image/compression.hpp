#pragma once
#include <array>
#include <cstdint>
#include <utility>
#include <vector>

auto compressGrayscale(std::array<std::array<uint8_t, 32>, 32>& data) -> std::vector<std::pair<uint8_t, uint8_t>>;

auto decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& data) -> std::array<std::array<uint8_t, 32>, 32>;
