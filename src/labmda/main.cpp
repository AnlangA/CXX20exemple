#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// Function that takes a lambda as parameter
void processNumbers(const std::vector<int> &nums,
                    const std::function<void(int)> &func) {
  for (int num : nums) {
    func(num);
  }
}

int main() {
  std::cout << "\n=== Basic Lambda Examples ===\n";

  // Simple lambda
  auto hello = []() { std::cout << "Hello, Lambda!\n"; };
  hello();

  // Lambda with parameters
  auto add = [](int a, int b) { return a + b; };
  std::cout << "2 + 3 = " << add(2, 3) << "\n";

  // Lambda with return type specified
  auto divide = [](double a, double b) -> double { return a / b; };
  std::cout << "10 / 3 = " << divide(10, 3) << "\n";

  std::cout << "\n=== Capture Examples ===\n";

  // Capture by value
  int multiplier = 10;
  auto multiply = [multiplier](int x) { return x * multiplier; };
  std::cout << "5 * 10 = " << multiply(5) << "\n";

  // Capture by reference
  int counter = 0;
  auto increment = [&counter]() { counter++; };
  increment();
  std::cout << "Counter: " << counter << "\n";

  // Capture all by value
  int x = 1, y = 2;
  auto captureAll = [=]() { return x + y; };
  std::cout << "x + y = " << captureAll() << "\n";

  std::cout << "\n=== Mutable Lambda ===\n";

  // Mutable lambda
  auto accumulator = [count = 0]() mutable { return ++count; };
  std::cout << "First call: " << accumulator() << "\n";
  std::cout << "Second call: " << accumulator() << "\n";

  std::cout << "\n=== Lambda with STL ===\n";

  // Using lambda with vectors and algorithms
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // forEach with lambda
  std::cout << "ForEach: ";
  std::for_each(numbers.begin(), numbers.end(),
                [](int n) { std::cout << n << " "; });
  std::cout << "\n";

  // Sort with lambda
  std::vector<int> nums = {3, 1, 4, 1, 5, 9};
  std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

  std::cout << "Sorted (descending): ";
  for (int n : nums) {
    std::cout << n << " ";
  }
  std::cout << "\n";

  std::cout << "\n=== Lambda as Function Parameter ===\n";

  // Passing lambda to function
  processNumbers(numbers,
                 [](int n) { std::cout << "Processing: " << n << "\n"; });

  std::cout << "\n=== Complex Lambda Example ===\n";

  // Lambda with multiple captures and complex logic
  std::string prefix = "Number: ";
  int threshold = 3;
  auto complexLambda = [prefix, threshold](int value) -> std::string {
    if (value > threshold) {
      return prefix + "High (" + std::to_string(value) + ")";
    } else {
      return prefix + "Low (" + std::to_string(value) + ")";
    }
  };

  std::cout << complexLambda(2) << "\n";
  std::cout << complexLambda(5) << "\n";

  std::cout << "\n=== Generic Lambda (C++14) ===\n";

  // Generic lambda
  auto genericAdd = [](auto a, auto b) { return a + b; };

  std::cout << "Int add: " << genericAdd(5, 3) << "\n";
  std::cout << "Double add: " << genericAdd(3.14, 2.14) << "\n";
  std::cout << "String add: " << genericAdd(std::string("Hello "), "World!")
            << "\n";

  return 0;
}
