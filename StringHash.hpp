#pragma once
#include <iostream>
using namespace std;
#define BASE_SIZE 11

class StringHash
{
private:
	int arrSize;
	string *StringArray;

public:
	StringHash() { StringHash(BASE_SIZE); };
	StringHash(int);

	void fillEmpty(std::string []);
	void resize(int nSize);
	void addItem(string);
	bool findItem(string) { return false; }
	void removeItem(string);
	string displayTable();
};