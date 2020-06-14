#include "PrintCommand.hpp"

#include "EvaluatorException.hpp"
#include "ParserException.hpp"

using calculator::Evaluator;
using calculator::EvaluatorException;
using calculator::Parser;
using calculator::ParserException;
using calculator::PrintCommand;

PrintCommand::PrintCommand(Messenger& messenger, Parser& parser, Evaluator& evaluator) :
    Command("print", messenger),
    parser(parser),
    evaluator(evaluator) { }

void PrintCommand::execute(vector<string>& arguments) const {
    try {
        vector<shared_ptr<Symbol>> symbols = this->parser.parse(arguments);
        double value = this->evaluator.evaluate(symbols);
        string value_string = std::to_string(value);
        this->messenger.sendLine(value_string);
    } catch (ParserException& exception) {
        this->messenger.sendErrorLine("An error occurred during parsing: " + exception.getCause());
    } catch (EvaluatorException& exception) {
        this->messenger.sendErrorLine("An error occurred during evaluation: " + exception.getCause());
    }
}
