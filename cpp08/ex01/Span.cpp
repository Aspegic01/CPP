#include "Span.hpp"

Span::Span(): _n(0), _elements() {}
Span::Span(unsigned int n): _n(n), _elements() {}
Span::Span(const Span &other): _n(other._n), _elements(other._elements) {}
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _elements = other._elements;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int number) {
    if (_elements.size() >= _n)
        throw SpanFullException();
    _elements.push_back(number);
}

unsigned int Span::shortestSpan() {
    if (_elements.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _elements;
    std::sort(sorted.begin(), sorted.end());

    int minDiff = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int currentDiff = sorted[i + 1] - sorted[i];
        if (currentDiff < minDiff)
            minDiff = currentDiff;
    }
    return minDiff;
}

unsigned int Span::longestSpan() {
    if (_elements.size() < 2)
        throw NoSpanException();
    std::vector<int> sortedElements = _elements;
    std::sort(sortedElements.begin(), sortedElements.end());
    return sortedElements.back() - sortedElements.front();
}

const char *Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers.";
}

const char *Span::NoSpanException::what() const throw() {
    return "Not enough elements to form a span.";
}