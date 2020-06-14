#include "ParserException.hpp"

using calculator::ParserException;

ParserException::ParserException(string cause) :
    cause(cause) { }

const char* ParserException::what() const noexcept {
    return this->cause.c_str();
}

string ParserException::getCause() {
    return this->cause;
}
