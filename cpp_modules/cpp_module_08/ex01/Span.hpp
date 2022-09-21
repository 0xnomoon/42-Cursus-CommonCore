#ifndef SPAN_H
#define SPAN_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>


class Span {
    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(unsigned int n);
        void fullingVctRdNb();
        unsigned int shortestSpan();
        unsigned int longestSpan();
    private:
        std::vector<unsigned int> _vect;
};

#endif