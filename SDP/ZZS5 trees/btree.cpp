#include "btree.h"
#include <iostream>
#include <cassert>
#include <iomanip>

template <class T>
TreeNode<T>::TreeNode (const T& _data,
                       TreeNode<T> *_left,
                       TreeNode<T> *_right):data(_data),
                                            left(_left),
                                            right(_right)
{
  id = maxid;
  maxid++;
}

template <class T>
int TreeNode<T>::getId ()
{
  return id;
}

template <class T>
int TreeNode<T>::maxid = 0;


template <class T>
BTree<T>::BTree():root(nullptr)
{

}

template <class T>
BTree<T>::BTree(const T data, const BTree<T> &lt, const BTree<T> &rt)
{
  //TODO: НЕ ТАКА!!!
  root = new TreeNode<T> (data,copyFrom(lt.root),copyFrom(rt.root));

}

template <class T>
void printNodesLISP (std::ostream& out, TreeNode<T> *root)
{
  if (root == nullptr)
  {
    out << "()";
    return;
  }

  out << "( " << root->data << " ";
  printNodesLISP (out, root->left);
  out << " ";
  printNodesLISP (out, root->right);
  out << " )";
}

template <class T>
void printNodesDotty (std::ostream& out, TreeNode<T> *root)
{
  if (root == nullptr)
  {
    return;
  }

  out << root->getId()
      << "[label=\""
      << root->data
      << "\"];"
      << std::endl;

  if (root->left != nullptr)
  {
    out << root->getId()
        << "->"
        << root->left->getId()
        << "[color = \"red\"]"
        << ";"
        << std::endl;
  }

  if (root->right != nullptr)
  {
    out << root->getId()
        << "->"
        << root->right->getId()
        << ";"
        << std::endl;
  }
  printNodesDotty (out, root->left);
  printNodesDotty (out, root->right);
}



std::ostream& operator << (std::ostream &out,const BTree<int> &t)
{
/*  out << "digraph G {" << std::endl;
  printNodesDotty (out, t.root);
  out << "}" << std::endl;*/

  printNodesLISP (out,t.root);

  return out;
}

template <class T>
bool BTree<T>::insertElement (std::string trace, const T& x, TreeNode<T> *&crr)
{
  if (trace == "" && crr == nullptr)
  {
    crr = new TreeNode<T> (x,nullptr,nullptr);
    return true;
  }
  if (trace != "" && crr == nullptr)
  {
    return false;
  }
  //=> trace != "" && current != nullptr
  if (trace[0] == 'L')
  {
    trace.erase (trace.begin());
    return insertElement (trace,x,crr->left);
  }
  if (trace[0] == 'R')
  {
    trace.erase (trace.begin());
    return insertElement (trace,x,crr->right);
  }
  return false;
}


template <class T>
bool BTree<T>::insertElement (std::string trace, const T& x)
{
  return insertElement (trace, x, root);
}

template <class T>
void BTree<T>::insertBOT (const T &x, TreeNode<T> *&crr)
{
  if (crr == nullptr)
  {
    crr = new TreeNode<T> (x,nullptr,nullptr);
    return;
  }

  if (x <= crr->data){
    insertBOT (x,crr->left);
    return;
  }

  insertBOT (x,crr->right);


}

template <class T>
void BTree<T>::insertBOT (const T& x)
{
  insertBOT (x, root);
}

template <class T>
bool BTree<T>::member (const T& y) const
{
  return member (y, root);
}


template <class T>
bool BTree<T>::member (const T& y, const TreeNode<T> *crr) const
{
  if (crr == nullptr)
  {
      return false;
  }

  return crr->data == y ||
         member (y,crr->left) ||
         member (y,crr->right);
}


template <class T>
void BTree<T>::read (std::istream &in)
{
  //приемаме, че дървото е празно
  root = readFromStream (in);
}


