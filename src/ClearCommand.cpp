#include "ClearCommand.hpp"

using calculator::ClearCommand;

ClearCommand::ClearCommand(Messenger& messenger, map<string, double>& variables) :
    Command("clear", messenger),
    variables(variables) {}

void ClearCommand::execute(vector<string>& arguments) const {
    this->variables.clear();
    this->messenger.sendLine("Variables cleared!");
}
