#include "Calculator.hpp"

using calculator::Calculator;
using calculator::Messenger;

#include <iostream>

int main() {
    Messenger messenger(std::cin, std::cout, std::clog);
    Calculator calculator(messenger);
    calculator.run();
    return 0;
}
