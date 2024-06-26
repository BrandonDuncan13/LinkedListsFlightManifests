#ifndef _DoubleLinkedList_H
#define _DoubleLinkedList_H

#include "NodePlus.h"
#include <string>

class DoubleLinkedList
{
public:

	NodePlus* m_head;
	NodePlus* m_tail;

	// default constructor
	DoubleLinkedList();

	// destructor
	~DoubleLinkedList();

	// methods
	NodePlus* findNode(std::string passenger);
	void addNodeAtHead(std::string passenger);
	void addNodeAtTail(std::string passenger);
	void deleteNode(std::string passenger);
	void bubbleSort();
	void printList();
	void printReverseList();
};

#endif