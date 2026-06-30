#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <limits>

class Span{
private:
	unsigned int _n;
	std::vector<int> _elements;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	template <typename T>
	void addRange(T begin, T end) {
		if (std::distance(begin, end) + _elements.size() > _n)
			throw SpanFullException();
		_elements.insert(_elements.end(), begin, end);
	}
	class SpanFullException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
#endif