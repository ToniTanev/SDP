#include "arrayiterator.h"

#include <assert.h>

template <class T>
ArrayIterator<T>::ArrayIterator(T* _arr, int _capacity) : arr(_arr), capacity(_capacity) {curr = 0;}

template <class T>
bool ArrayIterator<T>::more() const
{
    return curr < capacity;
}

template <class T>
T& ArrayIterator<T>::getNext()
{
    assert(more());
    return arr[curr++];
}

template <class T>
bool ArrayIterator<T>::hasPrevious() const
{
    return curr > 0;
}

template <class T>
T& ArrayIterator<T>::getPrevious()
{
    assert(hasPrevious());
    return arr[curr--];
}

template class ArrayIterator<int>; // tova tuk e pulen bullshit


