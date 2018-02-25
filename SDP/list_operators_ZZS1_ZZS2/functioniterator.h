#ifndef __FUNCTIONITERATOR_H
#define __FUNCTIONITERATOR_H

#include "baseiterator.h"

template<class E>
class FunctionIterator : public BaseIterator<E>
{
private:

    E& (* f) (int );
    int cnt; //broi izkarani elementi
    int curr;

public:

    FunctionIterator(E& (* ) (int), int  );
    E& getNext();
    bool more() const;
    E& getPrevious();
    bool hasPrevious() const;

};


#endif
