#include "NodePlus.h"

#include <string>

// default constructor
NodePlus::NodePlus()
{
	this->m_name = "";
	this->m_prev = nullptr; // nullptr
	this->m_next = nullptr;
}

// constructor with parameter for name
NodePlus::NodePlus(std::string name)
{
	this->m_name = name;
	this->m_prev = nullptr;
	this->m_next = nullptr;
}