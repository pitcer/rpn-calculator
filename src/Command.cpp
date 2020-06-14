#include "Command.hpp"

using calculator::Command;

Command::Command(string name, Messenger& messenger) :
    name(name),
    messenger(messenger) { }
