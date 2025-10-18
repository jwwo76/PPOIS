#include "pch.h"
#include "Program.h"
using namespace std;

void Program::addInstruction(const Instruction& instr) {
    instructions.push_back(instr);
}

void Program::removeInstruction(int index) {
    if (index >= 0 && index < (int)instructions.size())
        instructions.erase(instructions.begin() + index);
}

Instruction Program::getInstruction(int index) const {
    if (index >= 0 && index < (int)instructions.size())
        return instructions[index];
    return { 0, Move::Stay, -1 };
}

int Program::size() const {
    return (int)instructions.size();
}

void Program::loadFromStream(istream& in) {
    instructions.clear();
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int w, next;
        char moveChar;
        ss >> w >> moveChar >> next;
        Move mv;
        if (moveChar == 'L') mv = Move::Left;
        else if (moveChar == 'R') mv = Move::Right;
        else mv = Move::Stay;
        instructions.push_back({ w, mv, next });
    }
}

void Program::print() const {
    for (int i = 0; i < (int)instructions.size(); i++) {
        cout << i << ": write=" << instructions[i].write
            << ", move=" << (instructions[i].move == Move::Left ? "L" :
                instructions[i].move == Move::Right ? "R" : "S")
            << ", next=" << instructions[i].next << endl;
    }
}
