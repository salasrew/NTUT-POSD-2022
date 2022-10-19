#pragma once
// #include "iterator/iterator.h"

#include "./iterator/bfs_compound_iterator.h"
#include "./iterator/dfs_compound_iterator.h"


class Shape
{
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual std::string info() const = 0;
        virtual Iterator *createDFSIterator() = 0;
        virtual Iterator *createBFSIterator() = 0;
        virtual void addShape(Shape *shape) = 0;
        virtual void deleteShape(Shape *shape) = 0;

        virtual bool isCompound() const = 0;

};