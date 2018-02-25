#ifndef __BASEITERATOR_H
#define __BASEITERATOR_H

template <class T>
class BaseIterator
{
public:

    virtual T& getNext() = 0;
    virtual bool more() const = 0;
    virtual T& getPrevious() = 0;
    virtual bool hasPrevious() const = 0;

};

#endif // __BASEITERATOR_H
