// test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node(int data);
	Node();
	~Node();
};

Node::Node(int data) {
	this->data = data;
}

Node::~Node() {
	cout << "deleting node (" << this->data << ")" << endl;
}

class Stack {
public:
	int capacity;
	int top;
	Node** nodes;
	Stack(int capacity);
	~Stack();

	void push(int data);
	int pop();
	bool isEmpty();
	int getSize();
};

Stack::Stack(int capacity) {
	this->nodes = new Node*[capacity];
	this->capacity = capacity;
	this->top = 0;
}

Stack::~Stack() {
	for (int i = 0; i < this->capacity; i++) {
		if (this->nodes[i]) {
			delete this->nodes[i];
		}
	}
	delete[] this->nodes;
}

void Stack::push(int data) {
	this->nodes[this->top++] = new Node(data);
	cout << "push: " << data << endl;
}

int Stack::pop() {
	int data = this->nodes[--(this->top)]->data;
	cout << "pop: " << data << endl;
	return data;
}

bool Stack::isEmpty() {
	return (this->top == 0);
}

int Stack::getSize() {
	return this->top - 1;
}



int main()
{
	Stack stack(30);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << "size: " << stack.getSize() << endl;

	stack.pop();
	stack.pop();

	cout << "empty: " << (stack.isEmpty() ? "true" : "false") << endl;
	stack.pop();
	cout << "empty: " << (stack.isEmpty() ? "true" : "false") << endl;

	return 0;
}

