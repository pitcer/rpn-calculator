#include "EvaluatorException.hpp"

using calculator::EvaluatorException;

EvaluatorException::EvaluatorException(string cause) :
    cause(cause) { }

const char* EvaluatorException::what() const noexcept {
    return this->cause.c_str();
}

string EvaluatorException::getCause() {
    return this->cause;
}