template <class T>
TreeNode<T>* BTree<T>::readFromStream (std::istream &in)
{ //()..............
  //( 7 ( 30 () ( 12 ( 90 () () ) () ) ) ( 5 ( 50 () () ) () ) )

  char nextChar;
  nextChar = in.get();
  assert (nextChar == '(');

  nextChar = in.get();
  assert (nextChar == ' ' || nextChar == ')');

  if (nextChar == ')')
  {
    return nullptr;
  }
  //уверени сме, че в потока следват следните неща:
  //1. СТОЙНОСТ НА КОРЕНА. ПРИЕМАМЕ, ЧЕ ОПЕРАТОР >>T КОРЕКТНО ЩЕ Я ИЗЧЕТЕ

  T rootValue;
  in >> rootValue;

  //2. интервал

  nextChar = in.get();
  assert (nextChar == ' ');

  //3. ЛЯВО ПОДДЪРВО

  TreeNode<T> *leftSubTree;
  leftSubTree = readFromStream (in);

  //4. интервал

  nextChar = in.get();
  assert (nextChar == ' ');

  //5. ДЯСНО ПОДДЪРВО

  TreeNode<T> *rightSubTree;
  rightSubTree = readFromStream (in);

  //6. интервал

  nextChar = in.get();
  assert (nextChar == ' ');

  //7. затваряща скоба

  nextChar = in.get();
  assert (nextChar == ')');

  return new TreeNode<T> (rootValue,leftSubTree,rightSubTree);

}


template <class T>
void BTree<T>::del (TreeNode<T> *crr)
{
  if (crr == nullptr)
  {
    return;
  }

  del (crr->left);
  del (crr->right);
  delete crr;
}


template <class T>
BTree<T>::~BTree ()
{
  del (root);
}

template <class T>
TreeNode<T>* BTree<T>::copyFrom (const TreeNode<T> *crr)
{
  if (crr == nullptr)
  {
    return nullptr;
  }

  return new TreeNode<T> (crr->data,
                          copyFrom (crr->left),
                          copyFrom (crr->right));
}


template <class T>
BTree<T>::BTree (const BTree<T> &other)
{
  root = copyFrom (other.root);
}

template <class T>
BTree<T>& BTree<T>::operator = (const BTree<T> &other)
{
  if (this != &other)
  {
      del (root);
      root = copyFrom (other.root);
  }
  return *this;
}

template <class T>
bool BTree<T>::operator == (const BTree<T> &other) const
{
  return compare (root, other.root);
}

template <class T>
bool BTree<T>::compare (const TreeNode<T> *t1, const TreeNode<T> *t2) const
{
  if (t1 == nullptr)
    return t2 == nullptr;

  if (t2 == nullptr)
    return t1 == nullptr;

  return t1->data == t2->data &&
         compare (t1->left,t2->left) &&
         compare (t1->right, t2->right);
}


template <class T>
void BTree<T>::listLeavesRec(TreeNode<T>* curr, std::vector<T>& res) const
{

  if(curr == NULL) 
    return;
  if(curr->right == NULL && curr->left == NULL)
  {
    res.push_back(curr->data);
    return;
  }
  listLeavesRec(curr->left, res);
  listLeavesRec(curr->right, res);

}

template <class T>
std::vector<T> BTree<T>::listLeaves() const
{

  std::vector<T> vec;
  listLeavesRec(root, vec);
  return vec;

}


template <class T>
void BTree<T>::findTraceRec(TreeNode<T>* curr, std::string& trace, std::string& res, const T& x) const 
{

  if (curr == NULL)
    return;

  if (curr->data == x)
  {

    res = trace;
    return;
  }

  trace.push_back('L');
  findTraceRec(curr->left, trace, res, x);
  trace.pop_back();

  trace.push_back('R');
  findTraceRec(curr->right, trace, res, x);
  trace.pop_back();

}

template <class T>
std::string BTree<T>::findTrace (const T& x) const
{

  std::string trace, temp;
  findTraceRec(root, temp, trace, x);
  return trace;
}

template <class T>
void BTree<T>::prettyPrintRec (TreeNode<T>* curr, int numbOfSpaces) const
{
  if (curr == NULL)
    return;

  if (curr->left == NULL && curr->right == NULL)
  {
    for(int i = 0; i < numbOfSpaces; i++)
      std::cout << ' ';
    std::cout << curr->data << std::endl;
    return;
  }


  prettyPrintRec (curr->right, numbOfSpaces + 5);

  for(int i = 0; i < numbOfSpaces; i++)
    std::cout << ' ';
  std::cout << curr->data << std::endl;
  prettyPrintRec (curr->left, numbOfSpaces + 5);


}



