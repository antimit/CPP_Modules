#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;


public:
    Point();
    Point(float x, float y);
    
    Point & operator=(Point const &rhs);
    ~Point();

    //getters
    Fixed const & get_x() const;
    Fixed const & get_y() const;

};


bool bsp(Point const &a, Point const &b, Point const &c, Point const& point);



#endif