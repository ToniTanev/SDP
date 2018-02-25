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

template <class T>
class List
{
private:

    Box<T>* first;

public:

    List();
    List(Box<T>* );
    void push(T );
    int cnt(int ) const;
    void Map(int (*) (int));
    bool duplicates() const;
    bool isSorted() const;
    bool palindrom() const;

};


#endif
