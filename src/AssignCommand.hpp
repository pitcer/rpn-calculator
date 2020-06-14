#pragma once

#include "Command.hpp"
#include "Evaluator.hpp"
#include "Parser.hpp"
#include <map>

using calculator::Command;
using std::map;

namespace calculator {

class AssignCommand : public Command {

private:
    map<string, double>& variables;
    Parser& parser;
    Evaluator& evaluator;

public:
    AssignCommand(Messenger& messenger, map<string, double>& variables, Parser& parser, Evaluator& evaluator);

public:
    void execute(vector<string>& arguments) const override;
};

}
