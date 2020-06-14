#include "Constant.hpp"

using calculator::Constant;

Constant::Constant(string name, double value) :
    Operand(),
    name(name),
    value(value) { }

double Constant::evaluate(Environment& environment) {
    return this->value;
}
