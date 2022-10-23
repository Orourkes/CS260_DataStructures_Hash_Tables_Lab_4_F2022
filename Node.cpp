#include <iomanip>
#include "Node.hpp"

Node::Node()
{
	storedVal = '0';
	next = nullptr;
	previous = nullptr;
}
Node::Node(string value)
{
	storedVal = value;
	next = nullptr;
	previous = nullptr;
}
Node* Node::getPrev() 
{ 
	return previous; //*previous will return the node, just previous will return the pointer to the node.
}