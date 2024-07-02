#include "DoubleLinkedList.h"

#include <string>
#include <iostream>

// default constructor
DoubleLinkedList::DoubleLinkedList() // the double linked list is created with 0 nodes
{
	this->m_head = nullptr;
	this->m_tail = nullptr;
}

// destructor
DoubleLinkedList::~DoubleLinkedList() // delete all passenger nodes in the list
{
	NodePlus* current = m_head;

	while (current != nullptr)
	{
		NodePlus* next = current->m_next;
		delete current;
		current = next;
	}
}

// methods
NodePlus* DoubleLinkedList::findNode(const std::string& passenger) // find a passenger node with a certain name
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

void DoubleLinkedList::addNodeAtHead(const std::string& passenger) // this function is only called by addNodeAtTail() but I figured it's good practice to have
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
	std::cout << "\nThe passenger " << passenger << " was added to the flight.\n" << std::endl;
}

void DoubleLinkedList::addNodeAtTail(const std::string& passenger) // add a passenger node to the end of the list
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
	std::cout << "\nThe passenger " << passenger << " was added to the flight.\n" << std::endl;

	bubbleSort(); // when a passenger is entered onto the double linked list the list will be sorted by passenger name
}

// Should just the passenger name be passed into the list??
void DoubleLinkedList::deleteNode(const std::string& passenger) // delete a specific passenger node from the list
{
	if (m_head == nullptr) // when the list is empty 
	{
		std::cout << "There are no passengers currently on this flight." << std::endl;

		return;
	}

	// find the node to be deleted
	NodePlus* current = findNode(passenger);

	if (current == nullptr) // if passenger node is not found in the list
	{
		std::cout << "The passenger you entered was not found on this flight. Please try again!\n" << std::endl;

		return;
	}

	if (current == m_head) // if node to be deleted is the head node
	{
		m_head = current->m_next;
		if (m_head != nullptr) // if there are more nodes in the list
		{
			m_head->m_prev = nullptr;
		}
		else // if the list becomes empty
		{
			m_tail = nullptr;
		}
	}
	else if (current == m_tail) // if node to be deleted is the tail node
	{
		m_tail = current->m_prev;
		if (m_tail != nullptr) // if there are more nodes in the list
		{
			m_tail->m_next = nullptr;
		}
	}
	else // node to be deleted is in the middle
	{
		current->m_next->m_prev = current->m_prev;
		current->m_prev->m_next = current->m_next;
	}

	// delete the current passenger node from the flight or list
	std::cout << "\nThe passenger " << current->m_name << " was deleted from the flight.\n" << std::endl;
	delete current;
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

void DoubleLinkedList::printList() // prints the passengers on flight in order
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

void DoubleLinkedList::printReverseList() // prints the passengers on flight in reverse order
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
