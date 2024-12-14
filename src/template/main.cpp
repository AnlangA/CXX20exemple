#include <iostream>
#include <concepts>
#include <type_traits>

// 1. Basic Concept Definition
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

// 2. More Complex Concept with Multiple Requirements
template<typename T>
concept Printable = requires(T x) {
    { std::cout << x } -> std::same_as<std::ostream&>;
};

// 3. Concept with Compound Requirements
template<typename T>
concept Incrementable = requires(T x) {
    { ++x } -> std::same_as<T&>;      // Pre-increment
    { x++ } -> std::same_as<T>;       // Post-increment
    { x += 1 } -> std::same_as<T&>;   // Add-assign
};

// 4. Using Concepts in Function Templates
// Method 1: Using concept as a template parameter constraint
template<Numeric T>
T add(T a, T b) {
    return a + b;
}

// Method 2: Using requires clause
template<typename T>
requires Numeric<T>
T subtract(T a, T b) {
    return a - b;
}
/*
template<typename Numeric>
Numeric subtract(Numeric a, Numeric b) {
    return a - b;
}
*/

// Method 3: Using concept in function parameters
void print(Printable auto const& item) {
    std::cout << item << std::endl;
}

// 5. Concept Composition
template<typename T>
concept Number = Numeric<T> && Incrementable<T>;

// 6. Class Template with Concept
template<Number T>
class Calculator {
public:
    T value;
    Calculator(T v) : value(v) {}

    T add(T other) {
        return value + other;
    }
};

// 7. Multiple Concepts
template<typename T>
    requires Numeric<T> && Printable<T>
T processValue(T value) {
    std::cout << "Processing: " << value << std::endl;
    return value * 2;
}

int main() {
    // Using functions with concepts
    std::cout << add(5, 3) << std::endl;        // Works with int
    std::cout << add(3.14, 2.86) << std::endl;  // Works with double

    // Using class with concept
    Calculator<int> calc(10);
    std::cout << calc.add(5) << std::endl;

    // Using auto with concepts
    Numeric auto x = 42;
    Numeric auto y = 3.14;

    // Print function works with any Printable type
    print("Hello");
    print(42);
    print(3.14);

    // Process values
    std::cout << processValue(10) << std::endl;

    return 0;
}
