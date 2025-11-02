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

Fixed::Fixed(const int value)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->value = value<<Fixed::bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int> (roundf(value*(1<<Fixed::bits)));
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

float Fixed::toFloat(void )const
{   
    return static_cast<float>(this->value) / static_cast<float>(1<<Fixed::bits);
} 

int Fixed::toInt(void)const
{
    return this->value >> bits;
}



Fixed::~Fixed()
{
    std::cout<<"Destructor called" <<std::endl;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) {
	o << rSym.toFloat();
	return o;
}
