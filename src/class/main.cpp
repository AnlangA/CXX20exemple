#include <iostream>

enum class Colors { RED, BLUE, GREEN, YELLOW };

class Animal {
private:
  std::string name;
  int age;
  Colors color;

public:
  Animal(std::string n, int a, Colors c) : name(n), age(a), color(c) {}

  void makeSound() { std::cout << "Animal makes sound!" << std::endl; }

  void setName(std::string n) { name = n; }

  std::string getName() { return name; }

  void setAge(int a) { age = a; }

  int getAge() { return age; }

  void setColor(Colors c) { color = c; }

  Colors getColor() { return color; }
};

#include <iostream>

// Basic enum class
enum class Color { Red, Green, Blue };

// Enum class with specified underlying type
enum class Flags : unsigned int { Option1 = 1, Option2 = 2, Option3 = 4 };

// Enum class with specified values
enum class HttpStatus : int {
  Ok = 200,
  Created = 201,
  BadRequest = 400,
  NotFound = 404
};

enum class Permissions : unsigned int {
  None = 0,
  Read = 1 << 0,   // 1
  Write = 1 << 1,  // 2
  Execute = 1 << 2 // 4
};

// Operator overloading for bitwise operations
constexpr Permissions operator|(Permissions a, Permissions b) {
  return static_cast<Permissions>(static_cast<unsigned int>(a) |
                                  static_cast<unsigned int>(b));
}

constexpr Permissions operator&(Permissions a, Permissions b) {
  return static_cast<Permissions>(static_cast<unsigned int>(a) &
                                  static_cast<unsigned int>(b));
}

int main() {
  Animal dog("Rex", 5, Colors::YELLOW);

  dog.makeSound();
  std::cout << "Name: " << dog.getName() << std::endl;
  std::cout << "Age: " << dog.getAge() << std::endl;

  // Using enum classes
  Color c = Color::Red;

  // Comparison
  if (c == Color::Red) {
    std::cout << "Color is red\n";
  }

  // Type safety
  // int x = c; // Error: no implicit conversion
  int x = static_cast<int>(c); // Explicit conversion needed

  // Using with switch
  HttpStatus status = HttpStatus::Ok;
  switch (status) {
  case HttpStatus::Ok:
    std::cout << "Request successful\n";
    break;
  case HttpStatus::NotFound:
    std::cout << "Resource not found\n";
    break;
  default:
    std::cout << "Other status\n";
  }

  Permissions userPerms = Permissions::Read | Permissions::Write;

  // Checking permissions
  if ((userPerms & Permissions::Read) == Permissions::Read) {
    std::cout << "Has read permission\n";
  }

  return 0;
}
