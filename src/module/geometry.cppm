export module geometry;

import math;  // importing another module

export namespace geometry {
    constexpr double PI = 3.14159265359;

    double circleArea(double radius) {
        return PI * math::square(radius);
    }

    double rectangleArea(double width, double height) {
        return math::multiply(width, height);
    }
}
