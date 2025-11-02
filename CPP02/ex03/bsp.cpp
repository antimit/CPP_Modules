#include "Point.hpp"

static float cross(Point const &p1, Point const &p2, Point const &p3)
{
    float x1 = p2.get_x().toFloat() - p1.get_x().toFloat();
    float y1 = p2.get_y().toFloat() - p1.get_y().toFloat();
    float x2 = p3.get_x().toFloat() - p1.get_x().toFloat();
    float y2 = p3.get_y().toFloat() - p1.get_y().toFloat();

    return x1 * y2 - y1 * x2;
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
    float c1 = cross(a, b, point);
    float c2 = cross(b, c, point);
    float c3 = cross(c, a, point);

    if (c1 == 0.0f || c2 == 0.0f || c3 == 0.0f)
        return false;

    bool hasPos = (c1 > 0.0f) || (c2 > 0.0f) || (c3 > 0.0f);
    bool hasNeg = (c1 < 0.0f) || (c2 < 0.0f) || (c3 < 0.0f);
    
    return !(hasPos && hasNeg);

}