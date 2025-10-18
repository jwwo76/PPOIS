#include "Rectangle.h"
#include "Point.h"
#include "pch.h"

TEST(RectangleTest, DefaultConstructor) {
    rectangle r;
    EXPECT_EQ(r == rectangle(0, 0, 1, 1), true);
}

TEST(RectangleTest, ParamConstructorOrderIndependent) {
    rectangle r(5, 5, 1, 1);
    EXPECT_EQ(r == rectangle(1, 1, 5, 5), true);
}


TEST(RectangleTest, MoveRectangle) {
    rectangle r(1, 1, 3, 3);
    r.move_rectangle(2, 1);
    EXPECT_EQ(r == rectangle(3, 2, 5, 4), true);
}


TEST(RectangleTest, IncrementDecrementOperators) {
    rectangle r(1, 1, 3, 3);

    rectangle post = r++;
    EXPECT_EQ(post == rectangle(1, 1, 3, 3), true);
    EXPECT_EQ(r == rectangle(1, 1, 4, 4), true);

    ++r;
    EXPECT_EQ(r == rectangle(1, 1, 5, 5), true);

    rectangle post2 = r--;
    EXPECT_EQ(post2 == rectangle(1, 1, 5, 5), true);
    EXPECT_EQ(r == rectangle(1, 1, 4, 4), true);

    --r;
    EXPECT_EQ(r == rectangle(1, 1, 3, 3), true);
}


TEST(RectangleTest, AdditionOperator) {
    rectangle r1(0, 0, 2, 2);
    rectangle r2(1, 1, 4, 3);
    rectangle res = r1 + r2;
    EXPECT_EQ(res == rectangle(0, 0, 4, 3), true);
}


TEST(RectangleTest, SubtractionOperatorIntersection) {
    rectangle r1(1, 1, 5, 5);
    rectangle r2(2, 2, 4, 4);
    rectangle res = r1 - r2;
    EXPECT_EQ(res == rectangle(2, 2, 4, 4), true);
}


TEST(RectangleTest, SubtractionOperatorNoIntersection) {
    rectangle r1(0, 0, 1, 1);
    rectangle r2(2, 2, 3, 3);
    rectangle res = r1 - r2;
    EXPECT_EQ(res == rectangle(0, 0, 0, 0), true);
}


TEST(RectangleTest, PlusEqualAndMinusEqual) {
    rectangle r1(0, 0, 2, 2);
    rectangle r2(1, 1, 3, 3);

    r1 += r2;
    EXPECT_EQ(r1 == rectangle(0, 0, 3, 3), true);

    r1 -= rectangle(1, 1, 2, 2);
    EXPECT_EQ(r1 == rectangle(1, 1, 2, 2), true);
}