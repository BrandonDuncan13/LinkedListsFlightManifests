#ifndef _NodePlus_H
#define _NodePlus_H

#include <string>

class NodePlus
{
public:

	std::string m_name;
	NodePlus* m_prev;
	NodePlus* m_next;

	// default constructor
	NodePlus();

	// constructor with parameter
	NodePlus(std::string name);
};

#endif