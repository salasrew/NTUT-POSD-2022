#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"


#define PI acos(-1)
// #define PI 3.14

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;

public:
    Circle(TwoDimensionalVector *radiusVec) 
    {
        _radiusVec = radiusVec;
    }
    ~Circle() {}

    double radius() const 
    {
        return _radiusVec->length();
    }

    double area() const override 
    {
        return this->radius() * this->radius() * PI;
    }

    double perimeter() const override 
    {
        return 2 * this->radius() * PI;
    }

    // (new Circle(
    // new TwoDimensionalVector(Point(-4.284, 0.264), Point(-4.827, 0.728))))->info();
    // "Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))"


    std::string info() const override 
    {
        std::ostringstream msg;    
        // << std::setprecision(2) std::fixed <<
        msg << "Circle (" << _radiusVec->info() << ")";
        return msg.str();
    }
};