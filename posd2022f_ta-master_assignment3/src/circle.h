#pragma once

#include <string>
#include <cmath>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"


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
        // AABB max
        Point *upperRight;
        // AABB min
        Point *lowerLeft;
        // radius of circle
        double radius = _radiusVec->length();

        // new Set
        std::set<const Point*> Points{};

        upperRight = new Point(_radiusVec->a()->x() + radius, _radiusVec->a()->y() + radius );
        lowerLeft = new Point(_radiusVec->a()->x() - radius , _radiusVec->a()->y() - radius );

        Points.insert(upperRight);
        Points.insert(lowerLeft);

        return Points;
    }

    void accept(ShapeVisitor* visitor) 
    {
        visitor->visitCircle(this);
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