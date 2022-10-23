#include "../src/triangle.h"
#include "../src/circle.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"

TEST(TriTest,constructorTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,0);

    // vector (4,0)
    Point point3(4,0);

    TwoDimensionalVector _5(&point1,&point2);
    TwoDimensionalVector _4(&point1,&point3);

    EXPECT_ANY_THROW(Triangle tri(&_5,&_4));

}

TEST(TriTest,areaTest)
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
TEST(TriTest,perimeterTest)
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
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);

    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))", tri.info());
}
//----

TEST(TriTest,createIterator)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);

    Iterator *temp = tri.createIterator(new BFSIteratorFactory());

    ASSERT_TRUE(temp->isDone());
}

TEST(TriTest,createDFSIteratorTest)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);
    ASSERT_TRUE(tri.createDFSIterator()->isDone());
}

TEST(TriTest,createBFSIteratorTest)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);
    ASSERT_TRUE(tri.createBFSIterator()->isDone());
}
TEST(TriTest,getPoints)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);

    ASSERT_EQ(tri.getPoints().size(),3);
}

TEST(TriTest,accept)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);

    CollisionDetector triDetector(&tri);

    EXPECT_NO_THROW(tri.accept(&triDetector));
}

TEST(TriTest,addShapeTest)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);
    
    // vector (0,5)
    Point point4(0,0);
    Point point5(0,5);

    TwoDimensionalVector _5(&point4,&point5);
    Circle circle(&_5);

    ASSERT_ANY_THROW(tri.addShape(&circle));
}

TEST(TriTest,deleteShapeTest)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);
    
    // vector (0,5)
    Point point4(0,0);
    Point point5(0,5);

    TwoDimensionalVector _5(&point4,&point5);
    Circle circle(&_5);

    // ASSERT_ANY_THROW(tri.deleteShape(&circle));
    ASSERT_ANY_THROW(tri.deleteShape(new Circle(&_5)));

}

TEST(TriTest,isCompoundTest)
{
    Point point1(0, 0);
    Point point2(3, 0);
    Point point3(3, 4);

    TwoDimensionalVector a(&point1,&point2);
    TwoDimensionalVector b(&point3,&point2);

    Triangle tri(&a,&b);
    
    ASSERT_FALSE(tri.isCompound());
}
