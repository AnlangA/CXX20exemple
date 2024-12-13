#include <iostream>
#include <cassert>
#include <vector>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        // Assert that dimensions are positive
        assert(width > 0 && "Width must be positive");
        assert(height > 0 && "Height must be positive");
    }

    double getArea() const {
        return width * height;
    }

    void resize(double w, double h) {
        // Static assert (compile-time check)
        static_assert(sizeof(double) >= 4, "Double type must be at least 4 bytes");

        assert(w > 0 && "Width must be positive");
        assert(h > 0 && "Height must be positive");

        width = w;
        height = h;
    }
};

// Function with contract-like assertions
void processNumbers(const std::vector<int>& numbers) {
    // Pre-condition
    assert(!numbers.empty() && "Vector cannot be empty");

    // Processing...
    for (size_t i = 0; i < numbers.size(); ++i) {
        // Internal invariant
        assert(i < numbers.size() && "Index out of bounds");
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Post-condition
    assert(numbers.size() == numbers.size() && "Vector size shouldn't change");
}

int main() {
    // Enable assertions (normally set by compiler flags)


    try {
        // Valid usage
        Rectangle rect(5.0, 3.0);
        std::cout << "Area: " << rect.getArea() << std::endl;

        // This will trigger an assertion
        // rect.resize(-2.0, 4.0);  // Uncomment to see assertion failure

        std::vector<int> nums = {1, 2, 3, 4, 5};
        processNumbers(nums);

        // This will trigger an assertion
        // std::vector<int> empty;
        // processNumbers(empty);  // Uncomment to see assertion failure

        // Custom assertion with message
        int x = -1;
        assert(x >= 0 && "x must be non-negative");

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
