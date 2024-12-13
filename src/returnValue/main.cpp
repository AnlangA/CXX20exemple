import <iostream>;
import <string>;   // needed for string type

struct Entry {
    std::string name;
    int value;
};

// Simple version with exception handling
Entry read_entry(std::istream& is)
{
    std::string s;
    int i;

    if (!(is >> s >> i)) {
        throw std::runtime_error("Failed to read integer value");
    }

    return {s,i};
}

// Interactive version with retry loop
Entry read_entry2(std::istream& is)
{
    std::string s;
    int i;

    while (true) {
        std::cout << "Please enter a name and a number: ";
        if (is >> s >> i) {
            return {s,i};
        }

        std::cout << "Error: Invalid number. Please try again.\n";

        // Clear error flags and discard invalid input
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    // First example: using read_entry with exception handling
    try {
        std::cout << "Example 1 - Simple version:\n";
        std::cout << "Please enter a name and a number: ";
        auto e1 = read_entry(std::cin);
        std::cout << "{ " << e1.name << " , " << e1.value << " }\n\n";
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
        // Clear stream for next input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Second example: using read_entry2 with retry loop
    std::cout << "Example 2 - Interactive version:\n";
    auto e2 = read_entry2(std::cin);
    std::cout << "{ " << e2.name << " , " << e2.value << " }\n";

    return 0;
}
