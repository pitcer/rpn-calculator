#pragma once

#include "Command.hpp"
#include "CalculatorState.hpp"

namespace calculator {

class ExitCommand : public Command {

private:
    CalculatorState& states;

public:
    ExitCommand(Messenger& messenger, CalculatorState& states);

public:
    void execute(vector<string>& arguments) const override;
};

}
