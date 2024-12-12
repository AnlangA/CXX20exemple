#include <iostream>

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 5, b = 10;

  std::cout << "Before swap - a: " << a << ", b: " << b << std::endl;

  swap(a, b);

  std::cout << "After swap - a: " << a << ", b: " << b << std::endl;

  // Reference to variable a
  int &ref = a;
  ref = 20; // Changes value of a

  std::cout << "After reference change - a: " << a << std::endl;

  /* int& a; // error: uninitialized reference
  a = 12;
  std::cout << a;
  */
  return 0;
}
