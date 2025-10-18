#pragma once
#include "Tape.h"
#include "Program.h"

class Machine {
private:
    Tape tape;          
    Program program;    
    int currentInstr;   
    bool logging;       
public:
    Machine(int tapeSize = 100, bool log = false);

    void loadProgram(std::istream& in);

    void loadTape(std::istream& in);

    void step();

    void run();

    void printState() const;
};
