#pragma once

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"
#include <string>
#include <algorithm>

#include <list>


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

    Iterator* createDFSIterator() override 
    {
        return new DFSCompoundIterator<std::list<Shape *>::const_iterator>(_shapes.begin(),_shapes.end());
    }

    Iterator* createBFSIterator() override 
    {
        return new BFSCompoundIterator<std::list<Shape *>::const_iterator>(_shapes.begin(),_shapes.end());
    }

    void addShape(Shape* shape)  override 
    {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape)  override 
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