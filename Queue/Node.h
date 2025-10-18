#pragma once

#include <iostream>
using namespace std;


class Node {
private:
	int info_;
	Node* next_;
public:
	Node(int info);
	Node* getNext();
	int getInfo();
	void setNext(Node* node);
};