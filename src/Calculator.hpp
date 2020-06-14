#pragma once

#include "CalculatorState.hpp"
#include "Command.hpp"
#include "Evaluator.hpp"
#include "Messenger.hpp"
#include "Parser.hpp"
#include <map>

using std::map;
using std::shared_ptr;
using std::string;

namespace calculator {

class Calculator {

private:
    Messenger& messenger;
    CalculatorState state;
    map<string, double> variables;
    Parser parser;
    Evaluator evaluator;
    map<string, shared_ptr<Command>> commands;

public:
    Calculator(Messenger& messenger);

public:
    void run();

private:
    vector<string> readWords();
};

}
