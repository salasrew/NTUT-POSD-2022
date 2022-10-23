#include "../src/point.h"

TEST(PointTest,xTest)
{
    Point point1(0,0);

    ASSERT_EQ(false,point1.x());
}

TEST(PointTest,yTest)
{
    Point point1(0,0);

    ASSERT_EQ(false,point1.y());
}


TEST(PointTest,equalTest)
{
    Point point1(0,0);
    Point point2(0,0);

    ASSERT_EQ(true,point1==point2);
}

TEST(PointTest,notEqualTest)
{
    Point point1(0,0);
    Point point2(0,1);

    ASSERT_EQ(false,point1==point2);
}

TEST(PointTest,infoTest)
{
    Point point(0,0);

    ASSERT_EQ("(0, 0)", point.info());
}

