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

	// methods
	NodePlus* findNode(std::string passenger);
	void addNodeAtHead(std::string passenger);
	void addNodeAtTail(std::string passenger);
	void deleteNode(NodePlus* passengerNode); // position is the position of the node in the linked list
	void bubbleSort();
	void printList();
	void printReverseList();
};

#endif