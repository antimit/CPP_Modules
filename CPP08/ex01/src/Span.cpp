#include "Span.hpp"

Span::Span() : _maxSize(0) {
}

Span::Span(unsigned int n) : _maxSize(n) {
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanFoundException();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanFoundException();
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

unsigned int Span::getSize() const {
    return _numbers.size();
}

unsigned int Span::getMaxSize() const {
    return _maxSize;
}

const char *Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char *Span::NoSpanFoundException::what() const throw() {
    return "No span can be found (need at least 2 numbers)";
}
