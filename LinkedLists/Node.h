#ifndef _Node_H
#define _Node_H

#include "DoubleLinkedList.h"
#include <string>

class Node
{
public:
	// pointer to a DLL node
	DoubleLinkedList* m_passengers;

	// default constructor
	Node();

	// constructor with parameter
	Node(int data);

	// destructor
	~Node();

	// friend class (instead of getters and setters)
	friend class SingleLinkedList;

private:
	int m_data;
	Node* m_next;
};

#endif