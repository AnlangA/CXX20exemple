import math;
import geometry;
#include <iostream>

int main() {
    double a = 5.0, b = 3.0;

    std::cout << "Math operations:\n";
    std::cout << "Add: " << math::add(a, b) << '\n';
    std::cout << "Square of " << a << ": " << math::square(a) << '\n';

    std::cout << "\nGeometry calculations:\n";
    std::cout << "Circle area (r=5): " << geometry::circleArea(5.0) << '\n';
    std::cout << "Rectangle area (4x6): " << geometry::rectangleArea(4.0, 6.0) << '\n';

    return 0;
}
