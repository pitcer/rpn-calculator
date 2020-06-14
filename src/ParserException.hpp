#pragma once

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace calculator {

class ParserException : public exception {

private:
    string cause;

public:
    ParserException(string cause);

public:
    const char* what() const noexcept;
    string getCause();
};

}
