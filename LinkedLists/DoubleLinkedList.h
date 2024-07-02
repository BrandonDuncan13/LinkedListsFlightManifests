#ifndef _DoubleLinkedList_H
#define _DoubleLinkedList_H

#include "NodePlus.h"
#include <string>

class DoubleLinkedList
{
public:
	// default constructor
	DoubleLinkedList();

	// destructor
	~DoubleLinkedList();

	// getter methods
	NodePlus* getHead() const
	{
		return m_head;
	}

	NodePlus* getTail() const // not used in this program but good practice to have
	{
		return m_tail;
	}

	// methods
	NodePlus* findNode(const std::string& passenger);
	void addNodeAtHead(const std::string& passenger);
	void addNodeAtTail(const std::string& passenger);
	void deleteNode(const std::string& passenger);
	void bubbleSort();
	void printList();
	void printReverseList();

private:
	NodePlus* m_head;
	NodePlus* m_tail;
};

#endif