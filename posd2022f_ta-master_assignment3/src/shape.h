#pragma once
#include <string>
#include <set>
#include "./point.h"
#include "./iterator/bfs_compound_iterator.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./visitor/shape_visitor.h"
#include "./visitor/shape_visitor.h"
#include "./iterator/factory/iterator_factory.h"

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual Iterator* createIterator(IteratorFactory * factory) = 0;
    virtual Iterator *createDFSIterator() = 0;
    virtual Iterator *createBFSIterator() = 0;
    virtual std::set<const Point*> getPoints() = 0;
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual void addShape(Shape *shape) = 0;
    virtual void deleteShape(Shape *shape) = 0;

    virtual bool isCompound() const = 0;

};
