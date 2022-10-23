#include "../src/rectangle.h"

TEST(recTest,lengthTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);
    Rectangle rec(&_5,&_4);


    ASSERT_EQ(5, rec.length());
}
TEST(recTest,widthTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);
    Rectangle rec(&_5,&_4);


    ASSERT_EQ(4, rec.width());

}
TEST(recTest,areaTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);
    Rectangle rec(&_5,&_4);


    ASSERT_EQ(20, rec.area());
}

// perimeter
TEST(recTest,perimeterTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);
    Rectangle rec(&_5,&_4);


    ASSERT_EQ(18, rec.perimeter());
}

TEST(recTest,infoTest)
{
    // new TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
    // new TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5))
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);

    ASSERT_EQ("Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))", rec.info());
}
