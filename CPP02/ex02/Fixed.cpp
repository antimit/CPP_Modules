#include "Fixed.hpp"


Fixed::Fixed(): value(0)
{
}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
}

Fixed::Fixed(const int value)
{
    this->value = value<<bits;
}

Fixed::Fixed(const float value)
{
    this->value = static_cast<int> (roundf(value*(1<<bits)));
}

Fixed & Fixed::operator=(Fixed const & rSym)
{
    this->value = rSym.getRawBits();
    return *this;
}

bool Fixed::operator>(Fixed const & rSym)const
{
   return this->value > rSym.value;
}

bool Fixed::operator<(Fixed const & rSym)const
{
    return this->value < rSym.value;
}

bool Fixed::operator>=(Fixed const & rSym)const
{
    return this->value >= rSym.value;
}

bool Fixed::operator<=(Fixed const & rSym)const
{
    return this->value <= rSym.value;
}

bool Fixed::operator==(Fixed const & rSym)const
{
   return this->value == rSym.value;
}

bool Fixed::operator!=(Fixed const & rSym)const
{
    return this->value != rSym.value;
}

Fixed  Fixed::operator+(Fixed const & rSym) const
{
    return (Fixed(this->toFloat() + rSym.toFloat()));
}

Fixed  Fixed::operator-(Fixed const & rSym) const
{
    return (Fixed(this->toFloat() - rSym.toFloat()));
}

Fixed  Fixed::operator*(Fixed const & rSym) const
{
    return (Fixed(this->toFloat() * rSym.toFloat()));
}

Fixed  Fixed::operator/(Fixed const & rSym) const
{
   return (Fixed(this->toFloat() / rSym.toFloat()));
}

Fixed &Fixed::operator++()
{
    ++this->value;

    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed a = *this;
    this->value++;

    return a;
}

Fixed & Fixed::operator--()
{
    --this->value;
    
    return *this;
}

Fixed  Fixed::operator--(int)
{
    Fixed a = *this;
    this->value--;
    return a;
}

int Fixed::getRawBits()const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void )const
{   
    return static_cast<float>(this->value) / static_cast<float>(1<<bits);
}


int Fixed::toInt(void)const
{
    return this->value >> bits;
}

Fixed::~Fixed()
{
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) {
	o << rSym.toFloat();
	return o;
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    return a.value < b.value ? a : b;
}

Fixed const &Fixed::min(Fixed const&a, Fixed const &b)
{
    return a.value < b.value ? a : b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    return a.value > b.value ? a : b;
}

Fixed const &Fixed::max(Fixed const&a, Fixed const &b)
{
    return a.value > b.value ? a : b;
}