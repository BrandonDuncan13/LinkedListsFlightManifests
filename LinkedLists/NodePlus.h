#ifndef _NodePlus_H
#define _NodePlus_H

#include <string>

class NodePlus
{
public:
	// default constructor
	NodePlus();
	// constructor with parameter
	NodePlus(const std::string& name);

	// destructor
	~NodePlus();

	// getter methods
	std::string getName() const
	{
		return m_name;
	}

	NodePlus* getNext() const
	{
		return m_next;
	}

	NodePlus* getPrev() const
	{
		return m_prev;
	}

	// friend class (instead of getters and setters)
	friend class DoubleLinkedList;

private:
	std::string m_name;
	NodePlus* m_prev;
	NodePlus* m_next;
};

#endif