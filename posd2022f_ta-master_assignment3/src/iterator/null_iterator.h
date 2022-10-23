#pragma once

#include "iterator.h"

class NullIterator : public Iterator
{
public:
    void first() override 
    {
        throw "first get called";
    }

    Shape* currentItem() const override 
    {
        throw "currentItem get called!";
    }

    void next() override 
    {
        throw "next get called!";
    }

    bool isDone() const override 
    {
        return true;
    }
};