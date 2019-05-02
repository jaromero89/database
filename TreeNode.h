#include <iostream>
using namespace std;
//Used treenode designed in class and some of the code in our Data structures textbook
template <class T>
class BST;

template <class T>
class TreeNode {
public:
  TreeNode();
  TreeNode(T key);
  virtual ~TreeNode();

  T key;

  TreeNode *left;
  TreeNode *right;

private:
  friend class BST<T>;
  friend class Database;
};

template <class T>
TreeNode<T>::TreeNode ()
{
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode (T k)
{
  left = NULL;
  right = NULL;
  key = k;
}

template <class T>
TreeNode<T>::~TreeNode()
{
  delete left;
	delete right;
}
