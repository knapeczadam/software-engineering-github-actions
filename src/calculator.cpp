#include "calculator.h"
#include <stdexcept>

int Calculator::Add(int a, int b) {
    return a + b;
}

int Calculator::Subtract(int a, int b) {
    return a - b;
}

int Calculator::Multiply(int a, int b) {
    return a * b;
}

double Calculator::Divide(int a, int b) {
    if (b == 0) throw std::invalid_argument("Division by zero");
    return static_cast<double>(a) / b;
}

int Calculator::Factorial(int n) {
    if (n < 0) throw std::invalid_argument("Negative input for factorial");
    return (n <= 1) ? 1 : n * Factorial(n - 1);
}

int Calculator::Power(int base, int exp) {
    if (exp < 0) throw std::invalid_argument("Negative exponent");
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}