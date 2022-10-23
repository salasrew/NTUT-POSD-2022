#pragma once

#include "./iterator_factory.h"
#include "../null_iterator.h"
#include "../dfs_compound_iterator.h"

class DFSIteratorFactory : public IteratorFactory 
{
    Iterator *createIterator() override;
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override;
};