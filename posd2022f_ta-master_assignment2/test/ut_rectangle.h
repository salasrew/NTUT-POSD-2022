#include "../src/rectangle.h"
#include "../src/circle.h"

TEST(recTest,constructorTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(1,5);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);

    EXPECT_ANY_THROW(Rectangle rec(&_5,&_4));
}


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

TEST(recTest,createDFSIteratorTest)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);
    
    ASSERT_TRUE(rec.createDFSIterator()->isDone());
}

TEST(recTest,createBFSIteratorTest)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);
    
    ASSERT_TRUE(rec.createBFSIterator()->isDone());
}

TEST(recTest,addShapeTest)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);
    
    // vector (0,5)
    Point point4(0,0);
    Point point5(0,5);

    TwoDimensionalVector _5(&point4,&point5);
    Circle circle(&_5);

    ASSERT_ANY_THROW(rec.addShape(&circle));
}

TEST(recTest,deleteShapeTest)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);
    
    // vector (0,5)
    Point point4(0,0);
    Point point5(0,5);

    TwoDimensionalVector _5(&point4,&point5);
    Circle circle(&_5);

    ASSERT_ANY_THROW(rec.deleteShape(&circle));
}

TEST(recTest,isCompoundTest)
{
    Point point1(-2, 1);
    Point point2(1.5, 0.47);
    Point point3(-1.47, 4.5);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point1,&point3);

    Rectangle rec(&a,&b);
    

    ASSERT_FALSE(rec.isCompound());
}
