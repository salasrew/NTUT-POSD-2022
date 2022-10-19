#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;

public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) 
    {
        _lengthVec = lengthVec;
        _widthVec = widthVec;

        /*
            _lengthVec->a();
            _lengthVec->b();
            _widthVec->a();
            _widthVec->b();
        */
        // if (!( (_lengthVec->a() == _widthVec->a()) || (_lengthVec->b() == _widthVec->b()) || (_lengthVec->a() != _widthVec->b()) || (_lengthVec->b() != _widthVec->a()) ))
        // {
        //     throw "Not A Rectangle!";
        // } 

        if (!(_lengthVec->dot(_widthVec) == 0))
        {
            throw "Not A Rectangle!";
        }


    }
    ~Rectangle() {}

    double length() const 
    {
        return _lengthVec->length();
    }

    double width() const 
    {
        return _widthVec->length();
    }

    double area() const override 
    {
        return this->length() * this->width();
    }

    double perimeter() const override 
    {
        return 2 * ( this->length() + this->width() );

    }

    std::string info() const override 
    {
        //"Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))"
        std::ostringstream msg;    
        msg << "Rectangle (" << _lengthVec->info() << ", " << _widthVec->info() << ")";
        return msg.str();

    }
};