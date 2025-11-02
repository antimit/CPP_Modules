#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(Fixed const & src);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

  //operators
    Fixed& operator=(Fixed const & rSym);
    bool  operator>(Fixed const & rSym)const;
    bool  operator<(Fixed const & rSym)const;
    bool  operator>=(Fixed const & rSym)const;
    bool  operator<=(Fixed const & rSym)const;
    bool  operator==(Fixed const & rSym)const;
    bool  operator!=(Fixed const & rSym)const;

    Fixed  operator+(Fixed const & rSym)const;
    Fixed  operator-(Fixed const & rSym)const;
    Fixed  operator*(Fixed const & rSym)const;
    Fixed  operator/(Fixed const & rSym)const;

    Fixed & operator++();//prefix
    Fixed operator++(int);//postfix

    Fixed & operator--();//prefix
    Fixed  operator--(int);//postfix

    int getRawBits(void ) const;
    void setRawBits(int const raw);

    float toFloat()const;
    int toInt(void)const;


    static Fixed & min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const&a, Fixed const &b);

    static Fixed & max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const&a, Fixed const &b);

   
    private:
    int value;
    static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif