#include "../src/bounding_box.h"
#include "../src/point.h"

#include <set>
#include <iostream>
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"

TEST(BoundingBoxTest,calMaximumPoint)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,2);
    Point point3(0,3);

    TwoDimensionalVector _2(&point1,&point2);
    TwoDimensionalVector _3(&point1,&point3);

    Circle circle2(&_2);
    Circle circle3(&_3);

    BoundingBox *bdb_circle3 = new BoundingBox(circle3.getPoints());
    // bdb_circle3->calMaximumPoint(circle2.getPoints());

    bdb_circle3->calMaximumPoint(circle2.getPoints())->info() == bdb_circle3->max()->info();

    ASSERT_TRUE(bdb_circle3->calMaximumPoint(circle2.getPoints())->info() == bdb_circle3->max()->info());
}
TEST(BoundingBoxTest,calMinimumPoint)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,2);
    Point point3(0,3);

    TwoDimensionalVector _2(&point1,&point2);
    TwoDimensionalVector _3(&point1,&point3);

    Circle circle2(&_2);
    Circle circle3(&_3);

    BoundingBox *bdb_circle3 = new BoundingBox(circle3.getPoints());
    // bdb_circle3->calMaximumPoint(circle2.getPoints());

    bdb_circle3->calMinimumPoint(circle2.getPoints())->info() == bdb_circle3->min()->info();

    ASSERT_TRUE(bdb_circle3->calMinimumPoint(circle2.getPoints())->info() == bdb_circle3->min()->info());

}
TEST(BoundingBoxTest,max)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);
    Point pointR(5,5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    BoundingBox *bdb_circle = new BoundingBox(circle.getPoints());

    // std::cout << bdb_circle->max()->info();
    // std::cout << pointR.info();

    ASSERT_TRUE(bdb_circle->max()->info() == pointR.info());
}
TEST(BoundingBoxTest,min)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);
    Point pointL(-5,-5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);

    BoundingBox *bdb_circle = new BoundingBox(circle.getPoints());

    ASSERT_TRUE(bdb_circle->min()->info() == pointL.info());

}
TEST(BoundingBoxTest,collide)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,2);
    Point point3(0,3);

    TwoDimensionalVector _2(&point1,&point2);
    TwoDimensionalVector _3(&point1,&point3);

    Circle circle2(&_2);
    Circle circle3(&_3);

    BoundingBox *bdb_circle2 = new BoundingBox(circle2.getPoints());
    BoundingBox *bdb_circle3 = new BoundingBox(circle3.getPoints());

    ASSERT_TRUE(bdb_circle2->collide(bdb_circle3));
}
