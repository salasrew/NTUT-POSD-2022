#pragma once

#include "../src/shape.h"
#include <string>

#include <list>
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/circle.h"
#include "../src/compound_shape.h"

TEST(CompoundShapeTest,constructTest)
{
    // Verifies that statement does not throw any exception.
    EXPECT_NO_THROW(CompoundShape *cs1 = new CompoundShape());
}
TEST(CompoundShapeTest,constructTest2)
{
    Shape *test;
    Shape **tests = &test;
    CompoundShape *cs1;

    EXPECT_NO_THROW(cs1 = new CompoundShape(tests,4));
}
TEST(CompoundShapeTest,constructTest3)
{
    Point point1(0.00, 0.00);
    Point point2(0.00, 5.00);
    Point point3(5.00, 0.00);

    TwoDimensionalVector _circle(&point1,&point2);
    TwoDimensionalVector _rec2(&point1,&point3);
    Circle circle(&_circle);
    Rectangle rectangle(&_circle,&_rec2);

    CompoundShape *cs1;

    Shape* shapeList[] = {&circle,&rectangle};

    EXPECT_NO_THROW(cs1 = new CompoundShape(shapeList,2));
}


TEST(CompoundShapeTest,infoTest)
{
    Point point1(0.00, 0.00);
    Point point2(0.00, 5.00);
    Point point3(5.00, 0.00);

    TwoDimensionalVector _circle(&point1,&point2);
    TwoDimensionalVector _rec2(&point1,&point3);
    Circle circle(&_circle);
    Rectangle rectangle(&_circle,&_rec2);

    CompoundShape *cs1;
    cs1 = new CompoundShape();
    cs1->addShape(&circle);
    cs1->addShape(&rectangle);
    std::string eq = "CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (0.00, 5.00)), Vector ((0.00, 0.00), (5.00, 0.00))))";
    
    ASSERT_EQ(eq, cs1->info());
}


TEST(CompoundShapeTest,areaTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);
    CompoundShape *cs;
    cs = new CompoundShape();
    cs->addShape(&circle);

    ASSERT_EQ(5 * 5 *M_PI, cs->area());
}
TEST(CompoundShapeTest,perimeterTest)
{
    // vector (0,5)
    Point point1(0,0);
    Point point2(0,5);

    TwoDimensionalVector _5(&point1,&point2);
    Circle circle(&_5);
    CompoundShape *cs;
    cs = new CompoundShape();
    cs->addShape(&circle);

    ASSERT_EQ(2 * 5 *M_PI, cs->perimeter());
}
TEST(CompoundShapeTest,deleteCompoundShapeTest)
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

    cs2->deleteShape(cs1);
    
    // 5 * 5 *M_PI + 25 + 3*3* M_PI
    ASSERT_EQ( 3*3*M_PI , cs2->area());
}
TEST(CompoundShapeTest,createDFSItrTest)
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

    Iterator *itr;
    // itr = cs2->createDFSIterator();
    // 5 * 5 *M_PI + 25 + 3*3* M_PI
    ASSERT_NO_THROW(itr = cs2->createDFSIterator());
}
TEST(CompoundShapeTest,createBFSItrTest)
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

    Iterator *itr;

    ASSERT_NO_THROW(itr = cs2->createBFSIterator());
}

TEST(CompoundShapeTest,addShapeTest)
{
    Point *p1, *p2;
    TwoDimensionalVector *vec1;
    CompoundShape *cs1;
    
    p1 = new Point(0, 0);
    p2 = new Point(0, 5);

    vec1 = new TwoDimensionalVector(p1, p2);

    cs1 = new CompoundShape();

    ASSERT_NO_THROW(cs1->addShape(new Circle(vec1)));

    ASSERT_EQ(5 * 5 *M_PI, cs1->area());
}
