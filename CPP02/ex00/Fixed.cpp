#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout<<"Default constructor called" <<std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = src;
}

Fixed & Fixed::operator=(Fixed const & rSym)
{
    std::cout<<"Copy assignment operator called" <<std::endl;
    this->value = rSym.getRawBits();
    return *this;
}


int Fixed::getRawBits()const
{
    std::cout<<"getRawBits member function called" <<std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called" <<std::endl;
}

const int Fixed::bits = 8; 