#include "Tape.h"
using namespace std;

Tape::Tape(int size) {
    cells.resize(size, 0);
    head = size / 2;
}

void Tape::moveLeft() {
    head--;
    if (head < 0) {
        cells.insert(cells.begin(), 0);
        head = 0;
    }
}

void Tape::moveRight() {
    head++;
    if (head >= (int)cells.size())
        cells.push_back(0);
}

int Tape::read() const {
    if (head < 0 || head >= (int)cells.size()) return 0;
    return cells[head];
}

void Tape::write(int value) {
    if (head < 0) head = 0;
    if (head >= (int)cells.size()) cells.resize(head + 1, 0);
    cells[head] = value;
}

int Tape::getHead() const {
    return head;
}

void Tape::setHead(int pos) {
    if (pos >= 0) head = pos;
}

void Tape::loadFromStream(std::istream& in) {
    std::string line;
    if (std::getline(in, line)) {
        cells.clear();
        for (char c : line)
            cells.push_back(c == '1' ? 1 : 0);
        head = 0; 
    }
}


void Tape::print(int range) const {
    for (int i = head - range; i <= head + range; i++) {
        if (i < 0 || i >= (int)cells.size())
            cout << " _ ";
        else if (i == head)
            cout << "[" << (cells[i] ? "1" : "_") << "]";
        else
            cout << " " << (cells[i] ? "1" : "_") << " ";
    }
    cout << endl;
}
