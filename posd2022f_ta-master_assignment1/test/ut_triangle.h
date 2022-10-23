#include "../src/triangle.h"

TEST(triTest,areaTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);
    Triangle tri(&_5,&_4);


    ASSERT_EQ(10, tri.area());
}


// perimeter
TEST(triTest,perimeterTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,3);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _3(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);
    Triangle tri(&_3,&_4);


    ASSERT_EQ(12, tri.perimeter());
}

//"Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))"
TEST(TriTest,infoTest)
{
    // new TwoDimensionalVector(Point(0, 0), Point(3, 0)),
    // new TwoDimensionalVector(Point(3, 4), Point(3, 0))
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);

    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))", tri.info());
}