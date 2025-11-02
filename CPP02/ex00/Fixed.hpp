
#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(Fixed const & src);
    ~Fixed();

    Fixed& operator=(Fixed const & rSym);
    int getRawBits(void ) const;
    void setRawBits(int const raw);

    private:
    int value;
    static const int bits;
};