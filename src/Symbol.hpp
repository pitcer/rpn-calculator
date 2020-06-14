#pragma once

#include "Environment.hpp"

namespace calculator {

class Symbol {

public:
    Symbol();

public:
    virtual double evaluate(Environment& environment) = 0;
};

}
