#pragma once

#include "Command.hpp"
#include "Evaluator.hpp"
#include "Parser.hpp"

namespace calculator {

class PrintCommand : public Command {

private:
    Parser& parser;
    Evaluator& evaluator;

public:
    PrintCommand(Messenger& messenger, Parser& parser, Evaluator& evaluator);

public:
    void execute(vector<string>& arguments) const override;
};

}
