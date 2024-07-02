#include "Node.h"

#include <string>

Node::Node() // default constructor
{
	this->m_data = 0;
	this->m_next = nullptr; // setting to null since this is the last node in the list
	this->m_passengers = new DoubleLinkedList(); // setting to an empty dll so we can start using it
}

Node::Node(const int& data) // constructor accepting flight number data
{
	this->m_data = data;
	this->m_next = nullptr;
	this->m_passengers = new DoubleLinkedList();
}

Node::~Node() // destructor
{
	// delete the passengers list by calling DLL deconstructor
	delete m_passengers;
}
