#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    std::vector<int> v2(v.size());
    std::transform(
        v.begin(),
        v.end(),
        v2.begin(),
        [](const auto pair) { return pair.first; });

    for (const auto& e : v2) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    return 0;
}
