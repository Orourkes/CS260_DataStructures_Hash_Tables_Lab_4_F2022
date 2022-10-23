#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "ChainLink.hpp"

//This is not multi-thread safe.

ChainLink::ChainLink()
{
	//no nodes yet
	head = tail = findlast = nullptr;
}

/**************************
* Functions for Lab 3: base lab
* built moodle example
***************************/

void ChainLink::addHead(string newVal)
{
	//******************
	// otherwise, just add a new link at the head
	if (head != nullptr)
	{
		// create new link with nullptr for prev and head for next
		Node* temp = new Node(newVal);
		temp->setNext(head);
		// set first link and head to point to the new link
		head->setPrev(temp);
		head = temp;
	}
	// if the list is empty, initialize both head and tail
	else
		 head = tail = new Node(newVal);
		//*****************/
}
string ChainLink::getHead()
{
	if (head == nullptr)
	{
		indexError();
		return 0;
	}
	else
		return head->getValue();
}

bool ChainLink::removeHead()
{	//don't actually need to delete the value, value is now garbage, just like eveything was when created
		//******************
	
	if (head != nullptr)
	{
		if (head != tail)
		{
			// create new link with nullptr for prev and head for next
			Node *tempNode = head;
			if ((head->getNext()) != nullptr)
			{
				head = head->getNext();
				head->setPrev(nullptr);
			}
			else
				head = tail = nullptr;

			delete tempNode;
			return true;
		}
		else
		{
			if (head != nullptr)
			{
				Node* temp1 = head;
				head = tail = nullptr;
				return true;
			}
			return false;
		}
		return false;
	}
	// if the list is empty, initialize both head and tail
	else
		return false;
}

void ChainLink::addTail(string newVal)
{
	//******************
	// otherwise, just add a new link at the tail
	if (tail != nullptr)
	{
		// create new link with tail for prev and nullptr for next
		Node* temp = new Node(newVal);
		temp->setPrev(tail);
		// set first link and tail to point to the new link
		tail->setNext(temp);
		tail = temp;
	}
	// if the list is empty, initialize both head and tail
	else
		head = tail = new Node(newVal);
	//*****************/	
}

bool ChainLink::removeTail()
{	//don't actually need to delete the value, value is now garbage, just like eveything was when created
		//******************

	if (tail != nullptr)
	{
		if (tail != head)
		{
			// create new link with nullptr for prev and head for next
			Node* tempNode = tail;
			if ((tail->getPrev()) != nullptr)
			{
				tail = tail->getPrev();
				tail->setNext(nullptr);
			}
			else
				tail = head = nullptr;

			delete tempNode;
			return true;
		}
		else
		{
			if (tail != nullptr)
			{
				Node* temp1 = tail;
				tail = head = nullptr;
				delete temp1;
				return true;
			}
			return false;
		}
		return false;
	}
	// if the list is empty, initialize both head and tail
	else
		return false;
}

string ChainLink::getTail()
{
	if (tail == nullptr)
	{
		indexError();
		return 0;
	}
	else
		return tail->getValue();
}

std::string ChainLink::displayList()
{
	std::string outputArray;
	Node* temp = head;
	while (temp != tail)
	{
		outputArray += temp->getValue();
		outputArray += " ";
		temp = temp->getNext();
	}
	if(temp != NULL)
		outputArray += temp->getValue();
	return outputArray;
}
/***************************************
* 
* getFindLast function for debugging only
* 
****************************************/
//char ChainLink::getFindLast()
//{
//	if (findlast == nullptr)
//	{
//		indexError();
//		return 0;
//	}
//	else
//		return findlast->getValue();
//}

bool ChainLink::find(string findme)
{
	if(head == NULL)
		return false;
	Node* temp = head;
	while (temp != tail)
	{
		if (findme == temp->getValue())
			return true;
		temp = temp->getNext();
	}
	if (tail != NULL && findme == tail->getValue())
		return true;
	return false;
}
int ChainLink::findCount(string findme)
{
	int counter = 0;
	Node* temp = head;
	while (temp != tail)
	{
		if (findme == temp->getValue())
			counter++;
		temp = temp->getNext();
	}
	if (findme == temp->getValue())
		counter++;
	return counter;
}
Node* ChainLink::findNode(string findme)
{
	if (!find(findme))
		return 0;
	Node* temp = head;
	while (temp != tail)
	{
		if (findme == temp->getValue())
			return temp;
		else
			temp = temp->getNext();
	}
	if (findme == temp->getValue())
		return temp;
	throw std::out_of_range("Index Error");
	return 0;
}
Node* ChainLink::findNextNode(string findme)
{
	if (!find(findme))
		return 0;
	if (findlast == tail)
		findlast->setNext(head);
	Node* tempFindNext = findlast->getNext();
	while (tempFindNext != findlast)
	{
		if (tempFindNext->getValue() == findme)
		{
			findlast = tempFindNext;
			return findlast;
		}
		if (tempFindNext == tail)
			tempFindNext = head;
		else
			tempFindNext = tempFindNext->getNext();
	}
}
bool ChainLink::findNext(string findme)
{
	if (find(findme) == true) 
	{
		if ((findCount(findme) == 1) || (findlast == nullptr) || (findlast->getValue() != findme))
		{
			findlast = findNode(findme);
			findlast->setPrev(findNode(findme)->getPrev());
			return true;
		}
		else if (findCount(findme) > 1)
		{
			findNextNode(findme);
			return true;
		}
	}
	return false;

}
bool ChainLink::findRemove(string findme)
{
	if (find(findme)== true)
	{
		Node* temp = findNode(findme);
		if (temp == head)
		{
			removeHead();
			findlast = nullptr;
			return true;
		}
		else if (temp == tail)
		{
			removeTail();
			findlast = nullptr;
			return true;
		}
		else
		{
			temp->getPrev()->setNext(temp->getNext());
			temp->getNext()->setPrev(temp->getPrev());
			findlast = nullptr;
			//delete temp;
			return true;
		}
		return false;
	}
	return false;
}
bool ChainLink::removeLast()
{
	if (nullptr == findlast )
		return false;
	if (head == findlast)
	{
		removeHead();
		findlast = nullptr;
		return true;
	}
	if (tail == findlast)
	{
		removeTail();
		findlast = nullptr;
		return true;
	}
	else
	{
		(findlast->getNext())->setPrev(findlast->getPrev());
		findlast->getPrev()->setNext(findlast->getNext());
		
		findlast = nullptr;
		return true;
	}
	return false;

}

void ChainLink::append(const ChainLink *list)
{
	Node* temp = list->head;
	temp->setNext(list->head->getNext());
	while (temp != nullptr)
	{
		this->addTail(temp->getValue());
		temp = temp->getNext();
	}
}

bool ChainLink::insertLast(string nodeVal)
{
	if (findlast == nullptr)
		return false;

	Node* temp = findlast;
	if (temp == head)
	{
		addHead(nodeVal);
		return true;
	}
	else if (temp == tail)
	{
		addTail(nodeVal);
		return true;
	}
	else
	{
		// create new link with tail for prev and nullptr for next
		Node* newNode = new Node(nodeVal);
		findlast->getPrev()->setNext(newNode);
		newNode->setPrev(findlast->getPrev());
		newNode->setNext(findlast);
		// set first link and tail to point to the new link
		findlast->setPrev(newNode);
		//findlast->getPrev()->getPrev()->setNext(newNode);
		return true;
	}
	return false;
}
void ChainLink::indexError()
{
	throw std::out_of_range("Index Error");
}

//#endif