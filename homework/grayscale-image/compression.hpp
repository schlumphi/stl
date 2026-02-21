#pragma once
#include <array>
#include <cstdint>
#include <utility>
#include <vector>

constexpr size_t width = 64;
constexpr size_t height = 64;

auto compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) -> std::vector<std::pair<uint8_t, uint8_t>>;

auto decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) -> std::array<std::array<uint8_t, width>, height>;

auto printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) -> void;

auto gen_bitmap(const size_t fraction) -> std::array<std::array<uint8_t, width>, height>;
