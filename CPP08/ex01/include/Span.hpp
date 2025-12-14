#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);
    
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int getSize() const;
    unsigned int getMaxSize() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NoSpanFoundException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

#endif
