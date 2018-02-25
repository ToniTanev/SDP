#ifndef __ARRAYITERATOR_H
#define __ARRAYITERATOR_H

#include "baseiterator.h"

template <class T>
class ArrayIterator : public BaseIterator<T>
{
private:

    T* arr;
    int curr;
    int capacity;

public:

    ArrayIterator(T* , int );
    T& getNext();
    bool more() const;
    T& getPrevious();
    bool hasPrevious() const;

};

#endif // __ARRAYITERATOR_H
