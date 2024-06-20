#ifndef _SingleLinkedList_H
#define _SingleLinkedList_H

#include "Node.h"
#include <string>

class SingleLinkedList
{
public:

	Node* m_head; // make private

	// default constructor
	SingleLinkedList();

	// methods
	Node* findNode(int flightNumber);
	void addNode(int flightNumber);
	void deleteNode(int position); // position is the position of the node in the linked list
};

#endif