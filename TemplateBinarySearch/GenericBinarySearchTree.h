#pragma once
#include <algorithm>
#include <iomanip>
template <class T>
class TreeNode {
	template <class T>
	friend class GenericBinarySearchTree;
	T data;
	TreeNode * left;
	TreeNode * right;
	TreeNode(T val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

template <class T>
class GenericBinarySearchTree
{	
public:
	GenericBinarySearchTree();
	~GenericBinarySearchTree();
	void add(T);
	void inorder();
	void preorder();
	void postorder();
	bool find(T);
	int height();
	void printTree();
	T findMin();
	T findMax();
	void deleteNode(T);

private:
	bool find(TreeNode<T>*, T);
	TreeNode<T> *root;
	void add(TreeNode<T> *, TreeNode<T> *);
	void inorder(TreeNode<T> *);
	void preorder(TreeNode<T> *);
	void postorder(TreeNode<T> *);
	void destroy(TreeNode<T> *);
	int height(TreeNode<T> *);
	void printTree(TreeNode<T> *, int);
	TreeNode<T> * findMin(TreeNode<T> *);
	TreeNode<T> * findMax(TreeNode<T> *);
	TreeNode<T> * deleteNode(T, TreeNode<T> *);

};

template<class T>
inline GenericBinarySearchTree<T>::GenericBinarySearchTree()
{
	root = nullptr;
}

template<class T>
inline GenericBinarySearchTree<T>::~GenericBinarySearchTree()
{
	destroy(root);
}

template<class T>
inline void GenericBinarySearchTree<T>::add(T data)
{
	TreeNode<T> * toAdd = new TreeNode<T>(data);
	if (root == nullptr) {
		root = toAdd;
	}
	else {
		add(toAdd, root);
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::inorder()
{
	inorder(root);
}

template<class T>
inline void GenericBinarySearchTree<T>::preorder()
{
	preorder(root);
}

template<class T>
inline void GenericBinarySearchTree<T>::postorder()
{
	postorder(root);
}

template<class T>
inline bool GenericBinarySearchTree<T>::find(T data)
{
	return find(root, data);
}

template<class T>
inline int GenericBinarySearchTree<T>::height()
{
	return height(root);
}

template<class T>
inline void GenericBinarySearchTree<T>::printTree()
{
	printTree(root, 0);
}

template<class T>
inline T GenericBinarySearchTree<T>::findMin()
{
	return findMin(root)->data;
}

template<class T>
inline T GenericBinarySearchTree<T>::findMax()
{
	return findMax(root)->data;
}

template<class T>
inline void GenericBinarySearchTree<T>::deleteNode(T dataIn)
{
	deleteNode(dataIn, root);
}

template<class T>
inline bool GenericBinarySearchTree<T>::find(TreeNode<T>* node, T data)
{
	if (node != nullptr) {
		if (data == node->data) {
			return true;
		}
		else if (data < node->data) {
			return find(node->left, data);
		}
		else {
			return find(node->right, data);
		}
	}
	else {
		return false;
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::add(TreeNode<T>* toAdd, TreeNode<T>* addHere)
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
inline void GenericBinarySearchTree<T>::inorder(TreeNode<T>* node)
{
	if (node != nullptr) {
		inorder(node->left);
		cout << node->data;
		inorder(node->right);
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::preorder(TreeNode<T>* node)
{ 
	if (node != nullptr) {
		cout << node->data;
		preorder(node->left);
		preorder(node->right);
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::postorder(TreeNode<T>* node)
{
	if (node != nullptr) {
		preorder(node->left);
		preorder(node->right);
		cout << node->data;
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::destroy(TreeNode<T>* node)
{
	if (node != nullptr) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

template<class T>
inline int GenericBinarySearchTree<T>::height(TreeNode<T>* node)
{
	if (node == nullptr) {
		return -1;
	}
	else {
		return 1 + std::max(height(node->left), height(node->right));
	}
	
}

template<class T>
inline void GenericBinarySearchTree<T>::printTree(TreeNode<T>* node, int  indent = 0 )
{
	if (node != nullptr) {
		if (node->right) {
			printTree(node->right, indent + 4);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (node->right) cout << " /\n" << setw(indent) << ' ';
		cout << node->data << "\n ";
		if (node->left) {
			cout << setw(indent) << ' ' << " \\\n";
			printTree(node->left, indent + 4);
		}
	}
}

template<class T>
inline TreeNode<T> * GenericBinarySearchTree<T>::findMin(TreeNode<T>* node)
{
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

template<class T>
inline TreeNode<T> * GenericBinarySearchTree<T>::findMax(TreeNode<T>* node)
{
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

template<class T>
inline TreeNode<T> * GenericBinarySearchTree<T>::deleteNode(T dataIn, TreeNode<T>* node)
{
	if (node != nullptr) {
		if (dataIn < node->data) {
			node->left = deleteNode(dataIn, node->left);
		}
		else if (dataIn > node->data) {
			node->right = deleteNode(dataIn, node->right);
		}
		else {
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->left == nullptr) {
				TreeNode<T>* temp = node;
				node = node->right;
				delete temp;
			}
			else if (node->right == nullptr) {
				TreeNode<T>* temp = node;
				node = node->left;
				delete temp;
			}
			else {
				TreeNode<T>* temp = findMin(node->right);
				node->data = temp->data;
				node->right = deleteNode(temp->data, node->right);
			}
		}
	}
	return node;
}
