#pragma once
#include <string>
using namespace std;

class Node
{
private:
	string storedVal;
	Node* next;
	Node* previous;

public:
	Node();
	Node(string value);
	
//protected:


	~Node() {}

	string getValue() { return storedVal; }

	void setValue(string newVal) { storedVal = newVal; }

	Node* getNext() { return next; }

	Node* getPrev();

	void setNext(Node* newNext) { next = newNext; }

	void setPrev(Node* newPrev) { previous = newPrev; }

};