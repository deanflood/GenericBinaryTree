#pragma once
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iomanip>   

/***************************************************************************************
*    Usage: Modified
*    Title: Binary Search Tree implementation using templates
*    Author: Ian McGrath
*    Date: Jul 5 '14
*    Availability: http://codereview.stackexchange.com/questions/56188/binary-search-tree-implementation-using-templates
***************************************************************/
template <class T>
class Tree
{
	struct Node
	{
		T data;
		Node * left;
		Node * right;

		Node(T val)
		{
			data = val;
			left = nullptr;
			right = nullptr;
		}
	};
public:
	Tree();
	void add(T);
	int height();
	void inorder();
private:
	Node * root;
	void add(Node *, Node *);
	int height(Node*);
	void inorder(Node *);
};

template<class T>
inline Tree<T>::Tree()
{
	root = nullptr;
}

template<class T>
inline void Tree<T>::add(T data)
{
	Node * toAdd = new Node(data);
	if (root == nullptr) {
		root = toAdd;
	}
	else {
		add(toAdd, root);
	}
}

template<class T>
inline int Tree<T>::height()
{
	return height(root);
}

template<class T>
inline void Tree<T>::inorder()
{
	inorder(root);
}

template<class T>
inline void Tree<T>::add(Node * toAdd, Node * addHere)
{
	if (toAdd->data < addHere->data) {
		if (addHere->left == nullptr) {
			addHere->left = toAdd;
		}
		else {
			add(toAdd, addHere->left);
		}
	}
	else if (toAdd->data > addHere->data) {
		if (addHere->right == nullptr) {
			addHere->right = toAdd;
		}
		else {
			add(toAdd, addHere->right);
		}
	}
}

template<class T>
inline int Tree<T>::height(Node * node)
{
	if (node == nullptr) {
		return -1;
	}
	else {
		return 1 + max(height(node->left), height(node->right));
	}
}

template<class T>
inline void Tree<T>::inorder(Node * node)
{
	if (node != nullptr) {
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
}

