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

	// methods
	Node* findNode(int flightNumber);
	void addNode(int flightNumber);
	void deleteNode(int position); // position is the position of the node in the single linked list

private:
	Node* m_head;
};

#endif