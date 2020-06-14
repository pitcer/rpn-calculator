#pragma once

#include "Symbol.hpp"

#include <string>
#include <functional>

using std::string;
using std::function;

namespace calculator {

class Function : public Symbol {

private:
    string name;
    function<double(Environment&)> func;

public:
    Function(string name, function<double(Environment&)> func);

public:
    double evaluate(Environment& environment);
};

}
