#pragma once

#include "../../src/circle.h"
#include "../../src/triangle.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include "../../src/bounding_box.h"

#include "../../src/visitor/collision_detector.h"

#include "../../src/iterator/factory/bfs_iterator_factory.h"
#include "../../src/iterator/factory/list_iterator_factory.h"

#include <vector>

TEST(collisionDetector,constructor)
{
    Point point1(0,0);
    Point point2(0,5);
    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);
    Shape* test[] = {&circle};

    EXPECT_NO_THROW(CollisionDetector collisionDetector(test[0]));
}

TEST(collisionDetector,visitCircle)
{
    Point point1(0,0);
    Point point2(0,5);
    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    CollisionDetector circleDetector(&circle);

    EXPECT_NO_THROW(circleDetector.visitCircle(&circle));
}

TEST(collisionDetector,visitTriangle)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);

    CollisionDetector triDetector(&tri);

    EXPECT_NO_THROW(triDetector.visitTriangle(&tri));
}
TEST(collisionDetector,visitRectangle)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);

    CollisionDetector recDetector(&rec);

    EXPECT_NO_THROW(recDetector.visitRectangle(&rec));
}
TEST(collisionDetector,visitCompoundShape)
{
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;
    
    p1 = new Point(0, 0);
    p2 = new Point(0, 5);
    p3 = new Point(5, 0);
    p4 = new Point(0, 3);

    vec1 = new TwoDimensionalVector(p1, p2);
    vec2 = new TwoDimensionalVector(p1, p3);
    vec3 = new TwoDimensionalVector(p1, p4);

    cs1 = new CompoundShape();
    cs1->addShape(new Circle(vec1));
    cs1->addShape(new Rectangle(vec1,vec2));

    cs2 = new CompoundShape();
    cs2->addShape(new Circle(vec3));
    cs2->addShape(cs1);

    CollisionDetector compoundShapeDetector(cs2);

    EXPECT_NO_THROW(compoundShapeDetector.visitCompoundShape(cs2));   
}
TEST(collisionDetector,collidedShapes)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);

    CollisionDetector recDetector(&rec);

    ASSERT_EQ(recDetector.collidedShapes().size(),0);
}
