#pragma once

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace calculator {

class EvaluatorException : public exception {

private:
    string cause;

public:
    EvaluatorException(string cause);

public:
    const char* what() const noexcept;

    string getCause();
};

}
