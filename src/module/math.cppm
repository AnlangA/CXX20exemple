module;

#include <cmath>

export module math;

export namespace math {
    double add(double a, double b) {
        return a + b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double square(double x) {
        return x * x;
    }
}
