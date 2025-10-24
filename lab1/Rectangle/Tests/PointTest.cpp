#include <gtest/gtest.h>
#include "../Point.h"
#include <sstream>

class PointTest : public ::testing::Test {
protected:
    void SetUp() override {
        p1 = Point(1, 2);
        p2 = Point(3, 4);
        p3 = Point(0, 0);
        p4 = Point(-1, -2);
    }

    Point p1;
    Point p2;
    Point p3;
    Point p4;
};

TEST_F(PointTest, ConstructorWithParameters) {
    Point p(5, 6);
    EXPECT_EQ(p.get_x(), 5);
    EXPECT_EQ(p.get_y(), 6);
}

TEST_F(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_EQ(p.get_x(), 0);
    EXPECT_EQ(p.get_y(), 0);
}

TEST_F(PointTest, GetX) {
    EXPECT_EQ(p1.get_x(), 1);
    EXPECT_EQ(p2.get_x(), 3);
    EXPECT_EQ(p3.get_x(), 0);
    EXPECT_EQ(p4.get_x(), -1);
}

TEST_F(PointTest, GetY) {
    EXPECT_EQ(p1.get_y(), 2);
    EXPECT_EQ(p2.get_y(), 4);
    EXPECT_EQ(p3.get_y(), 0);
    EXPECT_EQ(p4.get_y(), -2);
}

TEST_F(PointTest, SetX) {
    Point p = p1;
    p.set_x(10);
    EXPECT_EQ(p.get_x(), 10);
    EXPECT_EQ(p.get_y(), 2);
}

TEST_F(PointTest, SetY) {
    Point p = p1;
    p.set_y(20);
    EXPECT_EQ(p.get_x(), 1);
    EXPECT_EQ(p.get_y(), 20);
}

TEST_F(PointTest, SetXNegative) {
    Point p = p1;
    p.set_x(-5);
    EXPECT_EQ(p.get_x(), -5);
    EXPECT_EQ(p.get_y(), 2);
}

TEST_F(PointTest, SetYNegative) {
    Point p = p1;
    p.set_y(-10);
    EXPECT_EQ(p.get_x(), 1);
    EXPECT_EQ(p.get_y(), -10);
}

TEST_F(PointTest, SetXZero) {
    Point p = p2;
    p.set_x(0);
    EXPECT_EQ(p.get_x(), 0);
    EXPECT_EQ(p.get_y(), 4);
}

TEST_F(PointTest, SetYZero) {
    Point p = p2;
    p.set_y(0);
    EXPECT_EQ(p.get_x(), 3);
    EXPECT_EQ(p.get_y(), 0);
}

TEST_F(PointTest, StreamOperator) {
    std::stringstream ss;
    ss << p1;
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_NE(output.find("2"), std::string::npos);
}

TEST_F(PointTest, StreamOperatorZero) {
    std::stringstream ss;
    ss << p3;
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("0"), std::string::npos);
}

TEST_F(PointTest, StreamOperatorNegative) {
    std::stringstream ss;
    ss << p4;
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("-1"), std::string::npos);
    EXPECT_NE(output.find("-2"), std::string::npos);
}

TEST_F(PointTest, StreamOperatorFormat) {
    std::stringstream ss;
    ss << Point(7, 8);
    std::string output = ss.str();
    EXPECT_NE(output.find("("), std::string::npos);
    EXPECT_NE(output.find(","), std::string::npos);
    EXPECT_NE(output.find(")"), std::string::npos);
}

TEST_F(PointTest, MultiplePointsInStream) {
    std::stringstream ss;
    ss << p1 << p2 << p3;
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_NE(output.find("2"), std::string::npos);
    EXPECT_NE(output.find("3"), std::string::npos);
    EXPECT_NE(output.find("4"), std::string::npos);
    EXPECT_NE(output.find("0"), std::string::npos);
}

TEST_F(PointTest, LargeCoordinates) {
    Point p(10000, -5000);
    EXPECT_EQ(p.get_x(), 10000);
    EXPECT_EQ(p.get_y(), -5000);
    
    std::stringstream ss;
    ss << p;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(PointTest, MultipleSetOperations) {
    Point p;
    p.set_x(5);
    p.set_y(6);
    p.set_x(-3);
    p.set_y(-4);
    
    EXPECT_EQ(p.get_x(), -3);
    EXPECT_EQ(p.get_y(), -4);
}

TEST_F(PointTest, ConstMethods) {
    const Point const_p(15, 25);
    EXPECT_EQ(const_p.get_x(), 15);
    EXPECT_EQ(const_p.get_y(), 25);
    
    std::stringstream ss;
    ss << const_p;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(PointTest, IndependenceAfterCopy) {
    Point original(9, 8);
    Point copy = original;
    
    EXPECT_EQ(original.get_x(), copy.get_x());
    EXPECT_EQ(original.get_y(), copy.get_y());
    
    copy.set_x(100);
    copy.set_y(200);
    
    EXPECT_EQ(original.get_x(), 9);
    EXPECT_EQ(original.get_y(), 8);
    EXPECT_EQ(copy.get_x(), 100);
    EXPECT_EQ(copy.get_y(), 200);
}

TEST_F(PointTest, AllNegativeCoordinates) {
    Point p(-10, -20);
    EXPECT_EQ(p.get_x(), -10);
    EXPECT_EQ(p.get_y(), -20);
    
    std::stringstream ss;
    ss << p;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(PointTest, MixedSignCoordinates) {
    Point p(-5, 10);
    EXPECT_EQ(p.get_x(), -5);
    EXPECT_EQ(p.get_y(), 10);
    
    std::stringstream ss;
    ss << p;
    EXPECT_FALSE(ss.str().empty());
}
