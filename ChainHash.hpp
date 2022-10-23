#pragma once
#include <iostream>
#include <string>
#include "ChainLink.hpp"
using namespace std;
#define HTable_SIZE 7

class ChainHash
{
private:
	int arrSize;
	int counter = 0;
	ChainLink** ChainArray;
	string strEmpty = "_empty_";
	int findEmptyIndex(string);
	int findFilledIndex(string);
	int Hash(string);
	void resize();
	void getNextPrime();

public:
	ChainHash();
	ChainHash(int);
	~ChainHash() { delete ChainArray; }

	void addItem(string);
	bool findItem(string);
	void removeItem(string);
	string displayTable();
};