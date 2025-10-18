#include "pch.h"
#include "Machine.h"


TEST(TapeTest, WriteAndReadWorks) {
    Tape tape(5);
    tape.write(1);
    EXPECT_EQ(tape.read(), 1);
    tape.write(0);
    EXPECT_EQ(tape.read(), 0);
}

TEST(TapeTest, MoveLeftExpandsTape) {
    Tape tape(3);
    tape.setHead(0);
    tape.moveLeft();
    tape.write(1);
    EXPECT_EQ(tape.read(), 1);
}

TEST(TapeTest, MoveRightExpandsTape) {
    Tape tape(2);
    tape.moveRight();
    tape.write(1);
    EXPECT_EQ(tape.read(), 1);
}

TEST(TapeTest, LoadFromStreamParsesCorrectly) {
    std::stringstream ss("10101");
    Tape tape(1);
    tape.loadFromStream(ss);

    EXPECT_EQ(tape.read(), 1);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 0);
    tape.moveRight();
    EXPECT_EQ(tape.read(), 1);
}


TEST(ProgramTest, LoadFromStreamCreatesInstructions) {
    std::stringstream ss;
    ss << "1 R 1\n";
    ss << "0 L -1\n";

    Program p;
    p.loadFromStream(ss);

    EXPECT_EQ(p.size(), 2);

    Instruction i0 = p.getInstruction(0);
    Instruction i1 = p.getInstruction(1);

    EXPECT_EQ(i0.write, 1);
    EXPECT_EQ(i0.next, 1);

    EXPECT_EQ(i1.write, 0);
    EXPECT_EQ(i1.next, -1);
}


TEST(MachineTest, StepExecutesInstruction) {
    std::stringstream ss;
    ss << "1 R -1\n";

    Machine machine(5, false);
    machine.loadProgram(ss);

    std::stringstream tapeInput("00000");
    machine.loadTape(tapeInput);

    machine.step();

    machine.step(); 
}

TEST(MachineTest, RunExecutesWholeProgram) {
    std::stringstream ss;
    ss << "1 R 1\n";
    ss << "0 L -1\n";

    Machine machine(5, true);
    machine.loadProgram(ss);

    std::stringstream tapeInput("00000");
    machine.loadTape(tapeInput);

    machine.run();
}

TEST(MachineTest, HandlesInvalidInstructionGracefully) {
    std::stringstream ss;
    ss << "1 R 10\n";

    Machine machine(3, true);
    machine.loadProgram(ss);
    std::stringstream tapeInput("000");
    machine.loadTape(tapeInput);

    machine.step();
}
