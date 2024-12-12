import <iostream>;

// const: value cannot be modified after initialization
const int MAX_VALUE = 100;
const double PI = 3.14159;

// constexpr: evaluated at compile time
constexpr int ARRAY_SIZE = 10;
constexpr int square(int x) { return x * x; }

class Example {
    const int classConst = 42;  // const member variable
    static constexpr int staticConstexpr = 100;  // static constexpr member

public:
    Example() {}

    // const member function - cannot modify class members
    int getClassConst() const {
        return classConst;
    }
};

int main() {
    // const variables
    const int x = 5;
    // x = 10;  // Error: cannot modify const variable

    // const pointer to non-const data
    int value = 10;
    int* const ptr1 = &value;
    *ptr1 = 20;      // OK: can modify the data
    // ptr1 = &x;    // Error: cannot modify the pointer

    // pointer to const data
    const int* ptr2 = &value;
    // *ptr2 = 30;   // Error: cannot modify the data
    ptr2 = &x;       // OK: can modify the pointer

    // constexpr examples
    constexpr int squared = square(5);  // computed at compile time
    int arr[ARRAY_SIZE];                // array size must be known at compile time

    Example example;
    std::cout << example.getClassConst() << std::endl;

    return 0;
}
