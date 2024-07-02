#ifndef _SingleLinkedList_H
#define _SingleLinkedList_H

#include "Node.h"
#include <string>

class SingleLinkedList
{
public:
	// default constructor
	SingleLinkedList();

	// Destructor
	~SingleLinkedList();

	// getter method
	Node* getHead() const
	{
		return m_head;
	}

	// methods
	Node* findNode(const int& flightNumber);
	void addNode(const int& flightNumber);
	void deleteNode(int position); // position is the position of the node in the single linked list

private:
	Node* m_head;
};

#endif