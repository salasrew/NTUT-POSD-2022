#include "../src/circle.h"
#include <set>
#include <iostream>
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"

TEST(circleTest,radiusTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    ASSERT_EQ(5, circle.radius());
}

TEST(circleTest,areaTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

//round(circle.area() *100)/100
    ASSERT_EQ(78.54, round(circle.area() *100)/100);
}

TEST(circleTest,perimeterTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    ASSERT_EQ(31.42, round(circle.perimeter() *100)/100);
}

TEST(circleTest,infoTest)
{
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);

    TwoDimensionalVector _circle(&point1,&point2);

    Circle circle(&_circle);

    ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))", circle.info());
}

TEST(circleTest,createIterator)
{
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);

    TwoDimensionalVector _circle(&point1,&point2);

    Circle circle(&_circle);
    
    Iterator *temp = circle.createIterator(new BFSIteratorFactory());

    ASSERT_TRUE(temp->isDone());
}


TEST(circleTest,createDFSIteratorTest)
{
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);

    TwoDimensionalVector _circle(&point1,&point2);

    Circle circle(&_circle);
    
    Iterator *temp = circle.createDFSIterator();

    ASSERT_TRUE(temp->isDone());
}

TEST(circleTest,createBFSIteratorTest)
{
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);

    TwoDimensionalVector _circle(&point1,&point2);

    Circle circle(&_circle);
    
    Iterator *temp = circle.createBFSIterator();

    ASSERT_TRUE(temp->isDone());
}

TEST(circleTest,getPoints)
{
    Point point1(0,0);
    Point point2(0,5);
    Point point3(5,5);
    Point point4(-5,-5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    ASSERT_TRUE(circle.getPoints().size()==2);
}

TEST(circleTest,accept)
{
    Point point1(0,0);
    Point point2(0,5);
    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    CollisionDetector circleDetector(&circle);
    // circle.accept(&circleDetector);
    EXPECT_NO_THROW(circle.accept(&circleDetector));
}

TEST(circleTest,addShapeTest)
{

    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);
    Point point3(0,0);
    Point point4(0,5);
    
    TwoDimensionalVector _circle1(&point1,&point2);
    TwoDimensionalVector _circle2(&point3,&point4);

    Circle circle1(&_circle1);
    Circle circle2(&_circle2);


    EXPECT_ANY_THROW(circle1.addShape(&circle2));
}

TEST(circleTest,deleteShapeTest)
{
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);
    Point point3(0,0);
    Point point4(0,5);
    
    TwoDimensionalVector _circle1(&point1,&point2);
    TwoDimensionalVector _circle2(&point3,&point4);

    Circle circle1(&_circle1);
    Circle circle2(&_circle2);

    EXPECT_ANY_THROW(circle1.deleteShape(&circle2));
}

TEST(circleTest,isCompoundTest)
{
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);

    TwoDimensionalVector _circle1(&point1,&point2);

    Circle circle1(&_circle1);

    ASSERT_FALSE(circle1.isCompound());
}

