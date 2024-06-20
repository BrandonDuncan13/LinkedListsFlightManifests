#include "Node.h"

#include <string>

// default constructor
Node::Node()
{
	this->m_data = 0;
	this->m_next = nullptr;
	this->m_passengers = new DoubleLinkedList(); // setting to an empty dll so we can start using it
}

// constructor with parameter
Node::Node(int data)
{
	this->m_data = data;
	// on creating a new node next is set to null since this new node is last in the list
	this->m_next = nullptr;
	this->m_passengers = new DoubleLinkedList();
}