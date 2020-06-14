#pragma once

#include "Operand.hpp"
#include <string>

using std::string;

namespace calculator {

class Constant : public Operand {

private:
    string name;
    double value;

public:
    Constant(string name, double value);

public:
    double evaluate(Environment& environment) override;
};

}
