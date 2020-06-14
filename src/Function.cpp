#include "Function.hpp"

using calculator::Function;

Function::Function(string name, function<double(Environment&)> func) :
    Symbol(),
    name(name),
    func(func) {}

double Function::evaluate(Environment& environment) {
    return this->func(environment);
}
