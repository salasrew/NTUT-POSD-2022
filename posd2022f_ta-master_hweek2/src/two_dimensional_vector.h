#pragma once
#include <cmath>
#include "point.h"

class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b): _a(a),_b(b){}
    ~TwoDimensionalVector() {}

    const Point *a() const 
    {
        return _a;
    }

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
        double temp_x = _b->x() -  _a->x();
        double temp_y = _b->y() -  _a->y();

        double temp_x2 = vec->_b->x() - vec->_a->x() ;
        double temp_y2 = vec->_b->y() - vec->_a->y() ;

        double dots = temp_x * temp_x2 + temp_y * temp_y2;

        return dots;
    }

    double cross(const TwoDimensionalVector *vec) const 
    {
        double temp_x = _b->x() -  _a->x();
        double temp_y = _b->y() -  _a->y();

        double temp_x2 = vec->_b->x() - vec->_a->x() ;
        double temp_y2 = vec->_b->y() - vec->_a->y() ;

        double croz = temp_x * temp_y2 - temp_y * temp_x2;

        return croz;
    }

    std::string info() const 
    {
        std::ostringstream msg;    
        msg <<std::setprecision(2) << std::fixed <<"Vector (("  << _a->x() << ", " << _a->y() << "), (" << _b->x() << ", " << _b->y() << "))";
        return msg.str();
    }
};