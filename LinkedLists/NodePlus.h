#ifndef _NodePlus_H
#define _NodePlus_H

#include <string>

class NodePlus
{
public:
	// default constructor
	NodePlus();

	// constructor with parameter
	NodePlus(std::string name);

	// destructor
	~NodePlus();

	// friend class (instead of getters and setters)
	friend class DoubleLinkedList;

private:
	std::string m_name;
	NodePlus* m_prev;
	NodePlus* m_next;
};

#endif