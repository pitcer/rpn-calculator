#pragma once

#include "Constant.hpp"
#include "Function.hpp"
#include "Number.hpp"
#include "Symbol.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using std::map;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;

namespace calculator {

class Parser {

private:
    map<string, shared_ptr<Constant>> constants;
    map<string, shared_ptr<Function>> functions;
    map<string, double>& variables;

public:
    Parser(map<string, double>& variables);

public:
    vector<shared_ptr<Symbol>> parse(vector<string>& syntax_list);
    shared_ptr<Symbol> parse(string syntax);

private:
    bool isVariableValid(string name);
};

}
