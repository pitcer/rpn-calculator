#include "Parser.hpp"

#include "ParserException.hpp"
#include "Variable.hpp"
#include <algorithm>
#include <cmath>
#include <numbers>
#include <set>

using calculator::Constant;
using calculator::Function;
using calculator::Number;
using calculator::Parser;
using calculator::ParserException;
using calculator::Symbol;
using calculator::Variable;
using std::invalid_argument;
using std::out_of_range;
using std::set;

static const set<string> COMMAND_NAMES { "print", "assign", "to", "clear", "exit" };

Parser::Parser(map<string, double>& variables) :
    constants {
        { "e", std::make_shared<Constant>("e", M_E) },
        { "pi", std::make_shared<Constant>("pi", M_PI) },
        { "fi", std::make_shared<Constant>("fi", 1.618033988750) }
    },
    functions {
        { "+", std::make_shared<Function>("+", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return first_value + second_value;
         }) },
        { "-", std::make_shared<Function>("-", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return first_value - second_value;
         }) },
        { "*", std::make_shared<Function>("*", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return first_value * second_value;
         }) },
        { "/", std::make_shared<Function>("/", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return first_value / second_value;
         }) },
        { "modulo", std::make_shared<Function>("modulo", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return std::fmod(first_value, second_value);
         }) },
        { "min", std::make_shared<Function>("min", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return std::min(first_value, second_value);
         }) },
        { "max", std::make_shared<Function>("max", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return std::max(first_value, second_value);
         }) },
        { "log", std::make_shared<Function>("log", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return std::log(first_value) / std::log(second_value);
         }) },
        { "pow", std::make_shared<Function>("pow", [&](auto& environment) {
             double second_value = environment.popValue();
             double first_value = environment.popValue();
             return std::pow(first_value, second_value);
         }) },
        { "abs", std::make_shared<Function>("abs", [&](auto& environment) { return std::abs(environment.popValue()); }) },
        { "sgn", std::make_shared<Function>("sgn", [&](auto& environment) {
             double value = environment.popValue();
             if (value > 0) {
                 return 1;
             } else if (value == 0) {
                 return 0;
             } else {
                 return -1;
             }
         }) },
        { "floor", std::make_shared<Function>("floor", [&](auto& environment) { return std::floor(environment.popValue()); }) },
        { "ceil", std::make_shared<Function>("ceil", [&](auto& environment) { return std::ceil(environment.popValue()); }) },
        { "frac", std::make_shared<Function>("frac", [&](auto& environment) {
             double value = environment.popValue();
             if (value >= 0) {
                 return value - std::floor(value);
             } else {
                 return value - std::ceil(value);
             }
         }) },
        { "sin", std::make_shared<Function>("sin", [&](auto& environment) { return std::sin(environment.popValue()); }) },
        { "cos", std::make_shared<Function>("cos", [&](auto& environment) { return std::cos(environment.popValue()); }) },
        { "atan", std::make_shared<Function>("atan", [&](auto& environment) { return std::atan(environment.popValue()); }) },
        { "acot", std::make_shared<Function>("acot", [&](auto& environment) { return M_PI / 2 - std::atan(environment.popValue()); }) },
        { "ln", std::make_shared<Function>("ln", [&](auto& environment) { return std::log(environment.popValue()); }) },
        { "exp", std::make_shared<Function>("exp", [&](auto& environment) { return std::exp(environment.popValue()); }) },
    },
    variables(variables) { }

vector<shared_ptr<Symbol>> Parser::parse(vector<string>& syntax_list) {
    vector<shared_ptr<Symbol>> symbols;
    for (string& argument : syntax_list) {
        shared_ptr<Symbol> symbol = parse(argument);
        symbols.push_back(symbol);
    }
    return symbols;
}

shared_ptr<Symbol> Parser::parse(string syntax) {
    auto constant_result = this->constants.find(syntax);
    if (constant_result != this->constants.end()) {
        return constant_result->second;
    }
    auto function_result = this->functions.find(syntax);
    if (function_result != this->functions.end()) {
        return function_result->second;
    }
    try {
        double value = std::stod(syntax);
        return std::make_shared<Number>(value);
    } catch (invalid_argument& exception) {
        if (!isVariableValid(syntax)) {
            throw ParserException("Invalid variable name: " + syntax);
        }
        return std::make_shared<Variable>(syntax);
    } catch (out_of_range& exception) {
        throw ParserException("Invalid numeric value length");
    }
}

bool Parser::isVariableValid(string name) {
    return name.length() <= 7 && COMMAND_NAMES.find(name) == COMMAND_NAMES.end();
}
