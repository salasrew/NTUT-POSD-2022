#include "../src/two_dimensional_vector.h"

TEST(twoDTest,xTest)
{
    Point point1(3,0);
    Point point2(0,4);
    TwoDimensionalVector _345(&point1,&point2);
    bool ans = (point1 == *_345.a());
    ASSERT_TRUE(ans);
}
TEST(twoDTest,yTest)
{
    Point point1(3,0);
    Point point2(0,4);
    TwoDimensionalVector _345(&point1,&point2);

    ASSERT_TRUE(point2 == *_345.b());
}

TEST(twoDTest,lengthTest)
{
    Point point1(3,0);
    Point point2(0,4);
    TwoDimensionalVector _345(&point1,&point2);

    ASSERT_EQ(5,_345.length());
}
TEST(twoDTest,dotTest)
{
    // vector (2,4)
    Point point1(18,31);
    Point point2(20,35);

    // vector (3,5)
    Point point3(7,15);
    Point point4(10,20);

    TwoDimensionalVector _24(&point1,&point2);
    TwoDimensionalVector _35(&point3,&point4);

    ASSERT_EQ(26, _24.dot(&_35));

}
TEST(twoDTest,crossTest)
{
    // vector (2,4)
    Point point1(18,31);
    Point point2(20,35);

    // vector (3,5)
    Point point3(7,15);
    Point point4(10,20);

    TwoDimensionalVector _24(&point1,&point2);
    TwoDimensionalVector _35(&point3,&point4);

    // 10 - 12 = -2

    ASSERT_EQ(-2, _24.cross(&_35));
}

TEST(twoDTest,infoTest)
{

    Point point1(-8.42, 3.42);
    Point point2(-3.38, 4.3);
    TwoDimensionalVector _2D(&point1,&point2);


    ASSERT_EQ("Vector ((-8.42, 3.42), (-3.38, 4.30))", _2D.info());
}