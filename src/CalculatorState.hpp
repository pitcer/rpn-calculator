#pragma once

namespace calculator {

class CalculatorState {

private:
    bool enabled;

public:
    CalculatorState(bool enabled);

public:
    bool isEnabled();

    void disable();
};

}
