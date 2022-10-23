#pragma once

#include <cmath>
#include "point.h"
#include "iostream"


class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:

    // Point(double x, double y): _x(x), _y(y) {}

    TwoDimensionalVector(const Point *a, const Point *b): _a(a),_b(b){}
    ~TwoDimensionalVector() {}

    // (x1 , y1)
    const Point *a() const 
    {
        return _a;
    }

    // (x2, y2)
    const Point *b() const 
    {
        return _b;
    }

    double length() const 
    {
        return sqrt( (_a->x() - _b->x())*(_a->x() - _b->x()) + (_a->y() - _b->y())*(_a->y() - _b->y()) );
    }

    double dot(const TwoDimensionalVector *vec) const 
    {
        // this向量 = (_b.x - _a.x ,_b.y - _a.y )
        // vec向量 = (vec._b.x - vec._a.x ,vec._b.y - vec._a.y )
        // x1x2 + y1y2
        // return vec->_a->x() * vec->_b->x() + vec->_a->y() * vec->_b->y();

        double temp_x = _b->x() -  _a->x();
        double temp_y = _b->y() -  _a->y();

        double temp_x2 = vec->_b->x() - vec->_a->x() ;
        double temp_y2 = vec->_b->y() - vec->_a->y() ;

        double dots = temp_x * temp_x2 + temp_y * temp_y2;

        return dots;

    }

    double cross(const TwoDimensionalVector *vec) const 
    {
        // x1y2 - y1x2
        // return vec->_a->x() * vec->_b->y() - vec->_a->y() * vec->_b->x();
        double temp_x = _b->x() -  _a->x();
        double temp_y = _b->y() -  _a->y();

        double temp_x2 = vec->_b->x() - vec->_a->x() ;
        double temp_y2 = vec->_b->y() - vec->_a->y() ;

        double croz = temp_x * temp_y2 - temp_y * temp_x2;

        return croz;

    }

    std::string info() const  
    {
        // "Vector ((-8.42, 3.42), (-3.38, 4.30))"
        std::ostringstream msg;    
        msg <<std::setprecision(2) << std::fixed <<"Vector (("  << _a->x() << ", " << _a->y() << "), (" << _b->x() << ", " << _b->y() << "))";
        return msg.str();
    }
};