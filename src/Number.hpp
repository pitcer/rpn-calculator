#pragma once

#include "Operand.hpp"

namespace calculator {

class Number : public Operand {

private:
    double value;

public:
    Number(double value);

public:
    double evaluate(Environment& environment) override;
};

}
