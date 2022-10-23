#pragma once

#include "shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/bfs_iterator_factory.h"
#include "../iterator/factory/list_iterator_factory.h"

#include <vector>

class CollisionDetector : public ShapeVisitor
{
private:
    std::vector<Shape *> _collideResult;
    BoundingBox *_targetBoundingBox;

public:
    CollisionDetector(Shape *shape) 
    {
        _targetBoundingBox = new BoundingBox(shape->getPoints());
    }

    void visitCircle(Circle *circle) override 
    {
        BoundingBox *circleBoundingBox = new BoundingBox(circle->getPoints());
        if(_targetBoundingBox->collide(circleBoundingBox))
        {
            _collideResult.push_back(circle);
        }
    }

    void visitTriangle(Triangle *triangle) override 
    {
        BoundingBox *triangleBoundingBox = new BoundingBox(triangle->getPoints());
        if(_targetBoundingBox->collide(triangleBoundingBox))
        {
            _collideResult.push_back(triangle);
        }    
    }

    void visitRectangle(Rectangle *rectangle) override 
    {
        BoundingBox *rectangleBoundingBox = new BoundingBox(rectangle->getPoints());
        if(_targetBoundingBox->collide(rectangleBoundingBox))
        {
            _collideResult.push_back(rectangle);
        }      
    }

    void visitCompoundShape(CompoundShape *compoundShape) override 
    {   
        BoundingBox *compoundShapeBoundingBox = new BoundingBox(compoundShape->getPoints());
        if(_targetBoundingBox->collide(compoundShapeBoundingBox))
        {
            Iterator *itr;
            itr = compoundShape->createIterator(new ListIteratorFactory());
            for (;!itr->isDone();itr->next())
                itr->currentItem()->accept(this);
        }
    }

    std::vector<Shape *> collidedShapes() const 
    {
        return _collideResult;
    }
};