#pragma once

#include "Operand.hpp"

#include <string>

using std::string;

namespace calculator {

class Variable : public Operand {

private:
    string name;

public:
    Variable(string name);

public:
    double evaluate(Environment& environment) override;
};

}
