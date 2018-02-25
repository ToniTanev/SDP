#ifndef __LISTITERATOR_H
#define __LISTITERATOR_H


#include "list.cpp"

#include <cassert>

class ListIterator
{
private:
	Box* current;
public:
	ListIterator() : current(nullptr) {}
	ListIterator(Box* start) : current(start) {}
	bool more() const
	{
		return current != nullptr;
	}
	int& operator*()  //за да може да се променя стойността 
	{
		return current->data;
	}
	void operator++()
	{
		//assert(more());
		if(current != nullptr)
			current = current->next;
	}
	Box* getCurrent() const
	{
		return current;
	}
};

int count2(Box* l, int x)
{
	int br = 0;
	ListIterator iter(l);
	while(iter.more())
	{
		if(*iter == x)
			br++;
		++iter;
		
	}
	return br;
}


void map2(Box*& l, int (*f)(int))
{
	ListIterator iter(l);
	while(iter.more())
	{
		*iter = f(*iter);
		++iter;
	}

}
#endif