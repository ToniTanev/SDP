#ifndef __STRINGITERATOR_H
#define __STRINGITERATOR_H

#include "baseiterator.h"

class StringIterator : public BaseIterator<char>
{

private:

    char* str;
    int curr;
    //nqma nujda ot capacity, poneje e zero ended string
public:

    StringIterator(char* );
    char& getNext();
    bool more() const;
    char& getPrevious();
    bool hasPrevious() const;


};


#endif // __STRINGITERATOR_H
