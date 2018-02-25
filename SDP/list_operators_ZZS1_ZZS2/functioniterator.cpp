#include "functioniterator.h"

#include <assert.h>

template <class E>
FunctionIterator<E>::FunctionIterator(E& (* _f) (int), int _cnt) : f(_f), cnt(_cnt) {curr = 0;}

template <class E>
bool FunctionIterator<E>::more() const
{
    return curr < cnt;
}

template <class E>
E& FunctionIterator<E>::getNext()
{
    assert(more());
    int tmp = curr;
    curr++;
    return f(tmp);
}

template <class E>
bool FunctionIterator<E>::hasPrevious() const
{
    return curr > 0;
}

template <class E>
E& FunctionIterator<E>::getPrevious()
{
    assert(hasPrevious());
    int tmp = curr;
    curr--;
    return f(tmp);
}

template class FunctionIterator<double>; //bullshit once again
