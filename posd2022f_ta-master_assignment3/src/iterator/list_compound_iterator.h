#pragma once

#include "./iterator.h"
#include "../shape.h"
#include <list>

template <class ForwardIterator>
class ListCompoundIterator : public Iterator
{
    private:
    ForwardIterator _end;
    ForwardIterator _current;
    std::list<Shape *> _traversal;

public:
    ListCompoundIterator(ForwardIterator begin, ForwardIterator end) 
    {
        // 一個普通的iterator
        for (ForwardIterator _shapeItr = begin; _shapeItr != end ; _shapeItr++)
        {
            _traversal.push_back(*_shapeItr);
        }
        // 初始化
        first();
    }

    void first() override 
    {
        _current  = _traversal.begin();
        _end = _traversal.end();
    }

    Shape *currentItem() const override 
    {
        if(isDone())
        {
            throw "Out of list.";
        }
        return *_current;
    }

    void next() override 
    {
        // std::cout << "next()被呼叫" << std::endl;        
        if(isDone())
        {
            throw "NextShouldThrowExceptionWhenIsDone";
        }

        _current++;
    }

    bool isDone() const override 
    {
        return _current == _end ;
    }
};
