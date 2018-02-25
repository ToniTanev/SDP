#include <iostream>
#include <fstream>

#include "btree.cpp"


void testSerialize ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);


  std::ofstream f ("tree.txt");

  f << t7;

  f.close ();

  BTree<int> newTree;
  std::ifstream fin ("tree.txt");

  newTree.read (fin);

  //assert (t7==newTree);

  std::cout << std::endl << newTree;
}

void testBuild ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);


  t7.insertElement ("RR",100);
  std::cout << t7;

}

void testTrace ()
{
  BTree<int> t;

  t.insertElement ("",10);
  t.insertElement ("L",20);

  std::cout << t;
}

void testBOT ()
{
  BTree<int> t;

  t.insertBOT (10);
  t.insertBOT (20);
  t.insertBOT (5);

  std::cout << t;

  assert (t.member (5));
  assert (!t.member (6));

}

void testMemory ()
{
  BTree<int> empty;
  BTree<int> t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,empty,empty),
             t5  (5,t50, empty),
             t7  (7,t30,t5);

  BTree<int> *tmp = new BTree<int> (t7);

  assert (tmp->member (90));
  assert (tmp->member (7));
  assert (*tmp == t7);

  delete tmp;
  assert (t7.member (90));
  assert (t7.member (7));

  t90 = t7;
  assert (t90 == t7);
  t7 = t7;
  assert (t90 == t7);
  assert (t7 == t7);

}

void testListLeaves()
{

  BTree<int> empty;
  BTree<int> t40(40, empty, empty),
             t69(69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,t40,t69),
             t5  (5,t50, empty),
             t7  (7,t30,t5);
  BTree<int> t;
  t = t7;

  std::vector<int> leaves;
  leaves = t.listLeaves();

  for(int i = 0; i < leaves.size(); i++)
    std::cout << leaves[i] << std::endl;

}

void testFindTrace()
{

  BTree<int> empty;
  BTree<int> t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,empty,t12),
             t50 (50,t40,t69),
             t5  (5,t50, empty),
             t7  (7,t30,t5);

  std::string trace = "";
  trace = t7.findTrace(40);

  std::cout << trace << std::endl;
}

void testPrettyPrint ()
{
  BTree<int> empty;
  BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);


  t7.prettyPrint();

}

void testParseExpression ()
{

  BTree<char> tree;
  tree.parseExpression ("((9*4)+((2/(5+3))+(2*5)))");
  tree.prettyPrint();

}

void testCalcExpr ()
{

  BTree<char> tree;
  tree.parseExpression ("((9*4)+((2/(5+3))+(2*5)))");
  std::cout << tree.calculateExpressionTree () << std::endl;

}

void testIsBOT()
{

  BTree<int> empty;
  BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);

  // t7.prettyPrint();

   BTree<int> t;

   t.insertBOT (10);
   t.insertBOT (20);
   t.insertBOT (5);
   t.insertBOT(36);
   t.insertBOT(72);
   t.insertBOT(52);

   t.prettyPrint();

   std::cout << t.isBOT() << std::endl;

}

void testChangeVertices()
{
    BTree<int> empty;
    BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);

    t7.prettyPrint();

    t7.changeVertices();

    t7.prettyPrint();
}

void testCheckLevels()
{

  BTree<int> t;

   t.insertBOT (10);
   t.insertBOT (20);
   t.insertBOT (5);
   t.insertBOT(36);
   t.insertBOT(72);
   t.insertBOT(52);

   BTree<int> empty;
   BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);

  t.prettyPrint();

  std::cout << t.checkLevels() << std::endl;
}

void testAreSetsEq()
{

  std::vector<int> A;
  std::vector<int> B;
  A.push_back(5);
  A.push_back(1);
  A.push_back(2);
  A.push_back(3);

  B.push_back(21);
  B.push_back(1);
  B.push_back(2);
  B.push_back(23);
  B.push_back(5);
  B.push_back(3);


  std::cout << areSetsEqual(A, B) << std::endl;

}

void testBalance()
{
  BTree<std::string> empty;
  BTree<std::string> t4("samo", empty, empty),
                     t5("az si znam kakvo", empty, empty),
                     t6("mi", empty, empty),
                     t7("e", empty, empty),
                     t2("kogato znam kakvo ", t4, t5),
                     t3("mi e", t6, t7),
                     t1("az", t2, t3);
                     
                     

  t1.prettyPrint();
  t1.balance();
  std::cout << std::endl << std::endl;
  t1.prettyPrint();

}

void testBFSIterator()
{
  BTree<int> empty;
  BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);

 // std::cout << "b4" << std::endl;


  BFSIterator<int> iter = t7.begin();

  //std::cout << "after decl" << std::endl;
  while (iter != t7.end())
  {
   // std::cout << "in while" << std::endl;
    std::cout << (*iter)->data << " ";
  //  std::cout << "in while 2" << std::endl;
    ++iter;
  }

  std::cout << std::endl;



}

void testPredIterator()
{
  BTree<int> empty;
  BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);

  PredIterator<int> iter = t7.start();
  while (iter.more())
  {
   // std::cout << "in while" << std::endl;
    std::cout << *iter << " ";
    //std::cout << "in while 2" << std::endl;
    ++iter;
  }

  std::cout << std::endl;

  t7.prettyPrint();
std::cout << std::endl;  

}

void testPredicateIterator()
{
  BTree<int> empty;
  BTree<int> t360(360, empty, empty),
             t420(420, empty, empty),
             t40 (40, empty, empty),
             t69 (69, empty, empty),
             t90 (90,empty,empty),
             t12 (12,t90,empty),
             t30 (30,t360,t12),
             t50 (50,t40,t69),
             t5  (5,t50, t420),
             t7  (7,t30,t5);


  BTree<int>::PredicateIterator iter = t7.beginPred(isOdd);

  while(iter.more())
  {
    std::cout << *iter << ' ';
    ++iter;
  }

  std::cout << std::endl;
}

int main ()
{

  //testBuild ();
  //testTrace();
  //testBOT();
  //testMemory();

  //testSerialize ();

  //testListLeaves();
  //testFindTrace();
  //testPrettyPrint ();
  //testParseExpression ();
  //testCalcExpr ();
  //testIsBOT();
  //testChangeVertices();
  //testCheckLevels();
  //testAreSetsEq();
  //testBalance();
  //testBFSIterator();
  //testPredIterator();

  testPredicateIterator();


}