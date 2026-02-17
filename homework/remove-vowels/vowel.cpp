#include "vowel.hpp"
#include <algorithm>
#include <string>

auto removeChar(std::string& data, const char c) -> void {
    while (data.find(c) < data.size()) {
        data.erase(data.begin() + data.find(c));
    }
}

auto removeVowels(std::vector<std::string>& data) -> void {
    for (auto& str : data) {
        for (auto chr : VOWELS) {
            removeChar(str, chr);
        }
    }
}
