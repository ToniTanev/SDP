#include "stringiterator.h"

#include <assert.h>

StringIterator::StringIterator(char* _str) : str(_str) {curr = 0;}

bool StringIterator::more() const
{
    return str[curr] != 0;
}

char& StringIterator::getNext()
{
    assert(more());
    return str[curr++];
}

bool StringIterator::hasPrevious() const
{
    return curr > 0;

}

char& StringIterator::getPrevious()
{
    assert(hasPrevious());
    return str[curr--];
}
