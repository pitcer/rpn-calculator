#pragma once

#include "Messenger.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace calculator {

class Command {

protected:
    string name;
    Messenger& messenger;

public:
    Command(string name, Messenger& messenger);

public:
    virtual void execute(vector<string>& arguments) const = 0;
};

}
