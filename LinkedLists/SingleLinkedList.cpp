#include "SingleLinkedList.h"

#include <string>
#include <iostream>

// default constructor
SingleLinkedList::SingleLinkedList()
{
	// when a linked list is created it has no nodes inside of it
	m_head = nullptr;
}

// method definitions
Node* SingleLinkedList::findNode(int flightNumber)
{
	Node* current = m_head;

	if (current == nullptr)
	{
		return nullptr; // position variable will be set to the return value
	}
	
	while (current != nullptr)
	{
		if (current->m_data == flightNumber)
		{
			return current;
		}
		current = current->m_next;
	}
	// if the flight number is not found we return a sentinel value
	return nullptr;
}

// new nodes will only be added to the end of the list
void SingleLinkedList::addNode(int flightNumber)
{
	// create a new node
	Node* node = new Node(flightNumber); // here m_dll is set to point to NULL

	// add a node when the list is empty
	if (m_head == nullptr)
	{
		m_head = node;

		return;
	}

	Node* current = m_head;
	// traversing through the linked list
	while (current->m_next != nullptr)
	{
		// update current
		current = current->m_next;
	}
	// now you should be at the end of the linked list
	// the new node is added to the end of the list and it's next is already pointing to NULL
	current->m_next = node;
}

void SingleLinkedList::deleteNode(int position)
{
	Node* current = m_head;
	int i;

	if (position == -1)
	{
		std::cout << "Cannot delete node because either the list is empty or it wasn't found." << std::endl;
		return;
	}
	else if (position == 0)
	{
		// when we want to delete the head node we move the head to next node
		m_head = current->m_next;
		delete current;
		return;
	}
	else
	{
		// getting temp to point at the position 1 less than the desired
		for (i = 0; i <= (position - 1); i++)
		{
			current = current->m_next;
		}

		Node* d = current->m_next; // desired node

		// node before the node being deleted will now point to the node after the node being deleted
		// temp1's next will point to NULL if d's next points to NULL
		current->m_next = d->m_next;
		// deletes node d
		delete d;
	}
}