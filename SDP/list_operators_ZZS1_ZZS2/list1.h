#ifndef __LIST_H
#define __LIST_H

template <class T>
struct Box
{
    T data;
    Box* next;
    Box();
    Box(T, Box*);
};


int cnt(Box<int>* l,int x);

Box<int>* range (int x, int y);

Box<int>*& removeAll(Box<int>*& l,int x);

template <class T>
void push(Box<T>*& first, T x);

template <class T>
void append(Box<T>*& l1, Box<T>* l2);

template <class T>
Box<T>* concat(Box<T> *l1, Box<T>* l2);

template <class T>
bool duplicates (Box<T> *l);

template <class T>
void removeduplicates (Box<T> *&l);

template <class T>
bool issorted (Box<T> *l);

template <class T>
bool palindrom (Box<T> *l);

#endif // __LIST_H
