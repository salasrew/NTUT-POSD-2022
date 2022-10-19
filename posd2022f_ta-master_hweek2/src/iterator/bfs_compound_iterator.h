#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>

class CompoundShape;

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator
{
private:
    ForwardIterator _end;
    ForwardIterator _shapeItr;
    ForwardIterator _current;

    std::list<Shape *> _traversal;

public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end) 
    {        
        for (_shapeItr = begin; _shapeItr != end ; _shapeItr++)
        {
            _traversal.push_back(*_shapeItr);
        }

        for (_shapeItr = begin; _shapeItr != end ; _shapeItr++)
        {
            // compoundShape
            if((*_shapeItr)->isCompound())
            {
                Iterator* itr = (*_shapeItr)->createBFSIterator();
                for(; !itr->isDone() ; itr->next())
                {
                    _traversal.push_back(itr->currentItem());
                }
                delete itr;

            }
            // _traversal.push_back(*_shapeItr);
        }

        first();
    }

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