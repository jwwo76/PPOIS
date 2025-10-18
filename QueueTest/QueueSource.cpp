#include "pch.h"
#include "Queue.h"

Queue::Queue() {
	begin_ = end_ = nullptr;
}

void Queue::enqueue(int info) {
	Node* node = new Node(info);

	if (!end_) {
		begin_ = end_ = node;
	}
	else {
		end_->setNext(node);
		end_ = node;
	}
}

void Queue::dequeue() {
	if (!begin_) return;

	Node* temp = begin_;
	begin_ = begin_->getNext();

	if (!begin_) {
		end_ = nullptr;
	}

	delete temp;
}

void Queue::display() const {
	if (!begin_) {
		cout << "Очередь пуста" << endl;
		return;
	}

	Node* current = begin_;
	while (current) {
		cout << current->getInfo() << " ";
		current = current->getNext();
	}
	cout << endl;
}

Queue::~Queue() {
	while (begin_) {
		Node* temp = begin_;
		begin_ = begin_->getNext();
		delete temp;
	}
	end_ = nullptr;
}



