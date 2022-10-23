#pragma once

#include <string>
#include <algorithm>
#include <list>
#include <set>

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"
#include "./iterator/list_compound_iterator.h"

#include "./visitor/shape_visitor.h"


class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;

public:
    CompoundShape(){}
    CompoundShape(Shape **shapes, int size) 
        :_shapes(shapes,shapes+size){}

    ~CompoundShape() {}

    double area() const override 
    {
        double result = 0;
        for (auto shape_ptr : _shapes)
        {
            result += shape_ptr->area();
        }
        return result;
    }

    double perimeter() const override 
    {
        double result = 0;
        for (auto shape_ptr : _shapes)
        {
            result += shape_ptr->perimeter();
        }
        return result;
    }

    std::string info() const override 
    {
        std::string infos = "";
        std::ostringstream msg;    
        msg << "CompoundShape (";
        bool u=false;
        for(auto shape_ptr : _shapes)
        {                
            if(u)
            {
                msg << ", ";
            }
            msg << shape_ptr->info();
            u = true;
        }

        infos = msg.str();
        infos.append(")");

        return infos;
    }

    Iterator *createIterator(IteratorFactory *factory) override 
    {
        return factory->createIterator(_shapes.begin(),_shapes.end());
    }
    Iterator* createDFSIterator() override 
    {
        return new DFSCompoundIterator<std::list<Shape *>::const_iterator>(_shapes.begin(),_shapes.end());
    }

    Iterator* createBFSIterator() override 
    {
        return new BFSCompoundIterator<std::list<Shape *>::const_iterator>(_shapes.begin(),_shapes.end());
    }

    std::set<const Point*> getPoints() 
    {
        std::set<const Point*> Points{};
        Iterator *traversal = createDFSIterator();
        
        for(;!traversal->isDone();traversal->next())
        {
            std::set<const Point*> Points2{};
            Points2 = traversal->currentItem()->getPoints();
            Points.insert(Points2.begin(),Points2.end());
        }
        
        return Points;
    }

    void accept(ShapeVisitor* visitor) 
    {
        visitor->visitCompoundShape(this);
    }

    void addShape(Shape *shape) override 
    {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape *shape) override 
    {
        Iterator *itr = createDFSIterator();
        if(!shape->isCompound())
        {
            for(; !itr->isDone(); itr->next())
            {
                if(itr->currentItem()->isCompound())
                {
                    itr->currentItem()->deleteShape(shape);
                }
            }
        }
        _shapes.remove(shape);
    }
    bool isCompound() const override 
    {
        return true;
    }
};