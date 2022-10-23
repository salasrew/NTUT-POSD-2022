#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"
#include "./iterator/null_iterator.h"

// #define PI acos(-1)


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
        return this->radius() * this->radius() * M_PI ;
    }

    Iterator* createDFSIterator() override 
    {
        return new NullIterator();
    }

    Iterator* createBFSIterator() override 
    {
        return new NullIterator();
    }
    double perimeter() const override 
    {
        return 2 * this->radius() * M_PI;
    }

    std::string info() const override 
    {
        std::ostringstream msg;    
        msg << "Circle (" << _radiusVec->info() << ")";
        return msg.str();
    }
    void addShape(Shape *shape) override 
    {
        throw "error";
    }
    void deleteShape(Shape *shape) override 
    {
        throw "error";
    }
    
    bool isCompound() const override 
    {
        return false;
    }


};