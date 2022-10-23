#pragma once

#include "./iterator_factory.h"
#include "../null_iterator.h"
#include "../bfs_compound_iterator.h"

class BFSIteratorFactory : public IteratorFactory 
{
    Iterator *createIterator() override;
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override;

};

