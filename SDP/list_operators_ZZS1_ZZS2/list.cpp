#include "list.h"
#include "listiterator.h"

#include <iostream>
#include <cstdlib>
#include <vector>

template <class T>
Box<T>::Box() {next = NULL;}

template <class T>
Box<T>::Box(T _data, Box* _next) : data(_data), next(_next) {}

template <class T>
List<T>::List() {first = NULL;}

template <class T>
List<T>::List(Box<T>* _first) : first(_first) {};

template <class T>
void List<T>::push(T _data)
{
    first = new Box<T>(_data, first);
}

template <> //kogato specializirash tipa, trqbva da ostavish prosto prazni skobi <>
int List<int>::cnt(int x) const
{
    int br = 0;
    Box<int>* tmp = first;
    while(tmp != NULL)
    {
        if(tmp->data == x)
            br++;
        tmp = tmp->next;
    }
    return br;
}

template <>
void List<int>::Map(int (*f ) (int ))
{
    ListIterator<int> iter(first);
    while(iter.more())
        std::cout << f(iter.getNext()) << std::endl;

}

template <class T>
bool List<T>::duplicates() const
{
    ListIterator<T> iter(first);
    ListIterator<T> iter2(first);
    while(iter.more())
    {
        while(iter2.more())
        {

        }
    }
}


template class List<int>;

