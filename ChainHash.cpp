#include <iomanip>
#include <stdexcept>
#include <string>
#include "ChainHash.hpp"
#include "ChainLink.hpp"

ChainHash::ChainHash()
{
	arrSize = HTable_SIZE;
	ChainArray = new ChainLink * [arrSize];
	for (int i = 0; i < arrSize; i++)
		ChainArray[i] = NULL;
}
void ChainHash::addItem(string a)
{
	if (counter >= (arrSize * 2))
	{
		resize();
	}
	int location = Hash(a);
	if (ChainArray[location] == NULL)
		ChainArray[location] = new ChainLink;
	ChainArray[location]->addHead(a);
	counter++;

}
int ChainHash::Hash(string a)
{
	int hashValue = 0;

	for (int i = 0; i < a.length(); i++)
	{
		hashValue *= 128;
		hashValue += a[i];
		hashValue %= arrSize;

	}
	return hashValue;
}
bool ChainHash::findItem(string a)
{
	int index = Hash(a);
	if (ChainArray[index] != NULL)
		return ChainArray[index]->find(a);
	return false;
}
void ChainHash::removeItem(string a)
{
	int index = Hash(a);
	if (ChainArray[index] != NULL)
	{
		ChainArray[index]->findRemove(a);
		counter--;
	}
}
string ChainHash::displayTable()
{
	string retStr;
	for (int i = 0; i < arrSize; i++)
	{
		if (ChainArray[i] != NULL)
			retStr += ChainArray[i]->displayList() + " \n";
		else
			retStr += strEmpty + "\n";
		
	}
	return retStr;
}
void ChainHash::getNextPrime()
{
	bool isprime = false;
	while (!isprime)
	{
		isprime = true;
		arrSize++;
		for (int i = 2; i < arrSize; i++)
		{
			if (arrSize % i == 0)
				isprime = false;
		}
	}
}

void ChainHash::resize()
{
	//check new size vs current size. 
	ChainLink** newArray = ChainArray;
	int oldArrSize = arrSize;
	getNextPrime();
	counter = 0;
	ChainArray = new ChainLink * [arrSize];
	for (int i = 0; i < arrSize; i++)
		ChainArray[i] = NULL;
	//Copy over old array to new array
	for (int i = 0; i < oldArrSize; i++)
	{
		if (newArray[i] != NULL)
		{
			while (!newArray[i]->isEmpty())
			{
				addItem(newArray[i]->getHead());
				newArray[i]->removeHead();
			}
		}
	}
	//arrSize = newSize;
	delete newArray;
}