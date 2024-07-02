#include "NodePlus.h"

#include <string>

// default constructor
NodePlus::NodePlus() // creates a passenger node with no name or attached nodes
{
	this->m_name = "";
	this->m_prev = nullptr; // nullptr
	this->m_next = nullptr;
}

// constructor with parameter for name
NodePlus::NodePlus(const std::string& name)
{
	this->m_name = name;
	this->m_prev = nullptr;
	this->m_next = nullptr;
}

// destructor
NodePlus::~NodePlus() // nothing to do here but good practice to have
{
	
}
