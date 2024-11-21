#include <iostream>
#include <calculator.h>

int main(int argc, char** argv)
{
	Calculator calc{};

    std::cout << "2 + 5 = " << calc.Add(2,5) << std::endl;
    return 0;
}