#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用ranges
    for (int x : vec | std::views::filter([](int n) { return n % 2 == 0; })) {
        std::cout << x << " ";
    }

    return 0;
}
