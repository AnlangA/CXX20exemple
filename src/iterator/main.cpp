#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // Standard iteration
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  // Range-based for loop with auto
  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  // Range-based for loop with auto
  for (const auto num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  // Using reverse iterator
  for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
    std::cout << *rit << " ";
  }
  std::cout << "\n";

  // Iterator arithmetic
  auto mid = numbers.begin() + numbers.size() / 2;
  std::cout << "Middle element: " << *mid << "\n";

  // Iterator with advance
  auto it = numbers.begin();
  std::advance(it, 2);
  std::cout << "Third element: " << *it << "\n";

  // Iterator with next/prev
  auto next_it = std::next(numbers.begin());
  auto prev_it = std::prev(numbers.end());
  std::cout << "Second element: " << *next_it << "\n";
  std::cout << "Last element: " << *prev_it << "\n";

  return 0;
}
