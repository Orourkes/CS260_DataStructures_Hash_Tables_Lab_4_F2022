#pragma once
#include <iostream>
#include <string>
using namespace std;
#define CONST_SIZE 11

class StringHash
{
private:
	int arrSize;
	string strEmpty = "_empty_";
	string strDelete = "_deleted_";
	string** StringArray;
	int counter = 0;
	int findEmptyIndex(string);
	int findFilledIndex(string);
	int Hash(string);

public:
	StringHash();
	StringHash(int);
	~StringHash() {	delete StringArray;	}
	void fillEmpty();
	void resize(int nSize);
	void addItem(string);
	bool findItem(string);
	void removeItem(string);
	string displayTable();
};