#include <iostream>

#include "list.h"
#include "arrayiterator.h"
#include "stringiterator.h"
#include "functioniterator.h"

template <class T>
void process(BaseIterator<T>* iter)
{
    while(iter->more())
        std::cout << iter->getNext() << std::endl;

}

void testArrIter()
{
    int arr[4] = {0, 1, 2, 3};
    ArrayIterator<int> iter(arr, 4);
    process(&iter);

}

void testStrIter()
{
    char str[] = "this is a test";
    StringIterator iter(str);
    process(&iter);

}

double y; //trqbva da e globalna, za da moje rezultata da e ot tip E&, inache funkciqta square nqma da moje da go vru6ta
double& square(int x)
{
    y = x*x;
    return y;
}

void testFuncIter()
{
    FunctionIterator<double> iter(square, 30);
    process(&iter);
}

///////////////////////////////////
/*
void createList(Box<int>*& first)
{
    push<int>(first, 20);
    push<int>(first, 3);
    push<int>(first, 20);
    push<int>(first, 68);
    push<int>(first, 120);
    push<int>(first, 5);
}

void testList()
{
    Box<int>* first;
    createList(first);
    removeAll(first, 20);

}
*/
////////////////////////////////

int func(int x)
{
    return x*x;
}

void testList()
{

    List<int> l;
    l.push(5);
    l.push(14);
    l.push(29);
    l.push(5);
    l.push(5);
    std::cout << l.cnt(5) << std::endl;
    l.Map(func);
}

int main()
{

    //testArrIter();
    //testStrIter();
    //testFuncIter();
    testList();
    return 0;
}

