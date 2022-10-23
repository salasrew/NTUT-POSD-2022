#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) 
    {
        _v1 = v1;
        _v2 = v2;

        if((_v1->cross(_v2) == 0)||(_v1->length()==0)||(_v2->length()==0))
        {
            throw "Not A Triangle";
        }

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
        return abs(_v1->cross(_v2)/2 );
    }

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
        std::ostringstream msg;    
        msg << "Triangle (" << _v1->info() << ", " << _v2->info() << ")";
        return msg.str();
    }

    Iterator *createIterator(IteratorFactory *factory) override 
    {
        return new NullIterator();
    }

    Iterator* createDFSIterator() override 
    {
        return new NullIterator();
    }

    Iterator* createBFSIterator() override 
    {
        return new NullIterator();
    }

    std::set<const Point*> getPoints() 
    {
        std::set<const Point*> Points{};
        Points.insert(_v1->a());
        Points.insert(_v1->b());
        Points.insert(_v2->a());
        Points.insert(_v2->b());

        return Points;
    }

    void accept(ShapeVisitor* visitor) 
    {
        visitor->visitTriangle(this);
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