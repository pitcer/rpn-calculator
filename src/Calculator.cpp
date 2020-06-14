#include "Calculator.hpp"

#include "AssignCommand.hpp"
#include "ClearCommand.hpp"
#include "ExitCommand.hpp"
#include "PrintCommand.hpp"

using calculator::Calculator;

Calculator::Calculator(Messenger& messenger) :
    messenger(messenger),
    state(true),
    variables(),
    parser(this->variables),
    evaluator(this->variables),
    commands {
        { "print", std::make_shared<PrintCommand>(messenger, this->parser, this->evaluator) },
        { "assign", std::make_shared<AssignCommand>(messenger, this->variables, this->parser, this->evaluator) },
        { "clear", std::make_shared<ClearCommand>(messenger, this->variables) },
        { "exit", std::make_shared<ExitCommand>(messenger, this->state) }
    } {}

void Calculator::run() {
    while (this->state.isEnabled()) {
        this->messenger.send("$ ");
        vector<string> words = readWords();
        string command_name = words.front();
        shared_ptr<Command> command = this->commands[command_name];
        if (command == nullptr) {
            this->messenger.sendErrorLine("Unknown command: " + command_name);
        } else {
            words.erase(words.begin());
            command->execute(words);
        }
    }
}

vector<string> Calculator::readWords() {
    vector<string> words;
    string current_string;
    char current_character;
    this->messenger.receive(current_character);
    while (current_character != '\n') {
        if (current_character == ' ' && !current_string.empty()) {
            words.push_back(current_string);
            current_string.clear();
        } else {
            current_string += current_character;
        }
        this->messenger.receive(current_character);
    }
    words.push_back(current_string);
    return words;
}
