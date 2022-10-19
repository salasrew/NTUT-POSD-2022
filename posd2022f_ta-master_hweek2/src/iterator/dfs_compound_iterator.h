#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>

class CompoundShape;

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator
{
private:
    ForwardIterator _end;
    ForwardIterator _current;
    std::list<Shape *> _traversal;

public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) 
    {

        // 走訪由 list的頭走到list的尾
        for (ForwardIterator _shapeItr = begin; _shapeItr != end ; _shapeItr++)
        {
            // 建立DFS iterator
            // 只有compoundShape建立的itr是有功能的
            // 其餘都是nullIterator 唯一功能 isDone() 回傳True
            Iterator* itr = (*_shapeItr)->createDFSIterator();
            // 每經過一個shape push進去(CompoundShape也是Shape)
            _traversal.push_back(*_shapeItr);

            for(; !itr->isDone() ; itr->next())
            {
                // itr走訪，同上，走訪過一次push current
                _traversal.push_back(itr->currentItem());
            }

            delete itr;
        }
        // 初始化
        first();
    }

    // initialize
    void first() override 
    {
        _current  = _traversal.begin();
        _end = _traversal.end();
    }

    // Finally, CurrentItern returns the item at the current index. If the iteration
    // has already terminated, then we throw an IteratorOutOf Bounds exception:
    
    Shape* currentItem() const override 
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