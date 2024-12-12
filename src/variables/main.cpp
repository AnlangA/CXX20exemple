/// main.cpp
#include <complex>
import <iostream>;
using namespace std;
int main() {
  cout << "example about variables\n";

  double d1{1.0};
  double d2{2.0};
  complex<double> z{d1, d2};
  cout << "comple double:" << z << "\n";

  auto a = 1;
  cout << "aouto key:" << a;

  return 0;
}
