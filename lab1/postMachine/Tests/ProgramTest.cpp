#include <gtest/gtest.h>
#include "../Program.h"
#include <sstream>

class ProgramTest : public ::testing::Test {
protected:
    void SetUp() override {
        program = Program();
    }
    Program program;
};

TEST_F(ProgramTest, AddInstruction) {
    Instruction instr{1, Move::Right, 2};
    program.addInstruction(instr);
    EXPECT_EQ(program.size(), 1);
}

TEST_F(ProgramTest, AddMultipleInstructions) {
    program.addInstruction({0, Move::Left, 1});
    program.addInstruction({1, Move::Right, 2});
    program.addInstruction({0, Move::Stay, 0});
    EXPECT_EQ(program.size(), 3);
}

TEST_F(ProgramTest, RemoveInstruction) {
    program.addInstruction({0, Move::Left, 1});
    program.addInstruction({1, Move::Right, 2});
    program.removeInstruction(0);
    EXPECT_EQ(program.size(), 1);
}

TEST_F(ProgramTest, RemoveInvalidInstruction) {
    program.addInstruction({0, Move::Left, 1});
    program.removeInstruction(5);
    EXPECT_EQ(program.size(), 1);
}

TEST_F(ProgramTest, RemoveNegativeIndex) {
    program.addInstruction({0, Move::Left, 1});
    program.removeInstruction(-1);
    EXPECT_EQ(program.size(), 1);
}

TEST_F(ProgramTest, GetInstruction) {
    Instruction instr{1, Move::Right, 2};
    program.addInstruction(instr);
    Instruction retrieved = program.getInstruction(0);
    EXPECT_EQ(retrieved.write, 1);
    EXPECT_EQ(retrieved.move, Move::Right);
    EXPECT_EQ(retrieved.next, 2);
}

TEST_F(ProgramTest, GetInstructionInvalidIndex) {
    Instruction instr = program.getInstruction(0);
    EXPECT_EQ(instr.write, 0);
    EXPECT_EQ(instr.move, Move::Stay);
    EXPECT_EQ(instr.next, -1);
}

TEST_F(ProgramTest, GetInstructionNegativeIndex) {
    Instruction instr = program.getInstruction(-1);
    EXPECT_EQ(instr.write, 0);
    EXPECT_EQ(instr.move, Move::Stay);
    EXPECT_EQ(instr.next, -1);
}

TEST_F(ProgramTest, SizeEmpty) {
    EXPECT_EQ(program.size(), 0);
}

TEST_F(ProgramTest, SizeAfterAdd) {
    program.addInstruction({0, Move::Left, 1});
    EXPECT_EQ(program.size(), 1);
}

TEST_F(ProgramTest, LoadFromStream) {
    std::stringstream ss;
    ss << "1 R 2\n";
    ss << "0 L 1\n";
    program.loadFromStream(ss);
    EXPECT_EQ(program.size(), 2);
    
    Instruction instr1 = program.getInstruction(0);
    EXPECT_EQ(instr1.write, 1);
    EXPECT_EQ(instr1.move, Move::Right);
    EXPECT_EQ(instr1.next, 2);
    
    Instruction instr2 = program.getInstruction(1);
    EXPECT_EQ(instr2.write, 0);
    EXPECT_EQ(instr2.move, Move::Left);
    EXPECT_EQ(instr2.next, 1);
}

TEST_F(ProgramTest, LoadFromStreamWithEmptyLines) {
    std::stringstream ss;
    ss << "1 R 2\n";
    ss << "\n";
    ss << "0 L 1\n";
    program.loadFromStream(ss);
    EXPECT_EQ(program.size(), 2);
}

TEST_F(ProgramTest, LoadFromStreamLeftMove) {
    std::stringstream ss;
    ss << "1 L 2\n";
    program.loadFromStream(ss);
    Instruction instr = program.getInstruction(0);
    EXPECT_EQ(instr.move, Move::Left);
}

TEST_F(ProgramTest, LoadFromStreamRightMove) {
    std::stringstream ss;
    ss << "1 R 2\n";
    program.loadFromStream(ss);
    Instruction instr = program.getInstruction(0);
    EXPECT_EQ(instr.move, Move::Right);
}

TEST_F(ProgramTest, LoadFromStreamStayMove) {
    std::stringstream ss;
    ss << "1 X 2\n";
    program.loadFromStream(ss);
    Instruction instr = program.getInstruction(0);
    EXPECT_EQ(instr.move, Move::Stay);
}

TEST_F(ProgramTest, LoadFromStreamEmpty) {
    std::stringstream ss;
    program.loadFromStream(ss);
    EXPECT_EQ(program.size(), 0);
}

TEST_F(ProgramTest, LoadFromStreamMultipleLines) {
    std::stringstream ss;
    ss << "0 R 1\n";
    ss << "1 L 0\n";
    ss << "0 S 2\n";
    program.loadFromStream(ss);
    EXPECT_EQ(program.size(), 3);
}

TEST_F(ProgramTest, Print) {
    program.addInstruction({1, Move::Right, 2});
    program.addInstruction({0, Move::Left, 1});
    
    testing::internal::CaptureStdout();
    program.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(ProgramTest, PrintEmpty) {
    testing::internal::CaptureStdout();
    program.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}


TEST_F(ProgramTest, ComplexInstructions) {
    program.addInstruction({0, Move::Stay, 0});
    program.addInstruction({1, Move::Left, 1});
    program.addInstruction({0, Move::Right, 2});
    program.addInstruction({1, Move::Stay, 3});
    
    EXPECT_EQ(program.size(), 4);
    
    Instruction instr = program.getInstruction(2);
    EXPECT_EQ(instr.write, 0);
    EXPECT_EQ(instr.move, Move::Right);
    EXPECT_EQ(instr.next, 2);
}

TEST_F(ProgramTest, InstructionSequence) {
    program.addInstruction({0, Move::Right, 1});
    program.addInstruction({1, Move::Left, 0});
    
    Instruction first = program.getInstruction(0);
    Instruction second = program.getInstruction(1);
    
    EXPECT_EQ(first.next, 1);
    EXPECT_EQ(second.next, 0);
}

TEST_F(ProgramTest, OverwriteInstructions) {
    program.addInstruction({0, Move::Left, 1});
    program.addInstruction({1, Move::Right, 2});
    program.removeInstruction(0);
    program.addInstruction({0, Move::Stay, 0});
    
    EXPECT_EQ(program.size(), 2);
    Instruction instr = program.getInstruction(0);
    EXPECT_EQ(instr.write, 1);
    EXPECT_EQ(instr.move, Move::Right);
    EXPECT_EQ(instr.next, 2);
}
