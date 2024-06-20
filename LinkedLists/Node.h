#ifndef _Node_H
#define _Node_H

#include "DoubleLinkedList.h"
#include <string>

class Node
{
public:

	int m_data;
	Node* m_next;
	DoubleLinkedList* m_passengers; // pointer to a DLL node

	// default constructor
	Node();

	// constructor with parameter
	Node(int data);
};

#endif