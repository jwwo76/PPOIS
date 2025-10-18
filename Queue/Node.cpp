#include "Node.h"

Node::Node(int info) {
	info_ = info;
	this->next_ = nullptr;
}

Node* Node::getNext() {
	return next_;
}

int Node::getInfo() {
	return info_;
}

void Node::setNext(Node* node) {
	this->next_ = node;
}