#include "listiterator.h"

#include <assert.h>
#include <cstdlib>

template <class T>
ListIterator<T>::ListIterator(Box<T>* _first) : first(_first) {curr = _first;}

template <class T>
bool ListIterator<T>::more() const
{
    return curr->next != NULL;
}

template <class T>
T& ListIterator<T>::getNext()
{
    assert(more());
    Box<T>* tmp = curr;
    curr = curr->next;
    return tmp->data;
}
template <class T>
T& ListIterator<T>::getPrevious(){}

template <class T>
bool ListIterator<T>::hasPrevious() const {return 1;}

template class ListIterator<int>;
