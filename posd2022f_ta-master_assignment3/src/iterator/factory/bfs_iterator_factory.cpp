// #pragma once
#include "./bfs_iterator_factory.h"

Iterator *BFSIteratorFactory::createIterator() 
{
    return new NullIterator();
}
Iterator *BFSIteratorFactory::createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end)
{
    return new BFSCompoundIterator<std::list<Shape *>::const_iterator>(begin,end);
}

