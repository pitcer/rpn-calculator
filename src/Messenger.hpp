#pragma once

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

namespace calculator {

class Messenger {

private:
    istream& input_stream;
    ostream& output_stream;
    ostream& error_output_stream;

public:
    Messenger(istream& input_stream, ostream& output_stream, ostream& error_output_stream);

public:
    void receive(char& character);
    void send(string message);
    void sendLine(string message);
    void sendError(string error);
    void sendErrorLine(string error);
};

}
