#include "DoubleLinkedList.h"

#include <string>
#include <iostream>

// default constructor
DoubleLinkedList::DoubleLinkedList()
{
	// the double linked list is created with 0 nodes
	this->m_head = nullptr;
	this->m_tail = nullptr;
}

// methods
NodePlus* DoubleLinkedList::findNode(std::string passenger)
{
	NodePlus* current = m_head;

	if (current == nullptr)
	{
		return nullptr; // position variable will be set to the return value
	}

	// this while loop runs while a node's name isn't passenger and node's next isn't pointing to NULL
	while (current->m_name != passenger && current->m_next != nullptr)
	{
		current = current->m_next;
	}

	if (current->m_name != passenger)
	{
		return nullptr;
	}

	return current;
}

void DoubleLinkedList::addNodeAtHead(std::string passenger) // this function is only called by addNodeAtTail() but I figured it's good practice to have
{
	// instantiating a new node
	NodePlus* node = new NodePlus(passenger);

	node->m_next = m_head;

	if (m_head != nullptr)
	{
		m_head->m_prev = node;
	}
	else
	{
		// when there are no nodes in the list
		m_tail = node;
	}

	// sets head to the new node which takes care of all situations
	m_head = node;
	std::cout << "\nThe passenger " << passenger << " was added to the flight." << std::endl;
}

void DoubleLinkedList::addNodeAtTail(std::string passenger)
{
	// handles the case of an empty list
	if (m_head == nullptr)
	{
		// a node gets created and head and tail are set to that node
		addNodeAtHead(passenger);
		return;
	}

	NodePlus* current = m_head;

	// traverses through the double linked list
	// checks to see if passenger already exists
	while (current->m_next != nullptr)
	{
		if (current->m_name == passenger)
		{
			std::cout << passenger << " is already on this flight.\n" << std::endl;
			return;
		}
		current = current->m_next;
	}
	if (current->m_name == passenger)
	{
		std::cout << passenger << " is already on this flight.\n" << std::endl;
		return;
	}
	NodePlus* node = new NodePlus(passenger);
	
	current->m_next = node;
	node->m_prev = current;
	m_tail = node; // the tail is updated
	std::cout << "\nThe passenger " << passenger << " was added to the flight." << std::endl;

	bubbleSort(); // when a passenger is entered onto the double linked list the list will be sorted by passenger name
}

void DoubleLinkedList::deleteNode(NodePlus* passengerNode)
{
	// when the list is empty or the node isn't found
	if (m_head == nullptr || passengerNode == nullptr)
	{
		std::cout << "Either the list is empty or the node does not exist." << std::endl;
		return;
	}

	NodePlus* current = findNode(passengerNode->m_name);
	// if node is not found
	if (current == nullptr)
	{
		return;
	}
	// if node to be deleted is the head node
	if (current == m_head)
	{
		// if there's only one node in the list
		if (m_head == m_tail)
		{
			m_tail = nullptr;
		}
		m_head = current->m_next;
	}
	// change next if node to be deleted is not last node
	if (current->m_next != nullptr)
	{
		current->m_next->m_prev = current->m_prev;
	}
	// change prev if node to be deleted is not first node
	if (current->m_prev != nullptr)
	{
		current->m_prev->m_next = current->m_next;
	}
	// if node to be deleted is the tail node
	if (current == m_tail)
	{
		// the tail is set to the 2nd to last node so last node can be deleted
		m_tail = current->m_prev;
	}
	// delete the current node which is at the specified position
	delete current;
	return;
}

void DoubleLinkedList::bubbleSort() // sorting the double linked list by the passenger names using a bubble sort
{
	int swapped, i;
	NodePlus* head = m_head;
	NodePlus* ptr1;
	NodePlus* lptr = nullptr;

	/* Checking for empty list */
	if (head == nullptr)
	{
		return;
	}

	do
	{
		swapped = 0;
		ptr1 = head;

		while (ptr1->m_next != lptr)
		{
			if (ptr1->m_name > ptr1->m_next->m_name)
			{
				swap(ptr1->m_name, ptr1->m_next->m_name);
				swapped = 1;
			}
			ptr1 = ptr1->m_next;
		}
		lptr = ptr1;
	} while (swapped);
}

void DoubleLinkedList::printList()
{
	NodePlus* head = m_head;

	if (head == nullptr)
	{
		std::cout << "There are currently no passengers on this flight.\n" << std::endl;
		return;
	}
	
	while (head->m_next != nullptr) // cycles through flight's passengers list, printing each passenger
	{
		std::cout << "Name: " << head->m_name << std::endl;
		head = head->m_next;
	}
	// there is one more passenger to print out
	std::cout << "Name: " << head->m_name << "\n" << std::endl;

	return;
}

void DoubleLinkedList::printReverseList()
{
	NodePlus* tail = m_tail;

	if (tail == nullptr)
	{
		std::cout << "There are currently no passengers on this flight.\n" << std::endl;
		return;
	}

	while (tail->m_prev != nullptr) // cycles through flight's passengers list, printing each passenger starting at the tail
	{
		std::cout << "Name: " << tail->m_name << std::endl;
		tail = tail->m_prev;
	}

	// there is one more passenger to print out
	std::cout << "Name: " << tail->m_name << "\n" << std::endl;

	return;
}