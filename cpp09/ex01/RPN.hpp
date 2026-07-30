#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>
#include <string>

class RPN {
private:
	std::stack<int> _stack;
	bool isOperator(const std::string &token) const;
	void pushNumber(const std::string &token);
	void performOperation(const char c);
public:
	RPN();
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN();
	void calculate(const std::string &input);
};

#endif