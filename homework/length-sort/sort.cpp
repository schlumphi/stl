#include "sort.hpp"

auto lengthSort(std::forward_list<std::string>& data) -> std::deque<std::string> {
    std::deque<std::string> result;
    data.sort([](std::string first, std::string second) {
        if (first.size() == second.size()) {
            return first < second;
        } else {
            return first.size() < second.size();
        }
    });

    for (auto& str : data) {
        result.push_back(str);
    }
    return result;
}
