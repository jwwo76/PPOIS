#pragma once
#include "Node.h"

class Queue {
private:
	Node* begin_;
	Node* end_;
public:
	Queue();
	void enqueue(int info);
	void dequeue();
	void display() const;
	~Queue();
};