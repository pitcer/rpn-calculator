#include "Messenger.hpp"

using calculator::Messenger;

Messenger::Messenger(istream& input_stream, ostream& output_stream, ostream& error_output_stream) :
    input_stream(input_stream),
    output_stream(output_stream),
    error_output_stream(error_output_stream) { }

void Messenger::receive(char& character) {
    this->input_stream.get(character);
}

void Messenger::send(string message) {
    this->output_stream << message;
}

void Messenger::sendLine(string message) {
    this->output_stream << message << '\n';
}

void Messenger::sendError(string error_message) {
    this->error_output_stream << error_message;
}

void Messenger::sendErrorLine(string error_message) {
    this->error_output_stream << error_message << '\n';
}
