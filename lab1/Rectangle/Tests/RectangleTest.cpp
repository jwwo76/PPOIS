#include <gtest/gtest.h>
#include "../Rectangle.h"
#include <sstream>

class RectangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        rect1 = Rectangle(0, 0, 5, 5);
        rect2 = Rectangle(2, 2, 7, 7);
        rect3 = Rectangle(10, 10, 15, 15);
        zeroRect = Rectangle(0, 0, 0, 0);
    }

    Rectangle rect1;
    Rectangle rect2;
    Rectangle rect3;
    Rectangle zeroRect;
};

TEST_F(RectangleTest, ConstructorWithPoints) {
    Point p1(1, 1);
    Point p2(4, 4);
    Rectangle rect(p1, p2);
    
    std::stringstream ss;
    rect.print_verticles(ss);
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, ConstructorWithCoordinates) {
    Rectangle rect(1, 1, 4, 4);
    
    std::stringstream ss;
    rect.print_verticles(ss);
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, ConstructorWithReversedCoordinates) {
    Rectangle rect(4, 4, 1, 1);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, DefaultConstructor) {
    Rectangle rect;
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, PrintVerticles) {
    Rectangle rect(1, 1, 3, 3);
    std::stringstream ss;
    rect.print_verticles(ss);
    
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
}

TEST_F(RectangleTest, StreamOperator) {
    Rectangle rect(1, 1, 3, 3);
    std::stringstream ss;
    ss << rect;
    
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, MoveRectanglePositive) {
    Rectangle rect(1, 1, 3, 3);
    rect.move_rectangle(2, 3);
    
    std::stringstream ss1, ss2;
    ss1 << Rectangle(1, 1, 3, 3);
    ss2 << rect;
    
    EXPECT_NE(ss1.str(), ss2.str());
}

TEST_F(RectangleTest, MoveRectangleNegative) {
    Rectangle rect(5, 5, 8, 8);
    rect.move_rectangle(-2, -3);
    
    std::stringstream ss1, ss2;
    ss1 << Rectangle(5, 5, 8, 8);
    ss2 << rect;
    
    EXPECT_NE(ss1.str(), ss2.str());
}

TEST_F(RectangleTest, MoveRectangleZero) {
    Rectangle original(1, 1, 3, 3);
    Rectangle moved = original;
    moved.move_rectangle(0, 0);
    
    EXPECT_TRUE(original == moved);
}

TEST_F(RectangleTest, SizeChangePositive) {
    Rectangle rect(1, 1, 3, 3);
    rect.size_change(2);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, SizeChangeNegative) {
    Rectangle rect(1, 1, 5, 5);
    rect.size_change(-2);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, SizeChangeToZero) {
    Rectangle rect(1, 1, 3, 3);
    rect.size_change(-3);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, SizeChangeNegativeTooMuch) {
    Rectangle rect(1, 1, 2, 2);
    rect.size_change(-10);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, PreIncrement) {
    Rectangle original = rect1;
    ++rect1;
    
    EXPECT_FALSE(original == rect1);
}

TEST_F(RectangleTest, PostIncrement) {
    Rectangle original = rect1;
    Rectangle result = rect1++;
    
    EXPECT_TRUE(result == original);
    EXPECT_FALSE(rect1 == original);
}

TEST_F(RectangleTest, PreDecrement) {
    Rectangle original = rect1;
    --rect1;
    
    EXPECT_FALSE(original == rect1);
}

TEST_F(RectangleTest, PostDecrement) {
    Rectangle original = rect1;
    Rectangle result = rect1--;
    
    EXPECT_TRUE(result == original);
    EXPECT_FALSE(rect1 == original);
}

TEST_F(RectangleTest, MultipleIncrementDecrement) {
    Rectangle original = rect1;
    ++rect1;
    ++rect1;
    --rect1;
    
    EXPECT_FALSE(original == rect1);
}

TEST_F(RectangleTest, AdditionOperator) {
    Rectangle result = rect1 + rect2;
    
    std::stringstream ss;
    ss << result;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, AdditionWithNonOverlapping) {
    Rectangle result = rect1 + rect3;
    
    std::stringstream ss;
    ss << result;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, AdditionAssignmentOperator) {
    Rectangle original = rect1;
    rect1 += rect2;
    
    EXPECT_FALSE(original == rect1);
}

TEST_F(RectangleTest, SubtractionOperatorWithOverlap) {
    Rectangle result = rect1 - rect2;
    
    std::stringstream ss;
    ss << result;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, SubtractionOperatorNoOverlap) {
    Rectangle result = rect1 - rect3;
    
    EXPECT_TRUE(result == zeroRect);
}

TEST_F(RectangleTest, SubtractionOperatorTouchingEdges) {
    Rectangle rectA(0, 0, 5, 5);
    Rectangle rectB(5, 0, 10, 5);
    
    Rectangle result = rectA - rectB;
    EXPECT_TRUE(result == zeroRect);
}

TEST_F(RectangleTest, SubtractionAssignmentOperator) {
    Rectangle original = rect1;
    rect1 -= rect2;
    
    EXPECT_FALSE(original == rect1);
}

TEST_F(RectangleTest, SubtractionToZeroRectangle) {
    rect1 -= rect3;
    
    EXPECT_TRUE(rect1 == zeroRect);
}

TEST_F(RectangleTest, EqualityOperator) {
    Rectangle rectA(1, 1, 3, 3);
    Rectangle rectB(1, 1, 3, 3);
    
    EXPECT_TRUE(rectA == rectB);
}

TEST_F(RectangleTest, EqualityOperatorDifferent) {
    EXPECT_FALSE(rect1 == rect2);
}

TEST_F(RectangleTest, InequalityOperator) {
    EXPECT_TRUE(rect1 != rect2);
}

TEST_F(RectangleTest, InequalityOperatorSame) {
    Rectangle rectA(1, 1, 3, 3);
    Rectangle rectB(1, 1, 3, 3);
    
    EXPECT_FALSE(rectA != rectB);
}

TEST_F(RectangleTest, ZeroSizeRectangle) {
    Rectangle zero(0, 0, 0, 0);
    std::stringstream ss;
    ss << zero;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, NegativeCoordinates) {
    Rectangle rect(-5, -5, -1, -1);
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, SinglePointRectangle) {
    Rectangle rect(2, 2, 2, 2);
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, LargeCoordinates) {
    Rectangle rect(0, 0, 10000, 10000);
    rect.size_change(5000);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, ChainOperations) {
    Rectangle result = (rect1 + rect2) - rect3;
    result += rect1;
    ++result;
    
    std::stringstream ss;
    ss << result;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, SelfAssignment) {
    rect1 += rect1;
    
    std::stringstream ss;
    ss << rect1;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, MultipleOperationsOnSameObject) {
    Rectangle rect(1, 1, 10, 10);
    
    rect.move_rectangle(5, 5);
    rect.size_change(-2);
    ++rect;
    rect += Rectangle(0, 0, 3, 3);
    
    std::stringstream ss;
    ss << rect;
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(RectangleTest, CopyConsistency) {
    Rectangle original(2, 2, 8, 8);
    Rectangle copy = original;
    
    EXPECT_TRUE(original == copy);
    
    copy.move_rectangle(1, 1);
    EXPECT_FALSE(original == copy);
}
