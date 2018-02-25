#include "btree.h"
#include <iostream>
#include <cassert>


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
  root = new TreeNode<T> (data,lt.root,rt.root);

}

template <class T>
void printNodesLISP (std::ostream& out, TreeNode<T> *root)
{
  if (root == nullptr)
  {
    out << "()";
    return;
  }

  out << "(" << root->data << ",";
  printNodes (out, root->left);
  out << ",";
  printNodes (out, root->right);
  out << ")";
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
  out << "digraph G {" << std::endl;
  printNodesDotty (out, t.root);
  out << "}" << std::endl;
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
    trace.erase (0);
    return insertElement (trace,x,crr->left);
  }
  if (trace[0] == 'R')
  {
    trace.erase (0);
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
int BTree<T>::cntRec(TreeNode<T>* curr) const
{

    if(curr == NULL)
        return 0;
    return 1 + cntRec(curr->left) + cntRec(curr->right);

}

template <class T>
int BTree<T>::cnt() const
{

    return cntRec(root);

}

template <class T>
int BTree<T>::searchCountRec(bool (*pred) (const T&), TreeNode<T>* curr) const
{

    if(curr == NULL)
        return 0;
    int br = pred(curr->data) ? 1 : 0;
    return br + searchCountRec(pred, curr->left) + searchCountRec(pred, curr->right);

}

template <class T>
int BTree<T>::searchCount(bool (*pred) (const T&)) const
{

    return searchCountRec(pred, root);

}

template <class T>
int BTree<T>::heightRec(TreeNode<T>* curr) const
{

    if(curr == NULL)
        return 0;
    if(heightRec(curr->left) >= heightRec(curr->right))
        return 1 + heightRec(curr->left);
    else
        return 1 + heightRec(curr->right);

}

template <class T>
int BTree<T>::height() const
{
    return heightRec(root);
}

template <class T>
int BTree<T>::countLeavesRec(TreeNode<T>* curr) const
{
    if(curr == NULL)
        return 0;
    if(curr->left == NULL && curr->right == NULL)
        return 1;
    return countLeavesRec(curr->left) + countLeavesRec(curr->right);
}

template <class T>
int BTree<T>::countLeaves() const
{
    return countLeavesRec(root);
}

template <class T>
T BTree<T>::maxLeafRec(TreeNode<T>* curr) const
{


    if(curr->left == NULL && curr->right == NULL)
        return curr->data;
    if(curr->left == NULL || curr->right == NULL)
    {
        if(curr->left == NULL)
            return maxLeafRec(curr->right);
        if(curr->right == NULL)
            return maxLeafRec(curr->left);
    }
    if(maxLeafRec(curr->left) >= maxLeafRec(curr->right))
        return maxLeafRec(curr->left);
    else
        return maxLeafRec(curr->right);
}

template <class T>
T BTree<T>::maxLeaf() const
{

    return maxLeafRec(root);

}

template <class T>
T& BTree<T>::getElementRec(const char* s, TreeNode<T>* curr)
{
    //vrushta global, kogato nqma suotveten element


    if(curr == NULL)
        return global;
    if(*s == 0)
        return root->data;
    if(*(s+1) == 0)
    {
        if(*s == 'L')
            return (curr->left != NULL) ? curr->left->data : global;
        if(*s == 'R')
            return (curr->right != NULL) ? curr->right->data : global;
    }

    if(*s == 'L')
        return getElementRec(s + 1, curr->left);
    if(*s == 'R')
        return getElementRec(s + 1, curr->right);

}

template <class T>
T& BTree<T>::getElement(const char* s)
{
    return getElementRec(s, root);
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
