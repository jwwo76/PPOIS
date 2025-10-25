#include <gtest/gtest.h>
#include "Machine.h"
#include <sstream>

class MachineTest : public ::testing::Test {
protected:
    void SetUp() override {
        machine = Machine(10, false);
    }
    Machine machine;
};

TEST_F(MachineTest, Constructor) {
    EXPECT_NO_THROW(Machine(10, false));
    EXPECT_NO_THROW(Machine(5, true));
}

TEST_F(MachineTest, LoadProgram) {
    std::stringstream ss;
    ss << "1 R 2\n";
    ss << "0 L 1\n";
    machine.loadProgram(ss);
}

TEST_F(MachineTest, LoadTape) {
    std::stringstream ss;
    ss << "1010";
    machine.loadTape(ss);
}

TEST_F(MachineTest, StepWithNoProgram) {
    machine.step();
}

TEST_F(MachineTest, StepWithSimpleProgram) {
    std::stringstream program_ss;
    program_ss << "1 R 1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepWithWrite) {
    std::stringstream program_ss;
    program_ss << "1 R -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepWithLeftMove) {
    std::stringstream program_ss;
    program_ss << "0 L -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepWithRightMove) {
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepWithStayMove) {
    std::stringstream program_ss;
    program_ss << "0 S -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepWithNextInstruction) {
    std::stringstream program_ss;
    program_ss << "0 R 1\n";
    program_ss << "1 L -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepToCompletion) {
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
    machine.step();
}

TEST_F(MachineTest, StepWithInvalidNextInstruction) {
    std::stringstream program_ss;
    program_ss << "0 R 10\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, StepWithNegativeNextInstruction) {
    std::stringstream program_ss;
    program_ss << "0 R -2\n";
    machine.loadProgram(program_ss);
    
    machine.step();
}

TEST_F(MachineTest, RunWithNoProgram) {
    machine.run();
}

TEST_F(MachineTest, RunWithSimpleProgram) {
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    machine.loadProgram(program_ss);
    
    machine.run();
}


TEST_F(MachineTest, RunWithMultipleInstructions) {
    std::stringstream program_ss;
    program_ss << "1 R 1\n";
    program_ss << "0 L -1\n";
    machine.loadProgram(program_ss);
    
    testing::internal::CaptureStdout();
    machine.run();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(MachineTest, PrintState) {
    testing::internal::CaptureStdout();
    machine.printState();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(MachineTest, PrintStateWithProgram) {
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    machine.loadProgram(program_ss);
    
    testing::internal::CaptureStdout();
    machine.printState();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(MachineTest, LoadProgramAndTape) {
    std::stringstream program_ss;
    program_ss << "1 R -1\n";
    
    std::stringstream tape_ss;
    tape_ss << "1010";
    
    machine.loadProgram(program_ss);
    machine.loadTape(tape_ss);
    
    machine.run();
}

TEST_F(MachineTest, ComplexProgram) {
    std::stringstream program_ss;
    program_ss << "1 R 1\n";
    program_ss << "0 L 2\n";
    program_ss << "1 S -1\n";
    machine.loadProgram(program_ss);
    
    std::stringstream tape_ss;
    tape_ss << "0000";
    machine.loadTape(tape_ss);
    
    testing::internal::CaptureStdout();
    machine.run();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(MachineTest, MachineWithLogging) {
    Machine loggingMachine(10, true);
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    loggingMachine.loadProgram(program_ss);
    
    testing::internal::CaptureStdout();
    loggingMachine.run();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(MachineTest, MultipleRuns) {
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    machine.loadProgram(program_ss);
    
    machine.run();
    
    std::stringstream program_ss2;
    program_ss2 << "1 L -1\n";
    machine.loadProgram(program_ss2);
    
    machine.run();
}

TEST_F(MachineTest, StepAfterCompletion) {
    std::stringstream program_ss;
    program_ss << "0 R -1\n";
    machine.loadProgram(program_ss);
    
    machine.step();
    machine.step();
    machine.step();
}
