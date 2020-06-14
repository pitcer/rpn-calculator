#include "CalculatorState.hpp"

using calculator::CalculatorState;

CalculatorState::CalculatorState(bool enabled) :
    enabled(enabled) { }

bool CalculatorState::isEnabled() {
    return this->enabled;
}

void CalculatorState::disable() {
    this->enabled = false;
}
