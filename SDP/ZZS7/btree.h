#ifndef __BTREE_H
#define __BTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <queue>
#include <stack>

template <class T>
struct TreeNode
{
  TreeNode (const T& data, TreeNode<T> *_left, TreeNode<T> *_right);
  TreeNode<T> *left, *right;
  T data;

  int getId ();

private:
  static int maxid;
  int id;
};


////////////////
//BFS Iterator
template <class T>
class BFSIterator
{
private:
  std::queue<TreeNode<T>*> q;


public:
  BFSIterator(TreeNode<T>* );
  TreeNode<T>* operator * ();
  void operator++ ();
  bool operator != (const BFSIterator& );
  bool operator == (const BFSIterator& );


};

//BFS Iterator 
///////////////
//Predikat Iterator
template <class T>
struct Item
{
  TreeNode<T>* node;
  bool (* pred) (TreeNode<T>* );
  Item();
  Item(TreeNode<T>* , bool (* ) (TreeNode<T>* ) );  

};

template <class T>
class PredIterator
{
private:
  std::stack<Item<T>> s;
  void windStack();

public:
  PredIterator(TreeNode<T>* , bool (* _pred) (TreeNode<T>* ));
  T operator * () const;
  void operator++ ();
  bool operator != (const PredIterator& ) const;
  bool operator == (const PredIterator& ) const;
  bool more() const;

};




//Predikat Iterator
/////////////////////

template <class T>
class BTree
{
public:
  BTree();
  BTree(const T, const BTree<T>&, const BTree<T>&);
  BTree (const BTree<T>&);
  //TODO: ГОЛЯМА ЧЕТВОРКА

  BTree<T>& operator = (const BTree<T>&);

  bool operator == (const BTree<T>&) const;

  friend std::ostream& operator << (std::ostream&,const BTree<T>&);

  bool insertElement (std::string, const T&);
  void insertBOT (const T&);

  bool member (const T& x) const;

  void read (std::istream&);

  std::vector<T> listLeaves() const;
  std::string findTrace (const T&) const;
  void prettyPrint() const;
  void parseExpression (const char* );
  double calculateExpressionTree () const;
  bool isBOT() const;
  void changeVertices();
  bool checkLevels() const;
  void balance();

  BFSIterator<T> begin();
  BFSIterator<T> end();

  PredIterator<T> start();

  class PredicateIterator
  {
    private:

    std::queue<TreeNode<T>*> q;
    bool (*pred) (T);

    public:
    PredicateIterator(TreeNode<T>*& startEl, bool (*_pred) (T)) : pred(_pred) {q.push(startEl);}

    void operator++();
    T operator*() const;
    bool more() const;

  };

  PredicateIterator beginPred(bool (*) (T));


  ~BTree ();

private:

  TreeNode<T> *root;
  bool insertElement (std::string, const T&, TreeNode<T>*&);
  void insertBOT (const T&, TreeNode<T>*&);
  void del (TreeNode<T>*);

  bool member (const T& x, const TreeNode<T> *) const;
  TreeNode<T>* readFromStream (std::istream &);

  TreeNode<T>* copyFrom (const TreeNode<T> *);

  bool compare (const TreeNode<T> *t1, const TreeNode<T> *t2) const;

  void listLeavesRec (TreeNode<T>*, std::vector<T>& ) const;
  void findTraceRec (TreeNode<T>*, std::string&, std::string& , const T&) const; //mnogo zle napisana funkciq :(
  void prettyPrintRec (TreeNode<T>* , int ) const;
  TreeNode<T>* parseExpressionHelper(const char* ); 
  double calculateExpressionTreeHelper (TreeNode<char>* ) const;
  bool isBOTHelper(TreeNode<T>* , TreeNode<T>* , TreeNode<T>* ) const;
  bool compareStart(TreeNode<T>* , TreeNode<T>* ) const;
  bool compareEnd(TreeNode<T>* , TreeNode<T>* ) const;
  int changeVerticesHelper(TreeNode<int>*& );
  void checkLevelsHelper(TreeNode<T>* , int , std::vector<std::vector<T>>& ) const;
  void putStrings(TreeNode<std::string>* , int , std::vector<std::string>& ) const;
  void balanceRec(TreeNode<std::string>*& , int , std::vector<std::string>& );

  bool (*predForIter) (T);
 
};
template <class T>
std::ostream& operator << (std::ostream&,const BTree<T>&);

#endif