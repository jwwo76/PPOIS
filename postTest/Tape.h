#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Tape {
private:
    vector<int> cells;
    int head;     

public:
    Tape(int size = 100); 

    void moveLeft();
    void moveRight();

    int read() const;
    void write(int value);

    int getHead() const;
    void setHead(int pos);

    void loadFromStream(istream& in);

    void print(int range = 20) const;
};
