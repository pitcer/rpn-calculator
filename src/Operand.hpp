#pragma once

#include "Symbol.hpp"

namespace calculator {

class Operand : public Symbol {

public:
    Operand();

public:
    virtual double evaluate(Environment& environment) = 0;
};

}
