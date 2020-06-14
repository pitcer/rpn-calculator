#include "ExitCommand.hpp"

using calculator::CalculatorState;
using calculator::ExitCommand;

ExitCommand::ExitCommand(Messenger& messenger, CalculatorState& states) :
    Command("exit", messenger),
    states(states) { }

void ExitCommand::execute(vector<string>& arguments) const {
    this->states.disable();
    this->messenger.sendLine("Bye!");
}
