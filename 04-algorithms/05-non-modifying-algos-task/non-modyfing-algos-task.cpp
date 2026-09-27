#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    auto count = std::count_if(v.begin(), v.end(), [](auto value) { return value >= 5; });
    std::cout << count << "\n";
    std::cout << std::any_of(v.begin(), v.end(), [](auto value) { return value < 1; }) << "\n";
    std::cout << std::all_of(v.begin(), v.end(), [](auto value) { return value > 1; }) << "\n";

    return 0;
}
