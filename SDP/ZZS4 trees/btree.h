#ifndef __BTREE_H
#define __BTREE_H

#include <iostream>
#include <string>

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


template <class T>
class BTree
{
public:
  BTree();
  BTree(const T, const BTree<T>&, const BTree<T>&);
  //TODO: √ŒÀﬂÃ¿ ◊≈“¬Œ– ¿

  friend std::ostream& operator << (std::ostream&,const BTree<T>&);

  bool insertElement (std::string, const T&);
  void insertBOT (const T&);
  int cnt() const;
  int searchCount(bool (*pred) (const T&)) const;
  int height() const;
  int countLeaves() const;
  T maxLeaf() const;
  T& getElement(const char* ) ;

private:
  T global;

  TreeNode<T> *root;
  bool insertElement (std::string, const T&, TreeNode<T>*&);
  void insertBOT (const T&, TreeNode<T>*&);
  int cntRec(TreeNode<T>* ) const;
  int searchCountRec(bool (*pred) (const T&), TreeNode<T>* ) const;
  int heightRec(TreeNode<T>* ) const;
  int countLeavesRec(TreeNode<T>* ) const;
  T maxLeafRec(TreeNode<T>* ) const;
  T& getElementRec(const char*, TreeNode<T>*) ;

};

template <class T>
std::ostream& operator << (std::ostream&,const BTree<T>&);

#endif
