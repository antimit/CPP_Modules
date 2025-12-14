#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), size_(0)
{
    std::cout << "Array default constructor was called" << std::endl;
}


template <typename T>
unsigned int Array<T>::size() const
{
    return this->size_;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), size_(n)
{
    std::cout << "Array constructor was called" << std::endl;
    this->array = new T[n]();
}

template <typename T>
Array<T>::Array(Array const &src) : array(NULL), size_(0)
{
    std::cout << "copy constructor was called" << std::endl;

    this->array = new T[src.size()]();
    for (unsigned int i = 0; i < src.size(); i++)
    {
        this->array[i] = src.array[i];
    }
    this->size_ = src.size_;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->array;
        this->array = new T[other.size()]();
        for (unsigned int i = 0; i < other.size(); i++)
        {
            this->array[i] = other.array[i];
        }
        this->size_ = other.size_;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor was called" << std::endl;
    delete[] this->array;
}

template <typename T>
T & Array<T>::operator[](unsigned int i)
{
    if (i >= this->size_)
        throw OutOfRange();
    return this->array[i];
}

template <typename T>
T const & Array<T>::operator[](unsigned int i) const
{
    if (i >= this->size_)
        throw OutOfRange();
    return this->array[i];
}

template <typename T>
const char * Array<T>::OutOfRange::what() const throw()
{
    return "Index is out of range";
}