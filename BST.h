#include <iostream>
#include "TreeNode.h"
#ifndef BST_H
#define BST_H
using namespace std;
template <class T> class BST
{
public:
	BST();
	virtual ~BST();
	void insert(T value);
	bool contains(T value); // search
	bool deleteNode(T value);
	TreeNode<T>* getSuccessor(TreeNode<T>* d);
	bool deleteR(T k); //deletes recursively
	T* search(T key);
	TreeNode<T>* getMin();
	TreeNode<T>* getMax();
	bool isEmpty();
	void printTree();
	void recPrint(TreeNode<T>* node);
private:
	TreeNode<T>* root;
};

template <class T> BST<T>::BST()
{
	root = NULL; //empty true
}

template <class T> BST<T>::~BST()
{
	//iterate and delete
	//research
	while (root != NULL)
	{
		deleteR(root->key);
	}
}

template <class T> void BST<T>::printTree()
{
	recPrint(root);
}

template <class T> void BST<T>::recPrint(TreeNode<T>* node)
{
	if(node == NULL)
		return;
	recPrint(node->left);
	cout << node->key << endl;
	recPrint(node->right);
}

template <class T> bool BST<T>::isEmpty()
{
	return(root == NULL);
}

template <class T> void BST<T>::insert(T value)
{
	//check if value exist, if not continue (implement this)
	if(contains(value) == false)
	{
		TreeNode<T>* node = new TreeNode<T>(value);

		if(isEmpty()) //empty tree
		{
			root = node;
		}
		else //non empty
		{
			TreeNode<T>* current = root;
			TreeNode<T>* parent;

			while(true) //look for insertion point
			{
				parent = current;
				if(value < current->key) //go left
				{
					current = current->left;
					if(current == NULL) //found location
					{
						parent->left = node;
						break;
					}
				}
				else
				{
					current = current->right;
					if(current == NULL) //found location
					{
						parent->right = node;
						break;
					}
				}
			}
		}
	}
	else
		cout << "Error. Value already in tree." << endl;
}

template <class T> bool BST<T>::contains(T value)
{
	if(isEmpty()) //empty tree, nothing exists
		return false;

	TreeNode<T>* current = root;
	while(current->key != value)
	{
		if(value < current->key)
			current = current->left;
		else
			current = current->right;
		if(current == NULL) //item not in tree
			return false;
	}
	return true;
}

template <class T> TreeNode<T>* BST<T>::getMax()
{
	TreeNode<T>* current = root;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

template <class T> TreeNode<T>* BST<T>::getMin()
{
	TreeNode<T>* current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

template <class T> bool BST<T>::deleteR(T k)
{
	if(isEmpty())
		return false;
	//check if key/value exists in the tree

	TreeNode<T>* current = root;
	TreeNode<T>* parent = root;
	bool isLeft = true;
	//iterate and update pointers
	while(current->key != k)
	{
		parent = current;
		if(k < current->key)
		{
			isLeft = true;
			current = current->left;
		}
		else
		{
			isLeft = false;
			current = current->right;
		}
		if(current == NULL)
			return false;
	}
	//found the node to be deleted
	if(current->left == NULL && current->right == NULL) //case of leaf node
	{
		if(current == root)
			root = NULL;
		else if(isLeft) //i think we need deletion here
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	//need to check if node to be deleted has one child
	else if(current->right == NULL) //no right child
	{
		if(current == root)
			root = current->left;
		else if(isLeft)
		{
			parent->left = current->left;
		}
		else
		{
			parent->right = current->left;
		}
	}
	else if(current->left == NULL) //no left child
	{
		if(current == root)
			root = current->right;
		else if(isLeft)
		{
			parent->left = current->right;
		}
		else
		{
			parent->right = current->right;
		}
	}
	else //node to be deleted has two children
	{
		//find successor of the node to be deleted(current)
		TreeNode<T>* successor = getSuccessor(current);
		if(current == root)
			root = successor;
		else if(isLeft)
			parent->left = successor;
		else
			parent->right = successor;
		successor-> left = current->left;
	}
	return true;
}

template <class T> TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) //d is the node to be deleted
{
	TreeNode<T>* sp = d; //successors parent
	TreeNode<T>* successor = d;
	TreeNode<T>* current = d->right;
	while(current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}
	//need to check if successor is a descend
	if(successor != d->right)
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}

template <class T> T* BST<T>::search(T key)
{
	TreeNode<T> *current = root;
	while(current->key != key)
	{
		if (key < current->key)
			current = current->left;
		else
			current = current->right;
	}
	return &current->key;
}
#endif
