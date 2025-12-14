#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

// Non-const version - for modifying array elements
template<typename T, typename F>
void iter(T *arr, size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

// Const version - for read-only operations on const arrays
template<typename T, typename F>
void iter(T const *arr, size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

#endif