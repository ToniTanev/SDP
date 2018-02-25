#ifndef __LISTITERATOR_H
#define __LISTITERATOR_H

#include "baseiterator.h"
#include "list.h"


template <class T>
class ListIterator : public BaseIterator<T>
{
private:

    Box<T>* first;
    Box<T>* curr;

public:

    ListIterator(Box<T>*);
    T& getNext();
    bool more() const;
    T& getPrevious();
    bool hasPrevious() const;
};

#endif // __LISTITERATOR_H
