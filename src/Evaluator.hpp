#pragma once

#include "Symbol.hpp"
#include <memory>
#include <vector>

using calculator::Symbol;
using std::shared_ptr;
using std::vector;

namespace calculator {

class Evaluator {

private:
    map<string, double>& variables;

public:
    Evaluator(map<string, double>& variables);

public:
    double evaluate(vector<shared_ptr<Symbol>> symbols);
};

}
