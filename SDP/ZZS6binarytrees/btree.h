#ifndef __BTREE_H
#define __BTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <string>

using std::ostream;
using std::istream;

template <class T>
struct TreeNode
{
  TreeNode() 
  {
    left = nullptr;
    right = nullptr;
  }
  TreeNode (const T& data, TreeNode<T> *_left, TreeNode<T> *_right);
  TreeNode<T> *left, *right;
  T data;

  int getId ();

private:
  static int maxid;
  int id;
};

using Matrix = std::vector<std::vector<int>>;
/*struct Matrix //matrix for ZZS6 task
{
  int rows;
  int columns;
  int** mat;
  Matrix()
  {
    rows = 0;
    columns = 0;
    mat = nullptr;
  }
  Matrix(int _rows, int _columns) : rows(_rows), columns(_columns) 
  {
    mat = new *int[rows];
    for(int i = 0; i < rows; i++)
      mat[i] = new int[columns];
  }
  ~Matrix()
  {
    for(int i = 0; i < rows; i++)
      delete[] mat[i];
    delete[] mat;
  }
};*/

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
  void makeFromMatrix(Matrix);
  void printDOT(ostream&) const;

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
  void makeFromMatrixRec(TreeNode<Matrix>*&, Matrix);
  void printDOTHelper(TreeNode<Matrix>* , ostream&, int) const;

};
template <class T>
std::ostream& operator << (std::ostream&,const BTree<T>&);

#endif