#include "Machine.h"
#include <iostream>
using namespace std;

Machine::Machine(int tapeSize, bool log)
    : tape(tapeSize), logging(log), currentInstr(0) {
}

void Machine::loadProgram(istream& in) {
    program.loadFromStream(in);
    currentInstr = 0;
}

void Machine::loadTape(istream& in) {
    tape.loadFromStream(in);
}

void Machine::step() {
    if (currentInstr < 0 || currentInstr >= program.size()) {
        cout << "Программа завершена." << endl;
        currentInstr = -1;
        return;
    }

    Instruction instr = program.getInstruction(currentInstr);

    tape.write(instr.write);

    switch (instr.move) {
    case Move::Left:  tape.moveLeft(); break;
    case Move::Right: tape.moveRight(); break;
    case Move::Stay:  break;
    }

    currentInstr = instr.next;

    if (currentInstr < 0 || currentInstr >= program.size()) {
        currentInstr = -1;
        cout << "Программа завершена." << endl;
    }
}

void Machine::run() {
    while (currentInstr != -1) {
        printState();
        step();
    }
}

void Machine::printState() const {
    cout << "Текущая инструкция: " << currentInstr << endl;
    tape.print(10);
    cout << "----------------------" << endl;
}
