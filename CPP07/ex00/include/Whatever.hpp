#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &num1, T &num2) {
    T tmp = num1;
    num1 = num2;
    num2 = tmp;
}

template <typename T>
T const & min(T const &num1, T const &num2) {
    return (num1 < num2 ? num1 : num2);
}

template <typename T>
T const & max(T const &num1, T const &num2) {
    return (num1 > num2 ? num1 : num2);
}

#endif