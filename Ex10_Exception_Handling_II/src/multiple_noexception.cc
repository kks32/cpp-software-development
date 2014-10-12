#include <iostream>

double calculator(const double N1, const double N2, const char p);

int main() {
    double operand1, operand2, result;
    char operator_;

    std::cout << "This program allows you to perform a division of two numbers" << std::endl;
    std::cout << "To proceed, enter" << std::endl;
    std::cout << "First Number: ";  std::cin >> operand1;
    std::cout << "An Operator: ";   std::cin >> operator_;
    std::cout << "Second Number: "; std::cin >> operand2;


    result = calculator(operand1, operand2, operator_);

    std::cout << operand1 << " " << operator_ << " "
              << operand2 << " = " << result;

    std::cout << std::endl;
    return 0;
}

double calculator(const double oper1, const double oper2, const char symbol) {
    double value;

    switch(symbol) {
    case '+':
        value = oper1 + oper2;
        break;

    case '-':
        value = oper1 - oper2;
        break;

    case '*':
        value = oper1 * oper2;
        break;

    case '/':
        value = oper1 / oper2;
        break;
    }

    return value;
}
