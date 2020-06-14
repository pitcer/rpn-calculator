#include "AssignCommand.hpp"

#include "EvaluatorException.hpp"
#include "ParserException.hpp"

using calculator::AssignCommand;
using calculator::Evaluator;
using calculator::EvaluatorException;
using calculator::Parser;
using calculator::ParserException;

AssignCommand::AssignCommand(Messenger& messenger, map<string, double>& variables, Parser& parser, Evaluator& evaluator) :
    Command("assign", messenger),
    variables(variables),
    parser(parser),
    evaluator(evaluator) { }

void AssignCommand::execute(vector<string>& arguments) const {
    vector<string> syntax;
    string variable_name;
    for (size_t index = 0; index < arguments.size(); index++) {
        string& argument = arguments[index];
        if (argument == "to") {
            variable_name = arguments[index + 1];
            break;
        } else {
            syntax.push_back(argument);
        }
    }
    try {
        vector<shared_ptr<Symbol>> symbols = this->parser.parse(syntax);
        double value = this->evaluator.evaluate(symbols);
        this->variables.insert({ variable_name, value });
        this->messenger.sendLine("Value " + std::to_string(value) + " assigned to variable named '" + variable_name + "'.");
    } catch (ParserException& exception) {
        this->messenger.sendErrorLine("An error occurred during parsing: " + exception.getCause());
    } catch (EvaluatorException& exception) {
        this->messenger.sendErrorLine("An error occurred during evaluation: " + exception.getCause());
    }
}
