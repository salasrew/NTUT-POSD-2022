#pragma once

#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
// #include <gtest/gtest.h>

class Point
{
    private:
        const double _x;
        const double _y;

    public:
        Point(double x, double y): _x(x), _y(y) {}

        // 解構子
        ~Point() {}

        double x() const 
        {
            // return round(_x *100)/100 ;
            return _x;

        }

        double y() const 
        {
            // return round(_y *100)/100 ;
            return _y;

        }

        // overloading
        bool operator==(const Point &pt) const 
        {
            return (round(_x *100)/100 == round(pt.x() *100)/100) && (round(_y *100)/100 == round(pt.y() *100)/100);
        }

        std::string info() const 
        {
            // "(-4.59, -3.47)"
            std::ostringstream msg;
            msg << "("<< round(_x *100)/100 << ", " << round(_y *100)/100 << ")";
            return msg.str();
        }
};
