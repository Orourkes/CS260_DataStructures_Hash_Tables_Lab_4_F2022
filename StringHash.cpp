#include <iomanip>
#include <stdexcept>

#include "StringHash.hpp"


StringHash::StringHash(int nSize = BASE_SIZE)
{
	arrSize = BASE_SIZE;
	StringArray = new string[arrSize];
	fillEmpty(StringArray);
}
void StringHash::fillEmpty(string StringArray[])
{
	for (int i = 0; i < arrSize; i++)
		StringArray[i] = "empty";
}

void StringHash::removeItem(string sValue)
{

}

void StringHash::resize(int newSize)
{
	//check new size vs current size.
	//if(newSize < size)
		//throw assert double check instructions

	/****
	int* newArray = new int[newSize];
	//Copy over old array to new array
	for (int i = 0; i < usedElements; i++)
	{
		newArray[i] = theArray[head];
		head = modTracker(head);
	}
	delete theArray;
	theArray = newArray;
	head = 0;
	tail = usedElements;
	size = newSize;
	*****/
}

string StringHash::displayTable()
{
	string retStr = "";
	int i = 0;
	for(i; i < arrSize; i++)
	{
		retStr += StringArray[i];
		retStr += ", ";
	}
	return retStr;
}