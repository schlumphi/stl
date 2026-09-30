#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

template <typename T>
inline void print(const std::vector<T>& data) {
    for (const auto& elem : data) {
        std::cout << (int)elem << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);

    print(v);

    return 0;
}
