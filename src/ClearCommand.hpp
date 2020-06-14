#pragma once

#include "Command.hpp"
#include <map>

using calculator::Command;
using std::map;

namespace calculator {

class ClearCommand : public Command {

private:
    map<string, double>& variables;

public:
    ClearCommand(Messenger& messenger, map<string, double>& variables);

public:
    void execute(vector<string>& arguments) const override;
};

}
