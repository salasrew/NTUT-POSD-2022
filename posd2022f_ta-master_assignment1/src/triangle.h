#pragma once
#include <iostream>
#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

    // TwoDimensionalVector *_v3;

public:


    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) 
    {
        _v1 = v1;
        _v2 = v2;

        // 外積等於0 平行
        if((_v1->cross(_v2) == 0)||(_v1->length()==0)||(_v2->length()==0))
        {
            throw "Not A Triangle";
        }

        // _v1->a()->x() _v1->a()->y()
        // _v1->b()->x() _v1->b()->y()
        // _v2->a()->x() _v2->a()->y()
        // _v2->b()->x() _v2->b()->y()

        if( ((_v1->a()->x() == _v2->a()->x()) &&  (_v1->a()->y() == _v2->a()->y()) ) ||
            ((_v1->a()->x() == _v2->b()->x()) &&  (_v1->a()->y() == _v2->b()->y()) ) ||
            ((_v1->b()->x() == _v2->a()->x()) &&  (_v1->b()->y() == _v2->a()->y()) ) ||
            ((_v1->b()->x() == _v2->b()->x()) &&  (_v1->b()->y() == _v2->b()->y()) ) ){}

        else
        {
            throw "Not A Triangle";
        }


    }
    ~Triangle() {}

    double area() const override 
    {
        // s = ( a + b + c) / 2;
        // area = sqrt ( s * (s‐a) * (s‐b) * (s‐c) );
        // 前面物件 . 前面是指標
        return abs(_v1->cross(_v2)/2 );

 
    }

    // 周長
    double perimeter() const override 
    {
        TwoDimensionalVector *_v3;

        if ( _v1->a() == _v2->a())
        {
            _v3 = new TwoDimensionalVector(_v1->b(), _v2->b());
        }
        if (_v1->a() == _v2->b())
        {
            _v3 = new TwoDimensionalVector(_v1->b(), _v2->a());
        }
        if (_v1->b() == _v2->a())
        {
            _v3 = new TwoDimensionalVector(_v1->a(), _v2->b());
        }
        if (_v1->b() == _v2->b())
        {
            _v3 = new TwoDimensionalVector(_v1->a(), _v2->a());
        }

        return _v1->length() + _v2->length() + _v3->length();
    }

    std::string info() const override 
    {
        // "Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))"
        std::ostringstream msg;    
        // << std::setprecision(2) std::fixed <<
        msg << "Triangle (" << _v1->info() << ", " << _v2->info() << ")";
        return msg.str();
    }
};