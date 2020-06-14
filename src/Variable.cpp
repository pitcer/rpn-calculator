#include "Variable.hpp"

using calculator::Variable;

Variable::Variable(string name) :
    name(name) { }

double Variable::evaluate(Environment& environment) {
    return environment.getVariable(this->name);
}
