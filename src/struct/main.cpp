#include <iostream>
using namespace std;

struct Person {
  string name;
  int age;
  float height;

  void displayInfo() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
  }
};

int main() {
  Person person1;

  person1.name = "John";
  person1.age = 25;
  person1.height = 1.75f;

  person1.displayInfo();

  return 0;
}
