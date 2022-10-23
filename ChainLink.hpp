#pragma once
#include "Node.hpp"
#include <string>
using namespace std;
class ChainLink:Node
{

private:
	Node* head;
	Node* tail;
	Node* findlast;

public:
	ChainLink();
	~ChainLink() { while (removeHead()); };

/**************************
* Functions for base lab
* 
***************************/
	void indexError();
	void addTail(string newVal);
	void addHead(string newVal);
	string getTail();
	string getHead();
//	char getFindLast(); //used for debugging;
	bool removeTail();
	bool removeHead();
	bool find(string);
	int findCount(string);
	Node* findNode(string);
	Node* findNextNode(string);
	bool findNext(string);
	bool findRemove(string);
	bool removeLast();
	void append(const ChainLink*);
	void deletelist(){ while (removeHead()); }
	//int modTracker(int headsOrTails) { return ((headsOrTails + 1) % ); }
	std::string displayList();
	bool insertLast(string);

	bool isEmpty() { return (head == NULL); }
#ifdef CLEAN_UP
#endif
};
