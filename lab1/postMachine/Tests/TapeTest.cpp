#include <gtest/gtest.h>
#include "../Tape.h"
#include <sstream>

class TapeTest : public ::testing::Test {
protected:
    void SetUp() override {
        tape = Tape(10);
    }
    Tape tape;
};

TEST_F(TapeTest, Constructor) {
    EXPECT_EQ(tape.read(), 0);
    EXPECT_GE(tape.getHead(), 0);
}

TEST_F(TapeTest, MoveRight) {
    int initialHead = tape.getHead();
    tape.moveRight();
    EXPECT_EQ(tape.getHead(), initialHead + 1);
}

TEST_F(TapeTest, MoveLeft) {
    int initialHead = tape.getHead();
    tape.moveLeft();
    EXPECT_EQ(tape.getHead(), initialHead - 1);
}

TEST_F(TapeTest, MoveLeftBeyondZero) {
    tape.setHead(0);
    tape.moveLeft();
    EXPECT_EQ(tape.getHead(), 0);
}

TEST_F(TapeTest, MoveRightBeyondSize) {
    int size = 10;
    Tape smallTape(size);
    smallTape.setHead(size - 1);
    smallTape.moveRight();
    EXPECT_EQ(smallTape.getHead(), size);
}

TEST_F(TapeTest, WriteAndRead) {
    tape.write(1);
    EXPECT_EQ(tape.read(), 1);
}

TEST_F(TapeTest, WriteZero) {
    tape.write(1);
    tape.write(0);
    EXPECT_EQ(tape.read(), 0);
}

TEST_F(TapeTest, ReadBeyondBounds) {
    Tape smallTape(1);
    smallTape.setHead(5);
    EXPECT_EQ(smallTape.read(), 0);
}

TEST_F(TapeTest, WriteBeyondBounds) {
    Tape smallTape(1);
    smallTape.setHead(5);
    smallTape.write(1);
    EXPECT_EQ(smallTape.read(), 1);
}

TEST_F(TapeTest, SetHead) {
    tape.setHead(3);
    EXPECT_EQ(tape.getHead(), 3);
}

TEST_F(TapeTest, SetHeadNegative) {
    tape.setHead(-5);
    EXPECT_GE(tape.getHead(), 0);
}

TEST_F(TapeTest, LoadFromStream) {
    std::stringstream ss;
    ss << "1010";
    tape.loadFromStream(ss);
    EXPECT_EQ(tape.read(), 1);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 0);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 1);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 0);
}

TEST_F(TapeTest, LoadFromStreamEmpty) {
    std::stringstream ss;
    ss << "";
    tape.loadFromStream(ss);
    EXPECT_EQ(tape.read(), 0);
}

TEST_F(TapeTest, LoadFromStreamWithOnes) {
    std::stringstream ss;
    ss << "111";
    tape.loadFromStream(ss);
    EXPECT_EQ(tape.read(), 1);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 1);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 1);
}

TEST_F(TapeTest, LoadFromStreamWithZeros) {
    std::stringstream ss;
    ss << "000";
    tape.loadFromStream(ss);
    EXPECT_EQ(tape.read(), 0);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 0);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 0);
}

TEST_F(TapeTest, Print) {
    testing::internal::CaptureStdout();
    tape.print(2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(TapeTest, PrintWithData) {
    tape.write(1);
    testing::internal::CaptureStdout();
    tape.print(2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(TapeTest, MultipleMoves) {
    tape.write(1);
    tape.moveRight();
    tape.write(2);
    tape.moveLeft();
    EXPECT_EQ(tape.read(), 1);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 2);
}

TEST_F(TapeTest, SequenceOperations) {
    tape.write(1);
    tape.moveRight();
    tape.write(0);
    tape.moveRight();
    tape.write(1);
    tape.moveLeft();
    tape.moveLeft();
    EXPECT_EQ(tape.read(), 1);
}

TEST_F(TapeTest, LargeMoves) {
    for (int i = 0; i < 100; i++) {
        tape.moveRight();
    }
    EXPECT_GE(tape.getHead(), 100);
}

TEST_F(TapeTest, WriteDifferentValues) {
    tape.write(5);
    EXPECT_EQ(tape.read(), 5);
    tape.write(255);
    EXPECT_EQ(tape.read(), 255);
    tape.write(-1);
    EXPECT_EQ(tape.read(), -1);
}
