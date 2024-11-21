#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <calculator.h>

TEST_SUITE("Basic Arithmetic")
{
    TEST_CASE("Addition") {
        Calculator calc;

        CHECK(calc.Add(2, 3) == 5);
        CHECK(calc.Add(-1, 1) == 0);
        CHECK(calc.Add(0, 0) == 0);
    }

    TEST_CASE("Subtraction") {
        Calculator calc;

        CHECK(calc.Subtract(5, 3) == 2);
        CHECK(calc.Subtract(0, 1) == -1);
        CHECK(calc.Subtract(-1, -1) == 0);
    }

    TEST_CASE("Multiplication")
    {
        Calculator calc;

        CHECK(calc.Multiply(2, 3) == 6);
        CHECK(calc.Multiply(-2, 3) == -6);
        CHECK(calc.Multiply(0, 100) == 0);
    }

    TEST_CASE("Division")
    {
        Calculator calc;

        CHECK(calc.Divide(10, 2) == doctest::Approx(5.0));
        CHECK(calc.Divide(-10, 2) == doctest::Approx(-5.0));
        CHECK_THROWS_AS(calc.Divide(10, 0), std::invalid_argument);
    }

    TEST_CASE("Factorial Operation")
    {
        Calculator calc;

        CHECK(calc.Factorial(0) == 1);          // Edge case: 0!
        CHECK(calc.Factorial(1) == 1);          // Edge case: 1!
        CHECK(calc.Factorial(5) == 120);        // Normal case: 5!
        CHECK_THROWS_AS(calc.Factorial(-3), std::invalid_argument);  // Invalid case: negative input
    }

    TEST_CASE("Power Operation" * doctest::skip())
    {
        Calculator calc;

        CHECK(calc.Power(2, 3) == 8);           // Normal case: 2^3
        CHECK(calc.Power(5, 0) == 1);           // Edge case: anything ^ 0
        CHECK(calc.Power(0, 5) == 0);           // Edge case: 0 ^ anything
        CHECK_THROWS_AS(calc.Power(2, -2), std::invalid_argument);   // Invalid case: negative exponent
    }
}