#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/factory/bfs_iterator_factory.h"
#include "./iterator/factory/dfs_iterator_factory.h"
#include "./visitor/shape_visitor.h"

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
        std::ostringstream msg;    
        msg << "Rectangle (" << _lengthVec->info() << ", " << _widthVec->info() << ")";
        return msg.str();
    }

    Iterator* createIterator(IteratorFactory *factory) override{
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

        Point *theFourth;

        // _lengthVec->a();   
        // _lengthVec->b();   
        // _widthVec->a();   
        // _widthVec->b();

        /*
            1.先找相同的點
            2.不相同的兩點相加
            3. 2的結果扣掉1的結果
        */
    
        if (_lengthVec->a() == _widthVec->a())
        {
            //_lengthVec->b() + _widthVec->b()  - _widthVec->a();
            double x = _lengthVec->b()->x() + _widthVec->b()->x();
            double y = _lengthVec->b()->y() + _widthVec->b()->y();
            x = x - _lengthVec->a()->x();
            y = y - _lengthVec->a()->y();
            theFourth = new Point(x,y);
        }
        if (_lengthVec->a() == _widthVec->b())
        {
            double x = _lengthVec->b()->x() + _widthVec->a()->x();
            double y = _lengthVec->b()->y() + _widthVec->a()->y();
            x = x - _lengthVec->a()->x();
            y = y - _lengthVec->a()->y();
            theFourth = new Point(x,y);
        }
        if (_lengthVec->b() == _widthVec->a())
        {
            double x = _lengthVec->a()->x() + _widthVec->b()->x();
            double y = _lengthVec->a()->y() + _widthVec->b()->y();
            x = x - _lengthVec->b()->x();
            y = y - _lengthVec->b()->y();
            theFourth = new Point(x,y);
        }
        if (_lengthVec->b() == _widthVec->b())
        {
            double x = _lengthVec->a()->x() + _widthVec->a()->x();
            double y = _lengthVec->a()->y() + _widthVec->a()->y();
            x = x - _lengthVec->b()->x();
            y = y - _lengthVec->b()->y();
            theFourth = new Point(x,y);
        }

        Points.insert(_lengthVec->a());
        Points.insert(_lengthVec->b());
        Points.insert(_widthVec->a());
        Points.insert(_widthVec->b());
        Points.insert(theFourth);
        return Points;
    }

    void accept(ShapeVisitor* visitor) 
    {
        visitor->visitRectangle(this);
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