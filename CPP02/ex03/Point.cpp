#include "Point.hpp"

Point::Point(float x, float y) :_x(x), _y(y)
{
    
}

Point::Point(): _x(0), _y(0)
{

}

Point &Point::operator=(Point const &rhs)
{
    (void ) rhs;
    return *this;
}

//setters
 Fixed const & Point::get_x() const
 {
    return this->_x;
 }
Fixed const & Point::get_y() const
{   
    return this->_y;
}


Point::~Point()
{
}

