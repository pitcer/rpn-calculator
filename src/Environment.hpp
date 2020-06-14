#pragma once

#include <map>
#include <stack>
#include <string>

using std::map;
using std::stack;
using std::string;

namespace calculator {

class Environment {

private:
    map<string, double>& variables;
    stack<double>& values;

public:
    Environment(map<string, double>& variables, stack<double>& values);

public:
    double getVariable(string name);

    double popValue();

    bool isValuesEmpty();
};

}
