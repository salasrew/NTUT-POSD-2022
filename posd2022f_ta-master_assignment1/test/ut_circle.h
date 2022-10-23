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
    // new TwoDimensionalVector(Point(0, 0), Point(3, 0)),
    // new TwoDimensionalVector(Point(3, 4), Point(3, 0))
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);

    TwoDimensionalVector _circle(&point1,&point2);

    Circle circle(&_circle);

    ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))", circle.info());
}