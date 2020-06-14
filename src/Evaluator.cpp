#include "Evaluator.hpp"

using calculator::Evaluator;

Evaluator::Evaluator(map<string, double>& variables) :
    variables(variables) { }

double Evaluator::evaluate(vector<shared_ptr<Symbol>> symbols) {
    stack<double> values;
    Environment environment(this->variables, values);
    for (auto& symbol : symbols) {
        double value = symbol->evaluate(environment);
        values.push(value);
    }
    return environment.popValue();
}
