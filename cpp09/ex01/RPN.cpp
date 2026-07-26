#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) {
    *this = other;
}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}
bool RPN::isOperator(const char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void RPN::performOperation(const char c) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough operands.");
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
    switch (c) {
        case '+':
            _stack.push(a + b);
            break;
        case '-':
            _stack.push(a - b);
            break;
        case '*':
            _stack.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero.");
            _stack.push(a / b);
            break;
    }
}

void RPN::calculate(const std::string &input) {
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            performOperation(token[0]);
        } else {
            char *end;
            long num = strtol(token.c_str(), &end, 10);
            if (*end != '\0')
                throw std::runtime_error("Error: invalid token.");
            _stack.push(static_cast<int>(num));
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression.");
    std::cout << _stack.top() << std::endl;
}