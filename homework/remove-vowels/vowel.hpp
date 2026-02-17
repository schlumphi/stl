#pragma once
#include <array>
#include <string>
#include <vector>

inline constexpr std::array<const char, 12> VOWELS{
    'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};

auto removeChar(std::string& data, const char c) -> void;

auto removeVowels(std::vector<std::string>& data) -> void;