template <class T>
void BTree<T>::prettyPrint () const
{

  prettyPrintRec(root, 0);

}

bool isOperator (char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isDigit (char c)
{
  return c >= '0' && c <= '9';
}

template <class T>
TreeNode<T>* BTree<T>::parseExpressionHelper (const char* s)
{

  if (isDigit (*s))
    return new TreeNode<T> (*s, NULL, NULL);

  char leftExpr[300];
  char rightExpr[300];
  int leftBrackets = 0, rightBrackets = 0, i = 0; 

  if (isDigit (*(s + 1)))
  {
    i = 2; //purviqt simvol e '(', vtoriqt e digit, tretiqt e turseniqt operator razdelitel
    leftExpr[0] = *(s+1);
  }
  else
  {
    leftBrackets = 1;
    i = 2; //zapochva ot vtoriq simvol, tui kato nuleviqt i purviqt se podrazbira che sa '('

    while (rightBrackets < leftBrackets)
    {
      if (s[i] == '(')
        leftBrackets++;
      if (s[i] == ')')
        rightBrackets++;
      i++;
    }

    for (int k = 1; k < i; k++)
      leftExpr[k - 1] = s[k];
    leftExpr[i] = 0;
  }
  //sled if elsa na i-ta poziciq se namira operatora razdelitel
  int operatorPos = i;

  for (i = operatorPos + 1; s[i] != 0; i++)
    rightExpr[i - operatorPos - 1] = s[i];
  //na poslednata poziciq na rightExpr se namira poslednata zatvarqshta skoba, no tq ne trqbva da e chast ot rightExpr, zatova na neino mqsto slagame zavurshvashtata 0
  rightExpr[i - operatorPos - 2] = 0; //poslednata poziciq e s edno nazad, tui kato i se e uvelichilo s 1 za poslednata iteraciq
  //sega v leftExpr imame nujniq izraz i v rightExpr imame nujniq izraz, a v s[operatorPos] se namira nujniqt operator

  return new TreeNode<T> (s[operatorPos], parseExpressionHelper(leftExpr), parseExpressionHelper(rightExpr));

}

template <class T>
void BTree<T>::parseExpression(const char* s)
{
  root = parseExpressionHelper(s);
}

template <>
double BTree<char>::calculateExpressionTreeHelper (TreeNode<char>* curr) const
{

  if (isDigit (curr->data))
    return curr->data - '0';

  switch (curr->data)
  {

    case '+' : {return calculateExpressionTreeHelper (curr->left) + calculateExpressionTreeHelper (curr->right); break;}
    case '-' : {return calculateExpressionTreeHelper (curr->left) - calculateExpressionTreeHelper (curr->right); break;}
    case '*' : {return calculateExpressionTreeHelper (curr->left)*calculateExpressionTreeHelper (curr->right); break;}
    case '/' : {return calculateExpressionTreeHelper (curr->left)/calculateExpressionTreeHelper (curr->right); break;}
  }

}

template <>
double BTree<char>::calculateExpressionTree () const
{

  return calculateExpressionTreeHelper(root);
}
/*
template <class T>
bool BTree<T>::insertElement (std::string trace, const T& x)
{
  if (trace == "")
  {
    assert (root == nullptr);
    root = new TreeNode<T> (x,nullptr,nullptr);
    return true;
  }
  TreeNode<T> *crr = root;
  int letter = 0;
  assert (root != nullptr);
  for (letter = 0; letter < trace.size()-1; letter++)
  {
    assert (trace[letter] == 'L' || trace[letter] == 'R');
    if (trace[letter] == 'L')
    {
      crr = crr->left;
    } else if (trace[letter] == 'R')
    {
      crr = crr->right;
    }
    assert (crr != nullptr);
  }
  assert (trace[letter] == 'L' || trace[letter] == 'R');
  //crr сочи родителя на "дупката"
  if (trace[letter] == 'L')
  {
    assert (crr->left == nullptr);
    crr->left = new TreeNode<T> (x,nullptr,nullptr);
    return true;
  }
  if (trace[letter] == 'R')
  {
    assert (crr->right == nullptr);
    crr->right = new TreeNode<T> (x,nullptr,nullptr);
    return true;
  }
  return false;
}*/