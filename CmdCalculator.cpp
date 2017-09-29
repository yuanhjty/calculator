#include "CalculatorManager.h"
#include "Calculator.h"
#include "Util.h"

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>


int main() {
    std::shared_ptr<CalculatorManager> calculatorManager(
                new CalculatorManager);

//    Util::printWelcome();
    std::cout << "toy-calculator 0.1\n"
              << "Type expressions to be evaluated\n"
              << "Type 'q' to quit.\n\n";

    // main loop
    while (true) {
        std::cout << ">> ";             // Output prompt.

        std::string line;
        std::getline(std::cin, line);   // Get input(could be a command or infix expression).

        if (!std::cin.good()) {
            std::cout << "Sorry! It seems something wrong, please try again!" << std::endl;
            continue;
        }

        line = Util::trimEndsSpaces(line);
        if (line.empty())
            continue;
        if (line == "q" || line == "Q")
            break;

        calculatorManager->processInput(line);

//        Util::printResult(calculatorManager->getExpression(), calculatorManager->getResult());
        std::cout << "   " << std::string(40, '_')
                  << "\n   " << calculatorManager->showResult()
                  << "\n   " << std::string(40, '_') << "\n\n";
    }

    return 0;
}
