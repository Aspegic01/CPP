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

bool RPN::isOperator(const std::string &token) const
{
    return token == "+" ||
           token == "-" ||
           token == "*" ||
           token == "/";
}

void RPN::pushNumber(const std::string &token)
{
    char *end;
    long number = std::strtol(token.c_str(), &end, 10);

    if (*end != '\0')
        throw std::runtime_error("Error: invalid token.");

    _stack.push(static_cast<int>(number));
}

void RPN::performOperation(char op)
{
    if (_stack.size() < 2) 
        throw std::runtime_error("Error: not enough operands.");

    int b = _stack.top();
    _stack.pop();

    int a = _stack.top();
    _stack.pop();

    if (op == '+')
        _stack.push(a + b);
    else if (op == '-')
        _stack.push(a - b);
    else if (op == '*')
        _stack.push(a * b);
    else if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero.");

        _stack.push(a / b);
    }
}

void RPN::calculate(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
            performOperation(token[0]);
        else
            pushNumber(token);
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression.");

    std::cout << _stack.top() << std::endl;
}