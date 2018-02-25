#include <iostream>

#include "btree.cpp"


void testBuild ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);


  t7.insertElement ("LL",100);
  //std::cout << t7;

}

void testTrace ()
{
  BTree<int> t;

  t.insertElement ("",10);
  t.insertElement ("L",20);

  //std::cout << t;
}

void testBOT ()
{
  BTree<int> t;

  t.insertBOT (10);
  t.insertBOT (20);
  t.insertBOT (5);
  t.insertBOT (25);
  t.insertBOT (37);
  t.insertBOT (49);
  t.insertBOT (72);

  //std::cout << t;

}

void testCnt()
{
    BTree<int> t;

    t.insertBOT (10);
    t.insertBOT (20);
    t.insertBOT (5);
    t.insertBOT (25);
    t.insertBOT (37);
    t.insertBOT (49);
    t.insertBOT (72);
    std::cout << t.cnt() << std::endl;

}

template <class T>
bool pred(const T& x)
{

   return x%2 == 0;

}

void testSearchCount()
{
    BTree<int> t;

    t.insertBOT (10);
    t.insertBOT (20);
    t.insertBOT (5);
    t.insertBOT (25);
    t.insertBOT (37);
    t.insertBOT (49);
    t.insertBOT (72);
    std::cout << t.searchCount(pred<int>) << std::endl;
}

void testHeight()
{
    BTree<int> t;

    t.insertBOT (10);
    t.insertBOT (20);
    t.insertBOT (30);
    t.insertBOT (40);
    t.insertBOT (2);
    t.insertBOT (3);

    std::cout << t.height() << std::endl;
}

void testCountLeaves()
{
    BTree<int> t;

    t.insertBOT (10);
    t.insertBOT (20);
    t.insertBOT (30);
    t.insertBOT (40);
    t.insertBOT (2);
    t.insertBOT (3);
    t.insertBOT (1);

    std::cout << t.countLeaves() << std::endl;
}

void testMaxLeaf()
{

    BTree<int> t;

    t.insertBOT (10);
    t.insertBOT (20);
    t.insertBOT (30);
    t.insertBOT (40);
    t.insertBOT (2);
    t.insertBOT (3);
    t.insertBOT (1);

    std::cout << t.maxLeaf() << std::endl;
}

void testGetElement()
{

    BTree<int> t;

    t.insertBOT (10);
    t.insertBOT (20);
    t.insertBOT (30);
    t.insertBOT (40);
    t.insertBOT (2);
    t.insertBOT (3);
    t.insertBOT (1);

    std::cout << t.getElement("LL") << std::endl;
}

int main ()
{

  //testBuild ();
  //testTrace();
  //testBOT();



  //testCnt();
  //testSearchCount();
  //testHeight();
  //testCountLeaves();
  //testMaxLeaf();
    testGetElement();

    return 0;
}
