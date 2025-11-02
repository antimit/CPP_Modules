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

    int getRawBits(void ) const;
    void setRawBits(int const raw);
    float toFloat()const;
    int toInt(void)const;


    private:
    int value;
    static const int bits = 8;
};

std::ostream & operator<<(std::ostream & out, Fixed const & value);