#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template<typename T>
class Array
{
    public:
    Array();
    Array(unsigned int n);
    Array(Array const & src);
    ~Array();
    Array & operator=(Array const & src);

    unsigned int size() const;
    T & operator[](unsigned int i);
    T const & operator[](unsigned int i) const;

    class OutOfRange : public std::exception
    {
        public:
        const char *what() const throw();
    };


    private:
    T * array;
    unsigned int size_;

};


#include "Array.tpp"
#endif