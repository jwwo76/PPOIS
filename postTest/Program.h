#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

enum class Move { Left, Right, Stay };

struct Instruction {
    int write; 
    Move move; 
    int next; 

class Program {
private:
    std::vector<Instruction> instructions;

public:
    void addInstruction(const Instruction& instr);
    void removeInstruction(int index);
    Instruction getInstruction(int index) const;
    int size() const;

    void loadFromStream(std::istream& in);
    void print() const;
};
