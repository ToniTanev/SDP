#include "list.h"

#include <cstdlib>

template <class T>
Box<T>::Box() {next = NULL;}

template <class T>
Box<T>::Box(T _data, Box* _next) : data(_data), next(_next) {}

int cnt(Box<int>* l,int x)
{
    int br = 0;
    while(l != NULL) //inache nqma da obhodi posledniq element s while(l->next != NULL)
    {
        if(l->data == x)
            br++;
        l = l->next;
    }

    return br;
}

Box<int>* range (int x, int y)
{

    Box<int>* first = new Box<int>(x, NULL);

    Box<int>* prev = first;
    for(int i = x + 1; i <= y; i++)
    {
        Box<int>* tmp = new Box<int>(i, NULL);
        prev->next = tmp;
        prev = tmp;
    }
    return first;
}

Box<int>*& removeAll(Box<int>*& l,int x)
{
    Box<int>* first = l;
    while(first->next != NULL)
    {
        if(first->next->data == x)
        {
            Box<int>* tmp = first->next;
            first->next = tmp->next;
            delete tmp;
        }
        first = first ->next;
    }
    if(first->data == x)
        delete first;
    return l;
}


template <class T>
void push(Box<T>*& first, T x)
{
    first = new Box<T> (x,first);

}


template void push<int>(Box<int>*& first);
