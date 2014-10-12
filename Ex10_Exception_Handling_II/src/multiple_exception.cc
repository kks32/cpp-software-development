#include <iostream>

double calculator(const double N1, const double N2, const char p);

int main() {
    double operand1, operand2, result;
    char operator_;

    std::cout << "This program allows you to perform a division of two numbers" << std::endl;

    try {
	
        std::cout << "To proceed, enter" << std::endl;
        std::cout << "First Number: ";  std::cin >> operand1;
        std::cout << "An Operator: ";   std::cin >> operator_;
        std::cout << "Second Number: "; std::cin >> operand2;

        // Make sure the user typed a valid operator
        if(operator_ != '+' && operator_ != '-' &&
           operator_ != '*' && operator_ != '/')
            throw operator_;

        // Find out if the denominator is 0
        if(operator_ == '/')
            if(operand2 == 0)
                throw 0;

        result = calculator(operand1, operand2, operator_);

        // Move this outside the try block and see what happens
        std::cout << operand1 << " " << operator_ << " "
                  << operand2 << " = " << result;
        
        std::cout << std::endl;
    }
    catch(const char n) {
        std::cout << "Operation Error: " << n << " is not a valid operator" << std::endl;
    }
    catch(const int p) {
        std::cout << "Bad Operation: Division by " << p << " not allowed" << std::endl;
    }

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
