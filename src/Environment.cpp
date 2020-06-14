#include "Environment.hpp"

#include "EvaluatorException.hpp"

using calculator::Environment;
using calculator::EvaluatorException;

Environment::Environment(map<string, double>& variables, stack<double>& values) :
    variables(variables),
    values(values) { }

double Environment::getVariable(string name) {
    auto variable_result = this->variables.find(name);
    if (variable_result == this->variables.end()) {
        throw EvaluatorException("Variable named '" + name + "' is not assigned");
    }
    return variable_result->second;
}

double Environment::popValue() {
    if (this->values.empty()) {
        throw EvaluatorException("Values stack is empty");
    }
    double value = this->values.top();
    this->values.pop();
    return value;
}

bool Environment::isValuesEmpty() {
    return this->values.empty();
}
