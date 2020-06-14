#include "Number.hpp"

using calculator::Number;

Number::Number(double value) :
    Operand(),
    value(value) { }

double Number::evaluate(Environment& environment) {
    return this->value;
}
