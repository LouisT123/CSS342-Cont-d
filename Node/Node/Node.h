#ifndef NODE_
#define NODE_
#include <iostream> 

template<class ItemType>

class Node
{
private:
	ItemType        item; // A data item
	Node<ItemType>* next; // Pointer to next node

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	friend std::ostream& operator<<(std::ostream& Out, const Node& N);
}; // end Node

//#include "Node.cpp"  //if you include this line make sure your environment is not compiling the code twice.

#endif