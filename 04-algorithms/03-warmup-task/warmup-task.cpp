#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto print_vec = [&](std::vector<int>& data) { for (const auto& elem : data) {std::cout << elem << " ";} };
    print_vec(v);

    auto print_int = [](int value) { std::cout << value; };

    std::for_each(v.begin(), v.end(), print_int);

    return 0;
}
