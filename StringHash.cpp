#include <iomanip>
#include <stdexcept>
#include <string>
#include "StringHash.hpp"

StringHash::StringHash()
{
	arrSize = CONST_SIZE;
	StringArray = new string* [arrSize];
	fillEmpty();
}

StringHash::StringHash(int nSize)
{
	arrSize = nSize;
	StringArray = new string * [arrSize];
	fillEmpty();

}

void StringHash::fillEmpty()
{
	for (int i = 0; i < arrSize; i++)
		StringArray[i] = &strEmpty;
}

void StringHash::removeItem(string sValue)
{
	int removeIndex = findFilledIndex(sValue); //;
	if (removeIndex != -1)
	{
		StringArray[removeIndex] = &strDelete;
		counter--;
	}
		return;

}

void StringHash::resize(int newSize)
{
	//check new size vs current size.
	if (newSize < arrSize)
	{
		return;//throw exception or assert? double check instructions
	}
	string** newArray = StringArray;
	int oldArrSize = arrSize;
	arrSize = newSize;
	counter = 0;
	StringArray = new string* [newSize];
	fillEmpty();
	//Copy over old array to new array
	for (int i = 0; i < oldArrSize; i++)
	{
		if (newArray[i] != &strEmpty && newArray[i] != &strDelete)
			addItem(*newArray[i]); 
	}
	//arrSize = newSize;
	delete newArray;
	}
void StringHash::addItem(string a)
{
	if (counter >= (arrSize / 2))
	{
		resize(arrSize * 2);
	}
	StringArray[findEmptyIndex(a)] = new string(a);
	counter++;
	return;
}

int StringHash::findEmptyIndex(string a)
{
	int strCalcTot = Hash(a);
	//for (int i = 0; i < a.length(); i++)
	//	strCalcTot += static_cast<int>(a[i]);
	//strCalcTot = strCalcTot % arrSize;
	int startIndex = (strCalcTot - 1) % arrSize;
	while ((*StringArray[strCalcTot] != strEmpty) && startIndex != strCalcTot)
	{
		strCalcTot = (strCalcTot + 1) % arrSize;
	}
	return strCalcTot;
}
int StringHash::Hash(string a)
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
int StringHash::findFilledIndex(string a)
{
	int strCalcTot = Hash(a);
	//for (int i = 0; i < a.length(); i++)
	//	strCalcTot += static_cast<int>(a[i]);
	//strCalcTot = strCalcTot % arrSize;
	int startIndex = (strCalcTot - 1) % arrSize;
	while ((*StringArray[strCalcTot] != a) && (startIndex + 0) != strCalcTot)
	{
		if(*StringArray[strCalcTot] == strEmpty)
			return -1;
		strCalcTot = (strCalcTot + 1) % arrSize;
	}
	if ((startIndex) == strCalcTot)
		return -1;

	return strCalcTot;
}
bool StringHash::findItem(string a)
{ 
	return findFilledIndex(a) != -1 ;
}


string StringHash::displayTable()
{
	std::string retStr = "";
	int i = 0;
	for(i; i < arrSize; i++)
	{
		retStr += *StringArray[i];
		retStr += " ";
	}
	return retStr;
}