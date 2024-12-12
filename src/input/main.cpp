#include <iostream>
using namespace std;

int main() {
  int number;
  string name;

  cout << "Enter a number: ";
  cin >> number;

  cout << "Enter your name: ";
  cin >> name;

  cout << "Hello " << name << ", you entered: " << number << endl;

  return 0;
}
