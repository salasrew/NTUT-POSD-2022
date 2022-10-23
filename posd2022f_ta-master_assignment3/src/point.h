#pragma once

#include <cmath>
#include <sstream>

class Point
{
private:
    const double _x;
    const double _y;

public:
    Point(double x, double y): _x(x), _y(y) {}
    ~Point() {}

    double x() const 
    {
        return _x;
    }

    double y() const 
    {
        return _y;
    }

    bool operator==(const Point &pt) const 
    {
        return (round(_x *100)/100 == round(pt.x() *100)/100) && (round(_y *100)/100 == round(pt.y() *100)/100);
    }

    std::string info() const 
    {
        std::ostringstream msg;
        msg << "("<< round(_x *100)/100 << ", " << round(_y *100)/100 << ")";
        return msg.str();
    }
};
