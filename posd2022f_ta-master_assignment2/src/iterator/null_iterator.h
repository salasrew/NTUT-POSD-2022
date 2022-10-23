#pragma once

#include "iterator.h"

// The first method is used to initialize the iterator state. It can be called either on the for loop initialization or in the iterator constructor. 
// The isDone is to check if the iterator has gone through all elements (shapes). 
// The next tells the iterator to move to the next element. 
// The current returns the current element that the iterator steps on.

// Notice that an iterator can know it has gone through all elements only after the last next is called. 
// For example, there is a compound shape contains two shapes: a triangle and a rectangle. 
// The order of iterator methods and the expected output should be as below:


//  null iterator does not return any shapes. It is empty. Its isDone always returns true without calling next; next and current throw an exception once get called.
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