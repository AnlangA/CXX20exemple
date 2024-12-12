#include <iomanip>
#include <iostream>
int count_x(const char *p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
  if (p == nullptr)
    return 0;
  int count = 0;
  while (*p) {
    if (*p == x)
      ++count;
    ++p;
  }
  return count;
}
int main() {
  int *p = nullptr;
  std::cout << "Address of nullptr: " << p << std::endl;
  std::cout << "Memory representation of nullptr: " << std::hex
            << reinterpret_cast<std::uintptr_t>(p) << std::endl;
  char *pchar = nullptr;
  char x = 'a';
  auto num = count_x(pchar, x);
  std::cout << num;
  return 0;
}
