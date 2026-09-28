#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
inline void print_vector(const std::vector<T>& data) {
    for (const auto& e : data) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    std::vector<int> v2;
    std::transform(
        v.begin(),
        v.end(),
        std::back_inserter(v2),
        [](const auto pair) { return pair.first; });

    print_vector(v2);

    std::vector<std::string> v3;
    std::transform(
        v.begin(),
        v.end(),
        std::back_inserter(v3),
        [](const auto pair) { return pair.second + std::string{":"} + std::to_string(pair.first); });

    print_vector(v3);

    std::vector<char> v4(13);
    std::generate(v4.begin(), v4.end(), [i{63}]() mutable { return i += 2; });

    print_vector(v4);

    return 0;
}
