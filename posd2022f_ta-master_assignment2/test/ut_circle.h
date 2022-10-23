#include "../src/circle.h"
#include <iostream>

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